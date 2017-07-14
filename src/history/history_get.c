/*
** history_get.c for PSU_2015_42sh in C:/Users/geoff/OneDrive - Epitech/Geof/rendu/PSU_2015_42sh
**
** Made by Geoffrey Davril
** Login   <davril_g@epitech.net>
**
** Started on  Mon May 30 15:15:41 2016 Geoffrey Davril
** Last update Mon May 30 15:15:41 2016 Geoffrey Davril
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"history.h"
#include	"bool.h"
#include	"library.h"

char		*exec_history(t_history *hist, char *command)
{
  char		*cmd;

  if ((cmd = get_history_from_history(hist, command)))
    {
      write(1, cmd, my_strlen(cmd));
      write(1, "\n", 1);
      return (cmd);
    }
  put_error(command + 1);
  put_error(": Event not found.\n");
  return (NULL);
}

static void	put_history(t_history *hist, int n)
{
  int		i;

  i = 0;
  while (hist && (n == -1 || i < n || i == 0))
    {
      write(1, hist->history, my_strlen(hist->history));
      write(1, "\n", 1);
      hist = hist->next;
      i++;
    }
}

bool		history(t_history *hist, char **argv)
{
  int		n;

  n = -1;
  if (argv[1])
    {
      if (is_number(argv[1]))
	n = my_getnbr(argv[1]);
      else
	{
	  put_error("history: Badly formed number.\n");
	  return (FALSE);
	}
      if (n < 0)
	{
	  put_error("Usage: history [# number of events].\n");
	  return (FALSE);
	}
    }
  put_history(hist, n);
  return (TRUE);
}
