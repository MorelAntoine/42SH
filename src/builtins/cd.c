/*
** cd.c for cd in /home/dylan/Documents/PSU/PSU_2015_42sh
** 
** Made by Dylan Deu
** Login   <deu_d@epitech.net>
** 
** Started on  Sat Jun  4 16:44:13 2016 Dylan Deu
** Last update Sat Jun  4 16:44:16 2016 Dylan Deu
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<errno.h>
#include	<string.h>
#include	"bool.h"
#include	"shell.h"
#include	"library.h"

static bool	cd_go_dir(t_shell *shell, char *path)
{
  char		*s;

  if (path == NULL)
    return (FALSE);
  s = getcwd(NULL, 0);
  if (chdir(path) == -1)
    {
      put_error(path);
      put_error(": ");
      put_error(strerror(errno));
      put_error(".\n");
      if (s != NULL)
	free(s);
      free(path);
      return (FALSE);
    }
  set_env(shell->env, "OLDPWD", s);
  if (s != NULL)
    free(s);
  set_env(shell->env, "PWD", getcwd(NULL, 0));
  return (TRUE);
}

bool		cd(t_shell *shell, char **av)
{
  char		*path;

  if (av[1] == NULL)
    {
      if ((path = get_env(shell->env, "HOME")) == NULL)
	return (FALSE);
      else
	return (cd_go_dir(shell, path));
    }
  else if (av[2] != NULL)
    {
      put_error("cd: Too many arguments.\n");
      return (FALSE);
    }
  else if (same_str("-", av[1]))
    {
      if ((path = get_env(shell->env, "OLDPWD")) == NULL)
	return (FALSE);
      else
	return (cd_go_dir(shell, path));
    }
  else
    return (cd_go_dir(shell, my_strdup(av[1])));
}
