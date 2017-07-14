/*
** set_ctrl.c for 42sh in Documents/annee_1/semestre_2/unix/PSU_2015_42sh/src/system/linked_lists
**
** Made by Antoine MOREL
** Login   <morel_j@epitech.net>
**
** Started on  Sun Jun 05 11:09:59 2016 Antoine MOREL
** Last update Sun Jun 05 11:09:59 2016 Antoine MOREL
*/

#include	<stdlib.h>
#include	"system.h"

t_ctrl		*set_ctrl(void)
{
  t_ctrl	*ctrl;

  if ((ctrl = malloc(sizeof(t_ctrl))) == NULL)
    return (NULL);
  ctrl->length = 0;
  ctrl->first = NULL;
  ctrl->last = NULL;
  return (ctrl);
}
