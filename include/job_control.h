/*
** jobcontrol.h for PSU_2015_42sh in C:/Users/geoff/OneDrive - Epitech/Geof/rendu/PSU_2015_42sh
**
** Made by Geoffrey Davril
** Login   <davril_g@epitech.net>
**
** Started on  Tue May 17 17:21:23 2016 Geoffrey Davril
** Last update Thu Jun 02 14:11:30 2016 Baptiste Mairesse
*/

#ifndef			JOB_CONTROL_H_
# define		JOB_CONTROL_H_

# include		<sys/types.h>
# include		"bool.h"

typedef struct		s_job_control
{
  pid_t			chld_pid;
  char			*chld_name;
  struct s_job_control	*next;
  struct s_job_control	*prev;
}			t_job_control;

typedef struct		s_job_control_ctrl
{
  t_job_control		*first;
  t_job_control		*last;
}			t_job_control_ctrl;

t_job_control_ctrl	*init_job_control(void);
void			catch_sigint(int sig);
int			kill(pid_t pid, int sig);
void			kill_child(t_job_control_ctrl *jc);
void			clean_job_control(t_job_control_ctrl *job_control);

#endif			/* !JOB_CONTROL_H_ */
