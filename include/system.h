/*
** system.h for 42sh in Documents/annee_1/semestre_2/unix/PSU_2015_42sh/include
**
** Made by Antoine MOREL
** Login   <morel_j@epitech.net>
**
** Started on  Fri May 20 10:55:10 2016 Antoine MOREL
** Last update Sat Jun  4 16:59:36 2016 Dylan Deu
*/

#ifndef			SYSTEM_H_
# define		SYSTEM_H_

#include		"shell.h"

typedef	struct		s_list
{
  char			index;
  char			**cmd;
  struct s_list		*next;
}			t_list;

typedef	struct		s_ctrl
{
  int			length;
  struct s_list		*first;
  struct s_list		*last;
}			t_ctrl;

# ifndef		NOTHING
#  define		NOTHING 0
# endif			/* !NOTHING */

# ifndef		S_PIPE
#  define		S_PIPE 1
# endif			/* !PIPE */

# ifndef		D_PIPE
#  define		D_PIPE 2
# endif			/* !D_PIPE */

# ifndef		AMPERSAND
#  define		S_AMPERSAND 3
# endif			/* !S_AMPERSAND */

# ifndef		AMPERSAND
#  define		AMPERSAND 8
# endif			/* !AMPERSAND */

# ifndef		S_LEFT
#  define		S_LEFT 4
# endif			/* !S_LEFT */

# ifndef		S_RIGHT
#  define		S_RIGHT 5
# endif			/* !S_RIGHT */

# ifndef		D_LEFT
#  define		D_LEFT 6
# endif			/* !D_LEFT */

# ifndef		D_RIGHT
#  define		D_RIGHT 7
# endif			/* !D_RIGHT */

char			*global_var(char *, t_env *, char *);
bool			core_shell(t_shell *shell, char *str);
int			special_redir(char *str, t_ctrl *ctrl, int cpt,
				      char f_idx);
t_ctrl			*epur_and_add_store(char *cmd, t_ctrl *ctrl,
					    char index, t_env *env);
char			*get_cmd(char *str);
t_ctrl			*store_cmds(char *str, t_shell *shell);
char			get_index(char *str, int *i);
bool			end_of_get(char *str, int index);
char			**my_str_to_wordtab_quote(char *str, char sep);
t_ctrl			*set_ctrl(void);
t_ctrl			*add_end(t_ctrl *ctrl, char **board, char index);
void			free_list(t_ctrl *ctrl);
bool			is_valid_quote(char **full_str, int index);
void			delete_backslash_cmd(char **str);
int			good_following(t_ctrl *ctrl, t_shell *shell);
bool			my_exit(char **cmd, t_shell *shell);

#endif			/* !SYSTEM_H_ */
