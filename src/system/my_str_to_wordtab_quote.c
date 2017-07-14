/*
** my_str_to_wordtab_quote.c for 42sh in Documents/annee_1/semestre_2/unix/PSU_2015_42sh/src/system
**
** Made by Antoine MOREL
** Login   <morel_j@epitech.net>
**
** Started on  Sat May 21 16:52:51 2016 Antoine MOREL
** Last update Sat May 21 16:52:51 2016 Antoine MOREL
*/

#include	<stdlib.h>
#include	"bool.h"
#include	"system.h"
#include	"library.h"

static int	get_rows(char *str, char sep)
{
  int		rows;
  int		index;
  bool		space;

  rows = 0;
  index = 0;
  space = TRUE;
  while (str != NULL && str[index] != '\0')
    {
      if (end_of_get(str, index) == TRUE)
	{
	  if (space == FALSE && (str[index] == sep || str[index] == '\t'))
	    space = TRUE;
	  else if (space == TRUE && (str[index] != sep && str[index] != '\t'))
	    {
	      rows++;
	      space = FALSE;
	    }
	}
      index++;
    }
  return ((rows == 0 ? -1 : rows));
}

static char	*complete_lign(char *lign, char *str, char sep, int *cpt)
{
  while (str[(*cpt)] == sep || str[(*cpt)] == '\t')
    (*cpt)++;
  while (str[(*cpt)] != '\0')
    {
      if (end_of_get(str, (*cpt)) == TRUE)
	{
	  if (str[(*cpt)] == sep || str[(*cpt)] == '\t')
	    return (lign);
	  lign = my_str_charconcat(lign, str[(*cpt)]);
	}
      else
	lign = my_str_charconcat(lign, str[(*cpt)]);
      (*cpt)++;
    }
  return (lign);
}

char		**my_str_to_wordtab_quote(char *str, char sep)
{
  char		**board;
  int		rows;
  int		index;
  int		cpt;

  if ((rows = get_rows(str, sep)) == -1)
    return (NULL);
  if ((board = malloc(sizeof(char *) * (rows + 1))) == NULL)
    return (NULL);
  board[rows] = NULL;
  index = 0;
  cpt = 0;
  while (index < rows)
    {
      if ((board[index] = malloc(sizeof(char))) == NULL)
	return (NULL);
      board[index][0] = '\0';
      if ((board[index] = complete_lign(board[index], str, sep, &cpt)) == NULL)
	return (NULL);
      index++;
    }
  return (board);
}
