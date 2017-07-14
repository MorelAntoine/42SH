/*
** core_shell.c for 42sh in Documents/annee_1/semestre_2/unix/PSU_2015_42sh/src/system
**
** Made by Antoine MOREL
** Login   <morel_j@epitech.net>
**
** Started on  Fri May 20 10:34:59 2016 Antoine MOREL
** Last update Sat Jun  4 17:00:18 2016 Dylan Deu
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"bool.h"
#include	"shell.h"
#include	"system.h"
#include	"parsing.h"
#include	"library.h"
#include	"error.h"
#include	"actions.h"

static bool	crossroads(t_list *list, t_shell *shell, bool status)
{
  if (list->index == NOTHING || list->index == AMPERSAND
      || list->index == D_PIPE)
    status = my_fork(list, shell, 0);
  else if (list->index == S_PIPE)
    status = do_pipe(list, shell);
  else if (list->index == S_LEFT)
    status = do_s_left(list, shell, FALSE);
  else if (list->index == S_RIGHT)
    status = do_s_right(list, shell);
  else if (list->index == D_LEFT)
    status = do_d_left(list, shell);
  else if (list->index == D_RIGHT)
    status = do_d_right(list, shell);
  return (status);
}

static int	get_link(t_list *tmp)
{
  int		linker;

  linker = 0;
  if (tmp->index == AMPERSAND)
    linker = 1;
  else if (tmp->index == D_PIPE)
    linker = 2;
  return (linker);
}

static bool	airport(t_ctrl *ctrl, t_shell *shell, int linker, bool status)
{
  t_list	*tmp;

  if ((tmp = ctrl->first) != NULL)
    {
      while (tmp != NULL)
	{
	  if ((status == FALSE && linker == 1) || (status == TRUE && linker == 2))
	    linker = 0;
	  else
	    status = crossroads(tmp, shell, status);
	  if (status == TRUE_EXIT || status == FALSE_CHILD)
	    return (status);
	  linker = 0;
	  while (tmp != NULL && tmp->index != 0 && tmp->index != AMPERSAND
		 && tmp->index != D_PIPE)
	    tmp = tmp->next;
	  if (tmp == NULL)
	    return (TRUE);
	  linker = get_link(tmp);
	  if (tmp != NULL)
	    tmp = tmp->next;
	}
    }
  return (TRUE);
}

static bool	get_child_status(t_shell *shell)
{
  shell->exit_status = 1;
  return (FALSE_CHILD);
}

bool		core_shell(t_shell *shell, char *str)
{
  t_ctrl	*ctrl;
  bool		status;
  char		*cmd_history;

  status = TRUE;
  if (check_neighbors(str) == TRUE || !(shell->exit_status = 1))
    {
      if (is_history_cmd_search(str))
	{
	  if ((cmd_history = exec_history(shell->history, str)))
	    return (core_shell(shell, cmd_history));
	  return (TRUE);
	}
      shell->history = add_in_history(shell->history, str);
      if ((ctrl = store_cmds(str, shell)) == NULL)
	return (FALSE);
      if (good_following(ctrl, shell) == TRUE)
	status = airport(ctrl, shell, 0, TRUE);
      free_list(ctrl);
      if (status == TRUE_EXIT)
	return (FALSE);
      if (status == FALSE_CHILD)
	return (get_child_status(shell));
    }
  return (TRUE);
}
