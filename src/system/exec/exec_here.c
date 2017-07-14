/*
** exec_here.c for 42sh in Documents/annee_1/semestre_2/unix/PSU_2015_42sh/src/system/exec
**
** Made by Antoine MOREL
** Login   <morel_j@epitech.net>
**
** Started on  Tue May 24 17:41:41 2016 Antoine MOREL
** Last update Mon May 30 11:24:51 2016 Baptiste Mairesse
*/

#include	<unistd.h>
#include	"actions.h"
#include	"library.h"

int		exec_here(char **elem, t_shell *shell)
{
  char		**tab;

  tab = NULL;
  if (access(elem[0], F_OK) == 0)
    execve(elem[0], elem, (tab = env_to_tab(shell->env)));
  if (tab)
    free_board(tab);
  return (0);
}

int		present_here(char **elem)
{
  int		index;

  index = 0;
  if (access(elem[0], F_OK) != 0)
    return (-1);
  while (elem[0][index] != '\0')
    {
      if (end_of_get(elem[0], index) == TRUE)
	{
	  if (elem[0][index] == '/')
	    return (0);
	}
      index++;
    }
  return (-1);
}
