/*
** history_manage.c for PSU_2015_42sh in C:/Users/geoff/OneDrive - Epitech/Geof/rendu/PSU_2015_42sh
**
** Made by Geoffrey Davril
** Login   <davril_g@epitech.net>
**
** Started on  Thu May 26 11:02:47 2016 Geoffrey Davril
** Last update Sat Jun  4 16:49:17 2016 Dylan Deu
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"history.h"
#include	"library.h"

t_history	*load_history()
{
  t_history	*hist;

  if (!(hist = init_history()))
    return (NULL);
  return (hist);
}

t_history	*add_in_history(t_history *hist, char *cmd)
{
  t_history	*tmp;

  if (same_str(hist->history, cmd) || !my_strlen(cmd))
    return (hist);
  if (!(tmp = init_history()))
    return (hist);
  tmp->next = hist;
  tmp->history = my_strdup(cmd);
  return (tmp);
}

static char	*get_history_from_number(t_history *hist, char *cmd)
{
  int		n;
  int		go;
  t_history	*tmp;

  go = 0;
  if (cmd[1] == '-' &&  is_number(cmd + 2) && (n = my_getnbr(cmd + 2)))
    {
      while (go != n - 1 && hist && ++go)
	hist = hist->next;
      if (hist)
	return (hist->history);
    }
  else if (is_number(cmd + 1) && (n = my_getnbr(cmd + 1)) && (tmp = hist))
    {
      while (tmp && ++go)
	tmp = tmp->next;
      go -= n;
      n = 0;
      while (hist && ++n < go)
	hist = hist->next;
      if (hist && go > 0)
	return (hist->history);
    }
  return (NULL);
}

char		*get_history_from_history(t_history *hist, char *command)
{
  char		*cmd;

  while (command[0] && (command[0] == ' ' || command[0] == '\t') && ++command);
  if (command[0] != '!')
    return (NULL);
  else if (command[1] == '!' && !command[2] && hist->next && hist->next)
    return (hist->history);
  else if (command[1] == '?' && command[2])
    {
      while (hist)
	{
	  if (str_contains(command + 2, hist->history))
	    return (hist->history);
	  hist = hist->next;
	}
    }
  else if ((cmd = get_history_from_number(hist, command)))
    return (cmd);
  while (hist)
    {
      if (same_str_begin(command + 1, hist->history))
	return (hist->history);
      hist = hist->next;
    }
  return (NULL);
}

bool		is_history_cmd_search(char *str)
{
  int		index;

  index = 0;
  while (str[index] && (str[index] == ' ' || str[index] == '\t'))
    index++;
  if  (!str[index])
    return (FALSE);
  if (str[index] == '!')
    return (TRUE);
  return (FALSE);
}
