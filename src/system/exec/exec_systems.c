/*
** exec_systems.c for 42sh in Documents/annee_1/semestre_2/unix/PSU_2015_42sh/src/system/exec
**
** Made by Antoine MOREL
** Login   <morel_j@epitech.net>
**
** Started on  Tue May 24 17:42:43 2016 Antoine MOREL
** Last update Sat Jun  4 16:53:45 2016 Dylan Deu
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<sys/types.h>
#include	<sys/wait.h>
#include	"actions.h"
#include	"library.h"
#include	"env.h"

pid_t 		g_cur_child_pid;

void		add_pid_to_list(pid_t pid, char *bin,
				t_job_control_ctrl *jb_ctrl)
{
  t_job_control	*elem;

  elem = malloc(sizeof(t_job_control));
  if (elem == NULL)
    return ;
  elem->chld_pid = pid;
  elem->chld_name = my_strdup(bin);
  elem->prev = NULL;
  if (jb_ctrl->first != NULL)
    jb_ctrl->first->prev = elem;
  else
    jb_ctrl->last = elem;
  jb_ctrl->first = elem;
}

void		msg_status(int status, t_shell *shell, t_list *list)
{
  if (status >= 256)
    shell->exit_status = (unsigned char)((status / 256) % 256);
  else
    shell->exit_status = (unsigned char)status;
  if (WIFSIGNALED(status))
    {
      if (WTERMSIG(status) == 11)
	write(2, "Segmentation fault (core dumped)\n", 33);
      if (WTERMSIG(status) == 8)
	write(2, "Floating exception (core dumped)\n", 33);
    }
  if (WSTOPSIG(status) == 19 || WSTOPSIG(status) == 20)
    add_pid_to_list(g_cur_child_pid, list->cmd[0], shell->job_control);
}

void		exec_cmd(char **elem, t_env *env)
{
  char		*path;
  char		**pathnames;
  int		i;
  char		*slash;

  path = get_env(env, "PATH");
  pathnames = my_str_to_wordtab(path, ':');
  i = 0;
  slash = my_strdup("/");
  while (pathnames[i] != NULL)
    {
      pathnames[i] = my_strcat(pathnames[i], slash);
      pathnames[i] = my_strcat(pathnames[i], elem[0]);
      i++;
    }
  i = 0;
  while (pathnames[i] != NULL && execve(pathnames[i], elem, env->env) == -1)
    i++;
  free_board(pathnames);
  free(path);
  free(slash);
}
