/*
** globlal_var.c for 42sh in /home/dylan/Documents/PSU/PSU_2015_42sh
** 
** Made by Dylan Deu
** Login   <deu_d@epitech.net>
** 
** Started on  Tue May 31 16:42:29 2016 Dylan Deu
** Last update Fri Jun  3 15:09:58 2016 Dylan Deu
*/

#include	<unistd.h>
#include	<string.h>
#include	<stdlib.h>
#include	"env.h"
#include	"library.h"

static char	*get_new_var(char *str, int *index)
{
  int		iterator;
  char		*new;

  iterator = 0;
  (*index)++;
  if ((new = malloc(sizeof(char) * (strlen(str) + 2))) == NULL)
    return (NULL);
  while (str[*index] != '$' && str[*index] != '\0')
    new[iterator++] = str[(*index)++];
  new[iterator] = '\0';
  return (new);
}

static char	*cpy_var(t_env *env, char *new_str, char *new_var, int *new_index)
{
  int		var_index;
  int		index;
  char		*var;

  index = 0;
  var_index = 0;
  new_str[*new_index] = '\0';
  if ((var = get_env(env, new_var)) != NULL)
    {
      if ((new_str = realloc(new_str, (strlen(new_str) +
				       strlen(var) + 2))) == NULL)
	return (NULL);
      while (var[var_index] != 0)
	{
	  new_str[*new_index] = var[var_index];
	  (*new_index)++;
	  var_index++;
	}
      new_str[*new_index] = '\0';
      return (new_str);
    }
  write(2, new_var, strlen(new_var));
  write(2, ": Undefined variable.\n", 22);
  return (NULL);
}

char		*global_var(char *str, t_env *env, char *new_var)
{
  int		new_index;
  int		index;
  char		*new_str;

  index = 0;
  new_index = 0;
  if ((new_str = malloc(sizeof(char) * (strlen(str) + 2))) == NULL)
    return (NULL);
  while (str[index] != '\0')
    {
      if (str[index] == '$')
	{
	  if ((new_var = get_new_var(str, &index)) != NULL)
	    {
	      if ((new_str = cpy_var(env, new_str, new_var, &new_index)) == NULL)
		return (NULL);
	      free(new_var);
	    }
	}
      else if (str[index] != '\0')
	new_str[new_index++] = str[index++];
    }
  new_str[new_index] = '\0';
  free(str);
  return (new_str);
}
