/*
** do_s_left.c for 42sh in Documents/annee_1/semestre_2/unix/PSU_2015_42sh/src/system/index_actions
**
** Made by Antoine MOREL
** Login   <morel_j@epitech.net>
**
** Started on  Tue May 24 17:37:41 2016 Antoine MOREL
** Last update Tue May 24 17:37:41 2016 Antoine MOREL
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	"actions.h"
#include	"library.h"

static void	close_for_me(int *save_fd, int fd)
{
  dup2(save_fd[0], 0);
  dup2(save_fd[1], 1);
  close(save_fd[0]);
  close(save_fd[1]);
  close(fd);
}

bool		s_left(int fd, t_list *list, t_shell *shell, bool status)
{
  t_list	*file2;
  int		out;

  dup2(fd, 0);
  if (list->next->index == S_RIGHT || list->next->index == D_RIGHT)
    {
      file2 = list->next->next;
      if (list->next->index == S_RIGHT)
	{
	  if ((out = open(file2->cmd[0], O_RDWR | O_CREAT | O_TRUNC,
			  S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH)) != -1)
	    dup2(out, 1);

	}
      else if (list->next->index == D_RIGHT)
	{
	  if ((out = open(file2->cmd[0], O_RDWR | O_CREAT | O_APPEND,
			  S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH)) != -1)
	    dup2(out, 1);
	}
    }
  status = my_fork(list, shell, 0);
  return (status);
}

bool		do_s_left(t_list *list, t_shell *shell, bool status)
{
  t_list	*file;
  int		fd;
  int		save_fd[2];

  if ((file = list->next) != NULL)
    {
      if ((fd = open(file->cmd[0], O_RDONLY)) != -1)
	{
	  save_fd[0] = dup(0);
	  save_fd[1] = dup(1);
	  if (list->next->next != NULL &&
	      (list->next->index != S_RIGHT && list->next->index != D_RIGHT))
	    status = waterfall(list, shell, save_fd[1], fd);
	  else
	    status = s_left(fd, list, shell, status);
	  close_for_me(save_fd, fd);
	}
      else
	{
	  write(2, file->cmd[0], my_strlen(file->cmd[0]));
	  write(2, ": Aucun fichier ou dossier de ce type.\n", 39);
	}
    }
  return (status);
}
