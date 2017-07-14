/*
** delete_backslash_cmd.c for PSU_2015_42sh in C:/Users/geoff/OneDrive - Epitech/Geof/rendu/PSU_2015_42sh
**
** Made by Geoffrey Davril
** Login   <davril_g@epitech.net>
**
** Started on  Tue May 24 14:20:57 2016 Geoffrey Davril
** Last update Tue May 24 14:20:57 2016 Geoffrey Davril
*/

#include	<stdlib.h>
#include	<string.h>
#include	"system.h"

void		delete_backslash_cmd(char **str)
{
  int		pos_index;
  int		index;
  int		quote;

  index = 0;
  pos_index = 0;
  quote = 0;
  while (str && str[0] && index < (int)strlen(str[0]) && str[0][index])
    {
      if (str[0][index] == '\\')
	str[0][pos_index++] = str[0][++index];
      else if (str[0][index] == '\'' || str[0][index] == '"')
	{
	  if (quote == 0)
	    quote = str[0][index];
	  else if (quote == str[0][index])
	    quote = 0;
	  else
	    str[0][pos_index++] = str[0][index];
	}
      else
	str[0][pos_index++] = str[0][index];
      index++;
    }
  str[0][pos_index] = 0;
}
