/*
** add_end.c for 42sh in Documents/annee_1/semestre_2/unix/PSU_2015_42sh/src/system/linked_lists
**
** Made by Antoine MOREL
** Login   <morel_j@epitech.net>
**
** Started on  Sun Jun 05 11:09:12 2016 Antoine MOREL
** Last update Sun Jun 05 11:09:12 2016 Antoine MOREL
*/

#include	<stdlib.h>
#include	"system.h"

t_ctrl		*add_end(t_ctrl *ctrl, char **board, char index)
{
  t_list	*list;

  if ((list = malloc(sizeof(t_list))) == NULL)
    return (NULL);
  list->cmd = board;
  list->index = index;
  if (ctrl->first == NULL)
    {
      ctrl->first = list;
      ctrl->last = list;
      list->next = NULL;
    }
  else
    {
      ctrl->last->next = list;
      ctrl->last = list;
      ctrl->last->next = NULL;
    }
  ctrl->length++;
  return (ctrl);
}
