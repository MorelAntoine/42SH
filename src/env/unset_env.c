/*
** unset_env.c for 42sh in /home/dylan/Documents/PSU/PSU_2015_42sh/src/env
** 
** Made by Dylan Deu
** Login   <deu_d@epitech.net>
** 
** Started on  Mon May 30 16:04:26 2016 Dylan Deu
** Last update Sun Jun  5 09:02:02 2016 Dylan Deu
*/

#include	<stdlib.h>
#include	"shell.h"
#include	"system.h"
#include	"bool.h"
#include	"env.h"
#include	"library.h"

static bool	delete_env(t_env *env, char *name)
{
  t_env_var	*var;
  t_env_var	*tmp;

  if (env->vars && same_str(env->vars->name, name) && (tmp = env->vars))
    env->vars = env->vars->next;
  else
    {
      var = env->vars;
      tmp = NULL;
      while (var && var->next)
	{
	  if (same_str(var->next->name, name) && (tmp = var->next))
	    var->next = var->next->next;
	  var = var->next;
	}
      if (!tmp)
	return (FALSE);
    }
  free(tmp->name);
  if (tmp->value)
    free(tmp->value);
  free(tmp);
  free_board(env->env);
  env->env = env_to_tab(env);
  return (TRUE);
}

bool		unset_env(t_env *env, char **arg)
{
  size_t	index;

  index = 1;
  if (arg[1] == NULL)
    {
      put_error("unsetenv: Too few arguments.\n");
      return (FALSE);
    }
  while (arg[index] != NULL)
    {
      delete_env(env, arg[index]);
      index++;
    }
  return (TRUE);
}
