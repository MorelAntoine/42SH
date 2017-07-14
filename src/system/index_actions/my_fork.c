/*
** my_fork.c for 42sh in Documents/annee_1/semestre_2/unix/PSU_2015_42sh/src/system/index_actions
**
** Made by Antoine MOREL
** Login   <morel_j@epitech.net>
**
** Started on  Tue May 24 17:32:13 2016 Antoine MOREL
** Last update Sat Jun  4 17:03:54 2016 Dylan Deu
*/

#define		_GNU_SOURCE
#include	<stdlib.h>
#include	<unistd.h>
#include	<sys/types.h>
#include	<sys/wait.h>
#include	"actions.h"
#include	"cd.h"
#include	"bool.h"
#include	"library.h"

pid_t		g_cur_child_pid;

static bool	my_fork_no_builtins(t_list *list, t_shell *shell, int status)
{
  if ((g_cur_child_pid = fork()) == 0)
    {
      if (my_strcmp(list->cmd[0], "nano") == 0)
	setsid();
      mysh_actions(list, shell);
      return (FALSE_CHILD);
    }
  waitpid(g_cur_child_pid, &status, WCONTINUED | WUNTRACED);
  msg_status(status, shell, list);
  shell->exit_status = (status == 8) ? 136 : shell->exit_status;
  shell->exit_status = (status == 11) ? 139 : shell->exit_status;
  status = (status == 0 ? TRUE : FALSE);
  g_cur_child_pid = -1;
  return (status);
}

bool		my_fork(t_list *list, t_shell *shell, int status)
{
  shell->exit_status = 0;
  if (my_strcmp(list->cmd[0], "exit") == 0)
    status = my_exit(list->cmd, shell);
  else if (my_strcmp(list->cmd[0], "env") == 0)
    status = put_env(shell->env);
  else if (my_strcmp(list->cmd[0], "cd") == 0)
    status = cd(shell, list->cmd);
  else if (my_strcmp(list->cmd[0], "setenv") == 0 && list->cmd)
    status = set_env(shell->env, list->cmd[1], list->cmd[2]);
  else if (my_strcmp(list->cmd[0], "unsetenv") == 0)
    status = unset_env(shell->env, list->cmd);
  else if (my_strcmp(list->cmd[0], "history") == 0 && list->cmd)
    status = history(shell->history, list->cmd);
  else if (my_strcmp(list->cmd[0], "jobs") == 0 && list->cmd)
    status = jobs(shell, list);
  else if (my_strcmp(list->cmd[0], "fg") == 0 && list->cmd)
    status = fg(shell, list);
  else
    return (my_fork_no_builtins(list, shell, status));
  if (status == FALSE)
    shell->exit_status = 1;
  return (status);
}
