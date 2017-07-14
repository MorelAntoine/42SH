/*
** mysh_actions.c for 42sh in Documents/annee_1/semestre_2/unix/PSU_2015_42sh/src/system/exec
**
** Made by Antoine MOREL
** Login   <morel_j@epitech.net>
**
** Started on  Tue May 24 17:43:15 2016 Antoine MOREL
** Last update Wed Jun  1 19:15:09 2016 Dylan Deu
*/

#include	<unistd.h>
#include	"actions.h"
#include	"library.h"
#include	"cd.h"

void		mysh_actions(t_list *list, t_shell *shell)
{
  bool		status;

  status = 0;
  if (my_strcmp(list->cmd[0], "exit") == 0)
    status = my_exit(list->cmd, shell);
  else if (my_strcmp(list->cmd[0], "env") == 0)
    put_env(shell->env);
  else if (my_strcmp(list->cmd[0], "cd") == 0)
    status = cd(shell, list->cmd);
  else if (my_strcmp(list->cmd[0], "setenv") == 0 && list->cmd)
    status = set_env(shell->env, list->cmd[1], list->cmd[2]);
  else if (my_strcmp(list->cmd[0], "unsetenv") == 0)
    unset_env(shell->env, list->cmd);
  else if (my_strcmp(list->cmd[0], "history") == 0 && list->cmd)
    history(shell->history, list->cmd);
  else if (present_here(list->cmd) == 0)
    exec_here(list->cmd, shell);
  else if (present_on_cp(list->cmd, shell->env) == 0)
    exec_cmd(list->cmd, shell->env);
  else
    {
      shell->exit_status = 1;
      write(2, list->cmd[0], my_strlen(list->cmd[0]));
      write(2, ": Command not found.\n", 21);
    }
}
