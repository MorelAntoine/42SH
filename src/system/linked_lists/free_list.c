/*
** free_list.c for 42sh in Documents/annee_1/semestre_2/unix/PSU_2015_42sh/src/system/linked_lists
**
** Made by Antoine MOREL
** Login   <morel_j@epitech.net>
**
** Started on  Sun Jun 05 11:09:25 2016 Antoine MOREL
** Last update Sun Jun 05 11:09:25 2016 Antoine MOREL
*/

#include	<stdlib.h>
#include	"library.h"
#include	"system.h"

void		free_list(t_ctrl *ctrl)
{
  t_list	*tmp;
  t_list	*del;

  if ((tmp = ctrl->first) != NULL)
    {
      while (tmp != NULL)
	{
	  del = tmp;
	  tmp = tmp->next;
	  free_board(del->cmd);
	  free(del);
	}
    }
  free(ctrl);
}
