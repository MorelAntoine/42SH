/*
** jobs.c for PSU_2015_42sh in /home/maires_b/Dropbox/PSU_2015_42sh
**
** Made by Baptiste Mairesse
** Login   <maires_b@epitech.net>
**
** Started on  Thu Jun 02 22:53:34 2016 Baptiste Mairesse
** Last update Sun Jun 05 22:14:38 2016 Baptiste Mairesse
*/

#include	<stdio.h>
#include	<wait.h>
#include	<sys/wait.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	"actions.h"
#include	"system.h"
#include	"library.h"
#include	"bool.h"

bool		fg(t_shell *shell, t_list *list)
{
  int		status;
  t_job_control	*tmp;

  status = 0;
  if (!(tmp = shell->job_control->last))
    return (TRUE);
  kill(tmp->chld_pid, SIGCONT);
  waitpid(tmp->chld_pid, &status, WUNTRACED);
  msg_status(status, shell, list);
  shell->job_control->last = tmp->prev;
  if (tmp->prev)
    tmp->prev->next = NULL;
  else
    shell->job_control->last = NULL;
  if (shell->job_control->first == tmp)
    shell->job_control->first = NULL;
  free(tmp->chld_name);
  free(tmp);
  return (TRUE);
}

bool		jobs(t_shell *shell, t_list *list)
{
  t_job_control	*tmp;
  int		cpt;

  cpt = 1;
  if (!(tmp = shell->job_control->last))
    return (TRUE);
  if (list->cmd[1] && my_strcmp(list->cmd[1], "-l") != 0)
    {
      put_error("Usage: jobs [ -l ].\n");
      return (FALSE);
    }
  while (tmp)
    {
      printf("[%d]  + suspended (signal) %s\n", cpt++, tmp->chld_name);
      tmp = tmp->prev;
    }
  return (TRUE);
}
