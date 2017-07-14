/*
** job_control_settings.c for PSU_2015_42sh in C:/Users/geoff/OneDrive - Epitech/Geof/rendu/PSU_2015_42sh
**
** Made by Geoffrey Davril
** Login   <davril_g@epitech.net>
**
** Started on  Thu May 19 14:36:30 2016 Geoffrey Davril
** Last update Sun Jun 05 22:17:17 2016 Baptiste Mairesse
*/

#include		<stdlib.h>
#include		<signal.h>
#include 		<unistd.h>
#include		"job_control.h"

t_job_control_ctrl	*init_job_control(void)
{
  t_job_control_ctrl	*jb;

  if ((jb = malloc(sizeof(t_job_control_ctrl))) == NULL)
    return (NULL);
  jb->first = NULL;
  jb->last = NULL;
  return (jb);
}

void		clean_job_control(t_job_control_ctrl *jb)
{
  if (!jb)
    return ;
  free(jb);
}
