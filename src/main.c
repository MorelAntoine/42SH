/*
** main.c for 42sh in Documents/annee_1/semestre_2/unix/PSU_2015_42sh/src
**
** Made by Antoine MOREL
** Login   <morel_j@epitech.net>
**
** Started on  Thu May 19 10:36:21 2016 Antoine MOREL
** Last update Sun Jun 05 22:17:22 2016 Baptiste Mairesse
*/

#include	<sys/stat.h>
#include	<stdlib.h>
#include	<unistd.h>
#include 	<signal.h>
#include	"shell.h"
#include	"system.h"
#include	"get_next_line.h"
#include	"library.h"

pid_t		g_cur_child_pid = -1;
bool		g_is_sigint = FALSE;

void		sig_suspend(int sig)
{
  (void)sig;
  g_is_sigint = TRUE;
  write(1, "\n", 1);
  if (g_cur_child_pid != -1)
    {
      kill(g_cur_child_pid, SIGSTOP);
      tcsetpgrp(STDOUT_FILENO, getpid());
      tcsetpgrp(STDIN_FILENO, getpid());
    }
  signal(SIGTSTP, &sig_suspend);
}

void		sig_handler(int sig)
{
  (void)sig;
  g_is_sigint = TRUE;
  if (g_cur_child_pid != -1)
    {
      kill(g_cur_child_pid, SIGQUIT);
    }
  signal(SIGINT, sig_handler);
  signal(SIGCHLD, SIG_IGN);
  write(1, "\n", 1);
}

char		is_tty(t_shell *shell)
{
  struct stat	stat;
  char		*str;
  int		ret;

  fstat(0, &stat);
  ret = (S_ISCHR(stat.st_mode) ? 1 : 0);
  if (ret == 0)
    {
      while ((str = get_next_line(0)) != NULL)
	{
	  core_shell(shell, str);
	  free(str);
	}
    }
  else
    return (FALSE);
  return (TRUE);
}

void		manage_sig(void)
{
  signal(SIGSTOP, SIG_IGN);
  signal(SIGTTOU, SIG_IGN);
  signal(SIGTTIN, SIG_IGN);
  signal(SIGTSTP, sig_suspend);
  signal(SIGINT, sig_handler);
  signal(SIGQUIT, SIG_IGN);
}

int		main(int argc, char **argv, char **env)
{
  t_shell	*shell;
  unsigned char	exit_status;

  (void)argc;
  (void)argv;
  manage_sig();
  if ((shell = init_shell(env)) == NULL)
    {
      put_error("impossible to malloc\n");
      return (1);
    }
  if (is_tty(shell) == TRUE)
    {
      exit_status = shell->exit_status;
      clean_shell(shell);
      return (exit_status);
    }
  mainloop(shell);
  exit_status = shell->exit_status;
  clean_shell(shell);
  return (exit_status);
}
