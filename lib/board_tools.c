/*
** board_tools.c for 42sh in Documents/annee_1/semestre_2/unix/PSU_2015_42sh/lib
**
** Made by Antoine MOREL
** Login   <morel_j@epitech.net>
**
** Started on  Sun Jun 05 10:52:58 2016 Antoine MOREL
** Last update Sun Jun 05 10:52:58 2016 Antoine MOREL
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"library.h"

char		**clone_board(char **board)
{
  int		i;
  char		**clone;

  if (!board || !board[0])
    {
      if (!(clone = malloc(sizeof(char))))
	return (NULL);
      clone[0] = NULL;
      return (clone);
    }
  i = 0;
  while (board[i])
    i++;
  if (!(clone = malloc(sizeof(char *) * (i + 1))))
    return (NULL);
  clone[i] = NULL;
  i = 0;
  while (board[i])
    {
      if (!(clone[i] = my_strdup(board[i])))
	return (NULL);
      i++;
    }
  return (clone);
}

void		print_board(char **board)
{
  int		i;

  i = 0;
  while (board != NULL && board[i] != NULL)
    {
      printf("%s\n", board[i]);
      i++;
    }
}

void		free_board(char **board)
{
  int		i;

  i = 0;
  if (board != NULL)
    {
      while (board[i] != NULL)
	{
	  free(board[i]);
	  i++;
	}
      free(board);
    }
}
