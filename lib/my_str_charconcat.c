/*
** my_str_charconcat.c for 42sh in Documents/annee_1/semestre_2/unix/PSU_2015_42sh/lib
**
** Made by Antoine MOREL
** Login   <morel_j@epitech.net>
**
** Started on  Thu May 19 14:16:54 2016 Antoine MOREL
** Last update Thu May 19 14:16:54 2016 Antoine MOREL
*/

#include	<stdlib.h>
#include	<string.h>

char		*my_str_charconcat(char *src, char c)
{
  char		*dest;
  size_t	index;

  if ((dest = malloc(sizeof(char) * (strlen(src) + 2))) == NULL)
    return (NULL);
  dest[strlen(src) + 1] = '\0';
  index = 0;
  while (src[index] != '\0')
    {
      dest[index] = src[index];
      index++;
    }
  dest[index] = c;
  free(src);
  return (dest);
}
