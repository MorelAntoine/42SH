/*
** nb.c for PSU_2015_42sh in C:/Users/geoff/OneDrive - Epitech/Geof/rendu/PSU_2015_42sh
**
** Made by Geoffrey Davril
** Login   <davril_g@epitech.net>
**
** Started on  Thu May 19 14:32:25 2016 Geoffrey Davril
** Last update Thu May 19 14:32:25 2016 Geoffrey Davril
*/

#include	<stdlib.h>
#include	"bool.h"

bool		is_number(char *nb)
{
  int		index;

  if (!nb)
    return (FALSE);
  index = 0;
  if (nb[index] == '-')
    index++;
  if (nb[index] == 0)
    return (FALSE);
  while (nb[index] != 0)
    {
      if (!(nb[index] >= '0' && nb[index] <= '9'))
	return (FALSE);
      index++;
    }
  return (TRUE);
}

int		my_getnbr(char *nb)
{
  int		result;
  int		index;
  char		neg;

  if (nb == NULL)
    return (0);
  neg = 0;
  index = 0;
  if (nb[0] == '-' && ++neg)
    index++;
  result = 0;
  while (nb[index] != 0)
    {
      result = result * 10 + nb[index] - '0';
      index++;
    }
  if (neg)
    return (-result);
  return (result);
}
