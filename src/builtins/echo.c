/*
** echo.c for echo in /home/dylan/Documents/PSU/PSU_2015_42sh/src/builtins
** 
** Made by Dylan Deu
** Login   <deu_d@epitech.net>
** 
** Started on  Mon May 30 11:00:37 2016 Dylan Deu
** Last update Thu Jun  2 21:31:48 2016 Dylan Deu
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<string.h>
#include	"bool.h"
#include	"env.h"
#include	"shell.h"

static size_t	check_flags(char **av)
{
  size_t	value;
  size_t	index;
  size_t	type;

  type = 0;
  value = 0;
  index = 1;
  if (av[1] != NULL && av[1][0] == '-' && av[1][1] != '-')
    {
      while (av[1][index])
	{
	  if (av[1][index] == 'n')
	    value = 1;
	  index++;
	}
      return (value);
    }
  return (value);
}

static size_t	print_env_var(const char *arg, t_shell *shell,
			      char **av, size_t av_index)
{
  size_t	index_var;
  size_t	index_arg;
  char		*contents;
  char		*var;

  index_arg = 0;
  index_var = 0;
  if ((var = malloc(sizeof(char) * (strlen(arg) + 1))) == NULL)
    return (1);
  while (arg[index_arg] != '$' && arg[index_arg] != '\0')
    write(1, &arg[index_arg++], 1);
  while (arg[++index_arg] != '\0')
    var[index_var++] = arg[index_arg];
  var[index_var] = '\0';
  if ((contents = get_env(shell->env, var)) != NULL)
    {
      write(1, contents, strlen(contents));
      if (av[av_index + 1] != NULL)
	write(1, " ", 1);
      free(contents);
    }
  if (contents == NULL && arg[0] != '$')
    write(1, " ", 1);
  free(var);
  return (0);
}

static void	print_arg(const char *arg, char **av,
			  size_t av_index, t_shell *shell)
{
  char		ret;
  size_t	index;

  ret = 0;
  index = 0;
  while (arg[index] != '\0')
    {
      if (arg[index] == '$')
	ret = 1;
      index++;
    }
  if (ret == 1)
    print_env_var(arg, shell, av, av_index);
  else if (ret == 0)
    {
      write(1, arg, strlen(arg));
      if (av[av_index + 1] != NULL)
	write(1, " ", 1);
    }
}

bool		echo(t_shell *shell, char **av)
{
  size_t	tab;
  size_t	index;

  index = 1;
  if (av[1] != NULL)
    {
      if ((tab = check_flags(av)) != 0)
	index++;
      while (av[index] != NULL)
	{
	  print_arg(av[index], av, index, shell);
	  index++;
	}
      if (tab != 1)
	write(1, "\n", 1);
    }
  else
    write(1, "\n", 1);
  return (TRUE);
}
