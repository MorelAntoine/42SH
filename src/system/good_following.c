/*
** good_following.c for 42sh in Documents/annee_1/semestre_2/unix/PSU_2015_42sh/src/system
**
** Made by Antoine MOREL
** Login   <morel_j@epitech.net>
**
** Started on  Tue May 24 17:22:48 2016 Antoine MOREL
** Last update Tue May 24 17:22:48 2016 Antoine MOREL
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"system.h"

static int	ambiguous_ouput(char index1, char index2, t_shell *shell)
{
  if ((index1 == S_RIGHT &&
       (index2 == S_RIGHT || index2 == D_RIGHT || index2 == S_PIPE)) ||
      (index1 == D_RIGHT && (index2 == S_RIGHT || index2 == D_RIGHT
			     || index2 == S_PIPE)))
    {
      write(2, "Ambiguous output redirect.\n", 27);
      shell->exit_status = 1;
      return (FALSE);
    }
  return (TRUE);
}

int		good_following(t_ctrl *ctrl, t_shell *shell)
{
  t_list	*tmp;
  char		index1;
  char		index2;

  if ((tmp = ctrl->first) == NULL)
    return (FALSE);
  index1 = tmp->index;
  while ((tmp = tmp->next) != NULL)
    {
      index2 = tmp->index;
      if ((index1 == S_PIPE && (index2 == S_LEFT || index2 == D_LEFT))
	  || (index1 == S_LEFT && (index2 == S_LEFT || index2 == D_LEFT))
	  || (index1 == D_LEFT && (index2 == S_LEFT || index2 == D_LEFT)))
	{
	  write(2, "Ambiguous input redirect.\n", 26);
	  shell->exit_status = 1;
	  return (FALSE);
	}
      if (ambiguous_ouput(index1, index2, shell) == FALSE)
	return (FALSE);
      index1 = index2;
    }
  return (TRUE);
}
