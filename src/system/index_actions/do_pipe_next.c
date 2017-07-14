/*
** do_pipe_next.c for 42sh in Documents/annee_1/semestre_2/unix/PSU_2015_42sh/src/system/index_actions
**
** Made by Antoine MOREL
** Login   <morel_j@epitech.net>
**
** Started on  Tue May 24 17:38:17 2016 Antoine MOREL
** Last update Fri Jun  3 18:44:14 2016 Dylan Deu
*/

#include	<sys/types.h>
#include	<sys/wait.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	"actions.h"
#include	"shell.h"

static void	print_core_dumped(int status, int *ret, int index)
{
  if ((*ret) == 0)
    {
      if (status == 139)
	write(2, "Segmentation fault (core dumped)", 32);
      else if (status == 136)
	write(2, "Floating exception (core dumped)", 32);
    }
  else if (*ret == 1 && (status == 139 || status == 139))
    write(2, "  (core dumped)", 15);
  if (status == 136 || status == 139)
    (*ret)++;
  if (index == 1 && *ret > 0)
    write(1, "\n", 1);
}

int		get_invalid_status(t_shell *shell, int status, int index)
{
  int		ret;
  int		tmp;

  ret = 0;
  tmp = status;
  print_core_dumped(status, &ret, index);
  while (index-- > 0)
    {
      wait(&status);
      if (tmp != 256 && index > 1)
	{
	  if (status == 136 && tmp == 139)
	    tmp = 139;
	  else if (status == 139 && (tmp == 136 || tmp == 0))
	    tmp = status;
	  else if (tmp == 0 && (status == 139 || status == 136 || status == 256))
	    tmp = status;
	}
      print_core_dumped(status, &ret, index);
    }
  tmp = (tmp >= 256) ? tmp / 256 : tmp;
  shell->exit_status = tmp;
  return (tmp);
}

void		init_fall(int *fd, int *status, int start, int save_fd)
{
  fd[0] = start;
  fd[1] = save_fd;
  status[0] = 0;
  status[2] = 1;
  status[1] = 0;
  status[3] = 0;
}
