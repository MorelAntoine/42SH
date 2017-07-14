/*
** env.c for PSU_2015_42sh in C:/Users/geoff/OneDrive - Epitech/Geof/rendu/PSU_2015_42sh
**
** Made by Geoffrey Davril
** Login   <davril_g@epitech.net>
**
** Started on  Fri May 27 11:41:47 2016 Geoffrey Davril
** Last update Sun Jun  5 09:00:45 2016 Dylan Deu
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"env.h"
#include	"bool.h"
#include	"library.h"
#include	"error.h"

bool		put_env(t_env *env)
{
  t_env_var	*var;

  var = env->vars;
  while (var)
    {
      if (!var->value)
	{
	  write(1, var->name, my_strlen(var->name));
	  write(1, "=\n", 2);
	}
      else
	{
	  write(1, var->name, my_strlen(var->name));
	  write(1, "=", 1);
	  write(1, var->value, my_strlen(var->value));
	  write(1, "\n", 1);
	}
      var = var->next;
    }
  return (TRUE);
}

bool		set_env(t_env *env, char *name, char *value)
{
  int		index;
  t_env_var	*var;

  if (!env || !name)
    return (put_env(env));
  index = - 1;
  while ((++index || !index) && name[index])
    {
      if (!(name[index] >= 'a' && name[index] <= 'z')
	  && !(name[index] >= 'A' && name[index] <= 'Z')
	  && !(name[index] >= '0' && name[index] <= '9')
	  && name[index] != '_')
	return (put_error(ERROR_SET_ENV));
    }
  var = env->vars;
  while (var && !same_str(var->name, name))
    var = var->next;
  if (var && same_str(var->name, name))
    var->value = my_strdup(value);
  else
    add_var_in_env(env, name, value);
  free_board(env->env);
  env->env = env_to_tab(env);
  return (TRUE);
}

char		*get_env(t_env *env, char *name)
{
  t_env_var	*var;

  var = env->vars;
  while (var)
    {
      if (same_str(name, var->name))
	return (var->value);
      var = var->next;
    }
  return (NULL);
}

char		**env_to_tab(t_env *env)
{
  int		count;
  char		**tab;
  t_env_var	*var;
  char		*tmp;

  count = 0;
  var = env->vars;
  while (var && ++count)
    var = var->next;
  if (!(tab = malloc(sizeof(char *) * ((count + 1)))))
    return (NULL);
  count = 0;
  var = env->vars;
  while (var)
    {
      tmp = my_strconcat(var->name, "=");
      if (!var->value)
	tab[count++] = my_strdup(tmp);
      else
	tab[count++] = my_strconcat(tmp, var->value);
      free(tmp);
      var = var->next;
    }
  tab[count] = NULL;
  return (tab);
}
