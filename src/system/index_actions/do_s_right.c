/*
** do_s_right.c for 42sh in Documents/annee_1/semestre_2/unix/PSU_2015_42sh/src/system/index_actions
**
** Made by Antoine MOREL
** Login   <morel_j@epitech.net>
**
** Started on  Tue May 24 17:41:03 2016 Antoine MOREL
** Last update Tue May 24 17:41:03 2016 Antoine MOREL
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	"actions.h"

bool		do_s_right(t_list *list, t_shell *shell)
{
  t_list	*file;
  int		fd;
  int		save_fd;
  bool		status;

  status = TRUE;
  if ((file = list->next) != NULL)
    {
      if ((fd = open(file->cmd[0], O_RDWR | O_CREAT | O_TRUNC,
		     S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH)) != -1)
	{
	  save_fd = dup(1);
	  dup2(fd, 1);
	  status = my_fork(list, shell, 0);
	  dup2(save_fd, 1);
	  close(fd);
	  close(save_fd);
	}
    }
  return (status);
}
