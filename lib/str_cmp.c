/*
** str_cmp.c for PSU_2015_42sh in C:/Users/geoff/OneDrive - Epitech/Geof/rendu/PSU_2015_42sh
**
** Made by Geoffrey Davril
** Login   <davril_g@epitech.net>
**
** Started on  Thu May 19 14:50:21 2016 Geoffrey Davril
** Last update Thu May 19 14:50:21 2016 Geoffrey Davril
*/

#include	<string.h>
#include	<stdlib.h>
#include	"bool.h"
#include	"library.h"

bool		same_str(char *a, char *b)
{
  int		index;

  if (!a || !b)
    return (FALSE);
  index = 0;
  while (a[index])
    {
      if (!b[index])
	return (FALSE);
      if (b[index] != a[index])
	return (FALSE);
      index++;
    }
  if (b[index])
    return (FALSE);
  return (TRUE);
}

bool		str_contains(char *content, char *str)
{
  int		index_str;
  int		index_content;

  index_str = 0;
  if (!content || !content[0] || !str || !str[0])
    return (FALSE);
  while (str[index_str])
    {
      if (str[index_str] == content[0])
	{
	  index_content = 0;
	  while (str[index_str + index_content]
		 && str[index_str + index_content] == content[index_content])
	    index_content++;
	  if (!content[index_content])
	    return (TRUE);
	}
      index_str++;
    }
  return (FALSE);
}

int		my_strcmp(char *s1, char *s2)
{
  int		c1;

  c1 = 0;
  if (s1 == NULL || s2 == NULL)
    return (-1);
  if (my_strlen(s1) != my_strlen(s2))
    return (-1);
  while (s1[c1] == s2[c1] && s1[c1] != '\0')
    {
      c1++;
    }
  return (s1[c1] - s2[c1]);
}

bool		same_str_begin(char *begin, char *str)
{
  int		index;

  index = 0;
  while (begin[index])
    {
      if (!str || !str[index])
	return (FALSE);
      if (str[index] != begin[index])
	return (FALSE);
      index++;
    }
  return (TRUE);
}
