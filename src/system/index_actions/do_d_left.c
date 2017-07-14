/*
** do_d_left.c for 42sh in /home/dylan/Documents/PSU
** 
** Made by Dylan Deu
** Login   <deu_d@epitech.net>
** 
** Started on  Thu May 26 14:37:56 2016 Dylan Deu
** Last update Sat Jun  4 15:10:59 2016 Dylan Deu
*/

#include	<sys/types.h>
#include	<sys/wait.h>
#include	<sys/stat.h>
#include	<stdlib.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	<string.h>
#include	"actions.h"
#include	"library.h"
#include	"get_next_line.h"

static int	close_do_d_left(int save[2], int pipefd[2],
				t_shell *shell, t_list *list)
{
  int		status;

  close(pipefd[1]);
  status = s_left(pipefd[0], list, shell, FALSE);
  close(pipefd[0]);
  dup2(save[0], 0);
  dup2(save[1], 1);
  return (status);
}

bool		do_d_left(t_list *list, t_shell *shell)
{
  t_list	*cmp;
  char		*str;
  int		pipefd[2];
  int		save[2];
  int		status;

  status = FALSE;
  if ((cmp = list->next) != NULL)
    {
      save[0] = dup(0);
      save[1] = dup(1);
      write(1, "? ", 2);
      pipe(pipefd);
      while ((str = get_next_line(0)) != NULL
	     && strcmp(str, cmp->cmd[0]) != 0 && pipefd[1] < 65000)
	{
	  write(pipefd[1], str, strlen(str));
	  write(pipefd[1], "\n", 1);
	  write(1, "? ", 2);
	  free(str);
	}
      status = close_do_d_left(save, pipefd, shell, list);
    }
  return (status);
}
