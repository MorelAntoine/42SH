/*
** shell.h for PSU_2015_42sh in C:/Users/geoff/OneDrive - Epitech/Geof/rendu/PSU_2015_42sh
**
** Made by Geoffrey Davril
** Login   <davril_g@epitech.net>
**
** Started on  Tue May 17 16:21:11 2016 Geoffrey Davril
** Last update Tue May 17 16:21:11 2016 Geoffrey Davril
*/

#ifndef			SHELL_H_
# define		SHELL_H_

#include		"env.h"
#include		"job_control.h"
#include		"history.h"
#include		"prompt.h"

typedef struct		s_shell
{
  t_env			*env;
  t_history		*history;
  t_job_control_ctrl	*job_control;
  t_prompt		*prompt;
  unsigned char		exit_status;
}			t_shell;

t_shell			*init_shell(char **env);
void			clean_shell(t_shell *shell);
void			mainloop(t_shell *shell);

#endif			/* !SHELL_H_ */
