/*
** env.h for PSU_2015_42sh in C:/Users/geoff/OneDrive - Epitech/Geof/rendu/PSU_2015_42sh
**
** Made by Geoffrey Davril
** Login   <davril_g@epitech.net>
**
** Started on  Tue May 17 17:42:52 2016 Geoffrey Davril
** Last update Sun Jun  5 09:01:38 2016 Dylan Deu
*/

#ifndef			ENV_H_
# define		ENV_H_

#include		"bool.h"

# define		ERROR_SET_ENV	("setenv: Variable name must contain a\
lphanumeric characters.\n")

typedef struct		s_env_var
{
  char			*name;
  char			*value;
  struct s_env_var	*next;
}			t_env_var;

typedef struct		s_env
{
  t_env_var		*vars;
  char			**path;
  char			**env;
}			t_env;

t_env			*init_env(char **env_src);
void			clean_env(t_env *env);
char			**get_path(t_env *env);
char			*get_env(t_env *env, char *key);
bool			set_env(t_env *env, char *name, char *value);
bool			unset_env(t_env *env, char **arg);
bool			put_env(t_env *env);
void			add_var_in_env(t_env *env, char *name, char *value);
char			**env_to_tab(t_env *env);

#endif			/* !ENV_H_ */
