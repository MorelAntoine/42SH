/*
** my_str_to_wordtab.c for 42sh in Documents/annee_1/semestre_2/unix/PSU_2015_42sh/lib
**
** Made by Antoine MOREL
** Login   <morel_j@epitech.net>
**
** Started on  Thu May 19 13:36:45 2016 Antoine MOREL
** Last update Thu May 19 13:36:45 2016 Antoine MOREL
*/

#include	<stdlib.h>
#include	<string.h>

static	int	malloc_tab(char *str, char **elem, int words)
  {
    int		i;
    int		total;

    i = 0;
    total = strlen(str);
    while (i < words)
      {
	if ((elem[i] = malloc(sizeof(char) * (total + 1))) == NULL)
	  return (1);
	elem[i][strlen(str)] = '\0';
	i++;
      }
    return (0);
  }

static	int	insert_words(char *str, char **elem, int words, char sep)
  {
    int		i;
    int		k;
    int		j;

    if (malloc_tab(str, elem, words) == 1)
      return (1);
    i = 0;
    j = 0;
    k = 0;
    while (str[j] != '\0' && i < words)
      {
	while ((str[j] == sep || str[j] == '\t') && str[j] != '\0')
	  j++;
	while ((str[j] != sep && str[j] != '\t') && str[j] != '\0')
	  {
	    elem[i][k] = str[j];
	    k++;
	    j++;
	  }
	elem[i][k] = '\0';
	i++;
	if (str[j] != '\0' && (k = 0) != -1)
	  j++;
      }
    return (0);
  }

static	int	how_many_words(char *str, char sep)
  {
    int		words;
    int		i;
    int		space;

    words = 0;
    i = 0;
    space = 0;
    if (str[0] != sep && str[0] != '\t' && str[0] != '\0')
      words++;
    else
      space = 1;
    while (str[i] != '\0')
      {
	while ((str[i] == sep || str[i] == '\t') && str[i] != '\0')
	  {
	    i++;
	    space = 1;
	  }
	if (str[i] != sep && str[i] != '\t' && str[i] != '\0' && space == 1)
	  words++;
	space = 0;
	if (str[i] != '\0')
	  i++;
      }
    return (words);
  }

char		**my_str_to_wordtab(char *str, char sep)
{
  char		**elem;
  int		words;

  if (str == NULL)
    return (NULL);
  if ((words = how_many_words(str, sep)) == 0)
    return (NULL);
  elem = malloc(sizeof(char *) * (words + 1));
  if (elem == NULL)
    return (NULL);
  elem[words] = NULL;
  if (insert_words(str, elem, words, sep) == 1)
    return (NULL);
  return (elem);
}
