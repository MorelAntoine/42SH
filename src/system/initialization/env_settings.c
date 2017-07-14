/*
** env.c for PSU_2015_minishell2 in C:/rendu/PSU_2015_minishell2
**
** Made by Geoffrey Davril
** Login   <davril_g@epitech.net>
**
** Started on  Mon Apr 18 20:53:16 2016 Geoffrey Davril
** Last update Mon Apr 18 20:53:16 2016 Geoffrey Davril
*/

#include	<stdlib.h>
#include	"env.h"
#include	"library.h"

t_env_var	*init_env_var()
{
  t_env_var	*var;

  if (!(var = malloc(sizeof(t_env_var))))
    return (NULL);
  var->name = NULL;
  var->value = NULL;
  var->next = NULL;
  return (var);
}

void		add_var_in_env(t_env *env, char *name, char *value)
{
  t_env_var	*var;

  if (!env->vars)
    {
      env->vars = init_env_var();
      var = env->vars;
    }
  else
    {
      var = env->vars;
      while (var->next)
	var = var->next;
      var->next = init_env_var();
      var = var->next;
    }
  var->name = my_strdup(name);
  var->value = my_strdup(value);
}

t_env		*init_env(char **ae)
{
  t_env		*env;
  int		index;
  int		index_name;
  char		*s;
  char		*s1;

  if ((env = malloc(sizeof(t_env))) == NULL)
    return (NULL);
  env->vars = NULL;
  index = 0;
  while (ae[index])
    {
      index_name = 0;
      while (ae[index][index_name] && ae[index][index_name] != '=')
	index_name++;
      add_var_in_env(env, (s = my_strncpy(ae[index], index_name)),
		     (s1 = my_strdup(ae[index] + index_name + 1)));
      free(s);
      free(s1);
      index++;
    }
  env->env = env_to_tab(env);
  return (env);
}

void		clean_env(t_env *env)
{
  t_env_var	*var;
  t_env_var	*tmp;

  if (env == NULL)
    return ;
  var = env->vars;
  while (var)
    {
      free(var->name);
      if (var->value)
	free(var->value);
      tmp = var;
      var = var->next;
      free(tmp);
    }
  if (env->env)
    free_board(env->env);
  free(env);
}
