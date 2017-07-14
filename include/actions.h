/*
** actions.h for 42sh in Documents/annee_1/semestre_2/unix/PSU_2015_42sh/include
**
** Made by Antoine MOREL
** Login   <morel_j@epitech.net>
**
** Started on  Tue May 24 17:33:11 2016 Antoine MOREL
** Last update Fri Jun  3 19:00:53 2016 Dylan Deu
*/

#ifndef		ACTIONS_H_
# define	ACTIONS_H_

# include	"system.h"

/*
** INDEX_ACTIONS
*/
bool		my_fork(t_list *list, t_shell *shell, int status);
bool		do_d_left(t_list *list, t_shell *shell);
bool		do_s_left(t_list *list, t_shell *shell, bool status);
bool		s_left(int fd, t_list *list, t_shell *shell, bool status);
bool		do_pipe(t_list *list, t_shell *shell);
int		get_invalid_status(t_shell *shell, int status, int index);
void		init_fall(int *fd, int *status, int start, int save_fd);
bool		waterfall(t_list *list, t_shell *shell, int save_fd, int start);
bool		do_d_right(t_list *list, t_shell *shell);
bool		jobs(t_shell *shell, t_list *list);
bool		fg(t_shell *shell, t_list *list);
bool		do_s_right(t_list *list, t_shell *shell);
bool		exit_waterfall(t_shell *shell, pid_t pid, int status[4], int fd[2]);

/*
** EXEC
*/
int		present_here(char **elem);
int		exec_here(char **elem, t_shell *shell);
void		exec_cmd(char **elem, t_env *env);
void		msg_status(int status, t_shell *shell, t_list *list);
void		mysh_actions(t_list *list, t_shell *shell);
int		present_on_cp(char **elem, t_env *env);

#endif		/* !ACTIONS_H_ */
