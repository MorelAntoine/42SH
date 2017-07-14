/*
** str_cpy.c for PSU_2015_42sh in C:/Users/geoff/OneDrive - Epitech/Geof/rendu/PSU_2015_42sh
**
** Made by Geoffrey Davril
** Login   <davril_g@epitech.net>
**
** Started on  Thu May 19 11:33:36 2016 Geoffrey Davril
** Last update Wed Jun  1 10:33:44 2016 Dylan Deu
*/

#include	<stdlib.h>
#include	"library.h"

int		my_strlen(char *str)
{
  int		i;

  if (!str)
    return (0);
  i = 0;
  while (str[i])
    i++;
  return (i);
}

char		*my_strdup(char *str)
{
  char		*result;
  int		i;

  if (!str)
    return (NULL);
  if (!(result = malloc(sizeof(char) * (my_strlen(str) + 1))))
    return (NULL);
  i = 0;
  while (str[i])
    {
      result[i] = str[i];
      i++;
    }
  result[i] = '\0';
  return (result);
}

char		*my_strconcat(char *a, char *b)
{
  char		*result;
  int		i_result;
  int		i_base;

  if (!(result = malloc(sizeof(char) * (my_strlen(a) + my_strlen(b) + 1))))
    return (NULL);
  i_result = 0;
  i_base = 0;
  while (a && a[i_base])
    result[i_result++] = a[i_base++];
  i_base = 0;
  while (b && b[i_base])
    result[i_result++] = b[i_base++];
  result[i_result] = 0;
  return (result);
}

char		*my_strcat(char *dest, char *src)
{
  int		i;
  int		j;
  char		*tmp;
  int		f;

  j = 0;
  f = 0;
  tmp = malloc((my_strlen(dest) + 1 + my_strlen(src)) * sizeof(char));
  if (!tmp)
    return (NULL);
  i = my_strlen(dest);
  while (dest[f])
    {
      tmp[f] = dest[f];
      f++;
    }
  while (src[j])
    tmp[i++] = src[j++];
  tmp[i] = '\0';
  free(dest);
  return (tmp);
}

char		*my_strncpy(char *str, int n)
{
  char		*result;
  int		index;

  if (!(result = malloc(sizeof(char) * (n + 1))))
    return (NULL);
  index = 0;
  while (str && str[index] && index < n)
    {
      result[index] = str[index];
      index++;
    }
  result[index] = 0;
  return (result);
}
