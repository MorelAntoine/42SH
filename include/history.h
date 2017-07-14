/*
** history.h for PSU_2015_42sh in C:/Users/geoff/OneDrive - Epitech/Geof/rendu/PSU_2015_42sh
**
** Made by Geoffrey Davril
** Login   <davril_g@epitech.net>
**
** Started on  Tue May 17 18:02:44 2016 Geoffrey Davril
** Last update Tue May 17 18:02:44 2016 Geoffrey Davril
*/

#ifndef			HISTORY_H_
# define		HISTORY_H_

#include		"bool.h"

# define		HISTORY_PATH		("42sh.history")
# define		HISTORY_LOAD_SIZE	(1000)

typedef struct		s_history
{
  char			*history;
  struct s_history	*next;
}			t_history;

t_history		*init_history(void);
void			clean_history(t_history *history);
char			*get_history_from_history(t_history *hist, char *cmd);
t_history		*add_in_history(t_history *hist, char *cmd);
t_history		*load_history();
bool			history(t_history *hist, char **argv);
char			*exec_history(t_history *hist, char *cmd);
bool			is_history_cmd_search(char *str);

#endif			/* !HISTORY_H_ */
