/*
** shell.c for PSU_2015_42sh in C:/Users/geoff/OneDrive - Epitech/Geof/rendu/PSU_2015_42sh
**
** Made by Geoffrey Davril
** Login   <davril_g@epitech.net>
**
** Started on  Thu May 19 11:53:01 2016 Geoffrey Davril
** Last update Tue May 31 18:09:29 2016 Baptiste Mairesse
*/

#include	<stdlib.h>
#include	"shell.h"
#include	"env.h"
#include	"history.h"
#include	"job_control.h"

t_shell		*init_shell(char **ae)
{
  t_shell	*shell;

  if ((shell = malloc(sizeof(t_shell))) == NULL)
    return (NULL);
  shell->env = init_env(ae);
  if (!(shell->history = init_history()))
    return (NULL);
  shell->job_control = NULL;
  if ((shell->prompt = init_prompt(shell)) == NULL)
    return (NULL);
  shell->exit_status = 0;
  shell->job_control = init_job_control();
  return (shell);
}

void		clean_shell(t_shell *shell)
{
  if (!shell)
    return ;
  if (shell->env != NULL)
    clean_env(shell->env);
  if (shell->history != NULL)
    clean_history(shell->history);
  if (shell->job_control != NULL)
    clean_job_control(shell->job_control);
  if (shell->prompt != NULL)
    clean_prompt(shell->prompt);
  free(shell);
}
