/*
** do_pipe.c for 42sh in Documents/annee_1/semestre_2/unix/PSU_2015_42sh/src/system/index_actions
**
** Made by Antoine MOREL
** Login   <morel_j@epitech.net>
**
** Started on  Tue May 24 17:38:44 2016 Antoine MOREL
** Last update Sat Jun  4 17:02:31 2016 Dylan Deu
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<sys/types.h>
#include	<sys/wait.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<signal.h>
#include	"actions.h"
#include	"bool.h"

static void	wateropen(t_list *list, int *fd, int *pipefd)
{
  int		fd_end;

  if (list->next != NULL
      && (list->next->index == S_PIPE || list->next->index == NOTHING
	  || list->next->index == D_PIPE || list->next->index == AMPERSAND
	  || list->next->index == S_RIGHT || list->next->index == D_RIGHT))
    dup2(pipefd[1], 1);
  if (list->index == NOTHING || list->index == D_PIPE
      || list->index == AMPERSAND)
    dup2(fd[1], 1);
  else if (list->index == S_RIGHT)
    {
      if ((fd_end = open(list->next->cmd[0], O_RDWR | O_CREAT | O_TRUNC,
			 S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH)) != -1)
	dup2(fd_end, 1);
    }
  else if (list->index == D_RIGHT)
    {
      if ((fd_end = open(list->next->cmd[0], O_RDWR | O_CREAT | O_APPEND,
			 S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH)) != -1)
	dup2(fd_end, 1);
    }
}

static bool	waterfork(t_list *list, t_shell *shell, int *fd, int *pipefd)
{
  dup2(fd[0], 0);
  wateropen(list, fd, pipefd);
  close(pipefd[0]);
  mysh_actions(list, shell);
  return (FALSE_CHILD);
}

static t_list	*move_on(int *is_ok, int start, t_list *list)
{
  if ((*is_ok) != 1 && start != 0)
    {
      (*is_ok) = 1;
      if (list->next->next != NULL)
	list = list->next->next;
      else
	return (NULL);
    }
  else
    {
      if (list->next != NULL)
	list = list->next;
      else
	return (NULL);
    }
  return (list);
}

bool		waterfall(t_list *list, t_shell *shell, int save_fd, int start)
{
  pid_t		pid;
  int		status[4];
  int		fd[2];
  int		pipefd[2];

  init_fall(fd, status, start, save_fd);
  while (status[2] == 1)
    {
      pipe(pipefd);
      if ((pid = fork()) == 0)
	if (waterfork(list, shell, fd, pipefd) == FALSE_CHILD)
	  return (FALSE_CHILD);
      close(pipefd[1]);
      fd[0] = pipefd[0];
      if (list->index == S_RIGHT || list->index == D_RIGHT ||
	  list->index == NOTHING || list->index == AMPERSAND || list->index == D_PIPE)
	status[2] = 0;
      if ((list = move_on(&status[1], start, list)) == NULL)
	return (exit_waterfall(shell, pid, status, fd));
      status[3]++;
    }
  waitpid(pid, &status[0], WCONTINUED);
  status[0] = get_invalid_status(shell, status[0], status[3] - 1);
  close(fd[0]);
  return ((status[0] == 0 ? TRUE : FALSE));
}

bool		do_pipe(t_list *list, t_shell *shell)
{
  int		save_fd[2];
  bool		status;

  save_fd[0] = dup(0);
  save_fd[1] = dup(1);
  status = waterfall(list, shell, save_fd[1], 0);
  dup2(save_fd[0], 0);
  dup2(save_fd[1], 1);
  close(save_fd[0]);
  close(save_fd[1]);
  return (status);
}
