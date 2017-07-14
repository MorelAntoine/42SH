/*
** present_on_cp.c for 42sh in Documents/annee_1/semestre_2/unix/PSU_2015_42sh/src/system/exec
**
** Made by Antoine MOREL
** Login   <morel_j@epitech.net>
**
** Started on  Tue May 24 17:44:25 2016 Antoine MOREL
** Last update Tue May 24 17:44:25 2016 Antoine MOREL
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<sys/types.h>
#include	<sys/wait.h>
#include	"actions.h"
#include	"library.h"

static	int	access_msg(char **pathnames)
{
  int		msg;
  int		i;

  i = 0;
  msg = -1;
  if (access(pathnames[0], F_OK) == 0)
    msg = 0;
  while (pathnames[i] != NULL && access(pathnames[i], F_OK) != 0)
    {
      i++;
      if (pathnames[i] != NULL && access(pathnames[i], F_OK) == 0)
	msg = 0;
    }
  return (msg);
}

int		present_on_cp(char **elem, t_env *env)
{
  int		msg;
  char		*path;
  char		**pathnames;
  int		i;
  char		*slash;

  if (!(path = get_env(env, "PATH")))
    return (-1);
  if (!path[0])
    return (-1);
  pathnames = my_str_to_wordtab(path, ':');
  i = 0;
  slash = my_strdup("/");
  if ((elem[0][0] == '.' && elem[0][1] == '/') ||
      (elem[0][0] == '.' && elem[0][1] == '.') || elem[0][0] == '/')
    return (-1);
  while (pathnames[i++] != NULL)
    {
      pathnames[i - 1] = my_strcat(pathnames[i - 1], slash);
      pathnames[i - 1] = my_strcat(pathnames[i - 1], elem[0]);
    }
  msg = access_msg(pathnames);
  free_board(pathnames);
  free(slash);
  return (msg);
}
