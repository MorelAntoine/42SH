/*
** history_settings.c for PSU_2015_42sh in C:/Users/geoff/OneDrive - Epitech/Geof/rendu/PSU_2015_42sh
**
** Made by Geoffrey Davril
** Login   <davril_g@epitech.net>
**
** Started on  Thu May 19 14:40:54 2016 Geoffrey Davril
** Last update Thu May 19 14:40:54 2016 Geoffrey Davril
*/

#include	<stdlib.h>
#include	"history.h"

t_history	*init_history(void)
{
  t_history	*hist;

  if ((hist = malloc(sizeof(t_history))) == NULL)
    return (NULL);
  hist->history = NULL;
  hist->next = NULL;
  return (hist);
}

void		clean_history(t_history *hist)
{
  t_history	*tmp;

  while (hist)
    {
      tmp = hist;
      hist = hist->next;
      if (tmp->history)
	free(tmp->history);
      free(tmp);
    }
}
