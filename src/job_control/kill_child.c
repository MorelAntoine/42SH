/*
** kill_child.c for 42sh in /home/dylan/Documents/PSU/PSU_2015_42sh/src
** 
** Made by Dylan Deu
** Login   <deu_d@epitech.net>
** 
** Started on  Thu Jun  2 18:37:17 2016 Dylan Deu
** Last update Sun Jun 05 22:17:13 2016 Baptiste Mairesse
*/

#include	<signal.h>
#include	<sys/types.h>
#include	<stdlib.h>
#include	"job_control.h"

void		kill_child(t_job_control_ctrl *ctrl)
{
  t_job_control	*del;
  t_job_control	*tmp;

  if (ctrl->first)
    tmp = ctrl->first;
  else
    return ;
  while (tmp != NULL)
    {
      del = tmp;
      kill(del->chld_pid, SIGINT);
      tmp = tmp->next;
      free(del);
    }
}
