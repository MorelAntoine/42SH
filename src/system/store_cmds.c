/*
** store_cmds.c for 42sh in Documents/annee_1/semestre_2/unix/PSU_2015_42sh/src/system
**
** Made by Antoine MOREL
** Login   <morel_j@epitech.net>
**
** Started on  Fri May 20 11:31:51 2016 Antoine MOREL
** Last update Sat Jun  4 17:01:54 2016 Dylan Deu
*/

#include	<stdlib.h>
#include 	<string.h>
#include	"bool.h"
#include	"library.h"
#include	"system.h"

bool		end_of_get(char *str, int index)
{
  static int	s_quote = 0;
  static int	d_quote = 0;

  if (is_valid_quote(&str, index) == FALSE)
    return ((s_quote == 0 && d_quote == 0 ? TRUE : FALSE));
  else if (is_valid_quote(&str, index) == FALSE)
    return ((s_quote == 0 && d_quote == 0 ? TRUE : FALSE));
  if (s_quote == 1 && str[index] == '\'')
    s_quote = 0;
  else if (s_quote == 0 && str[index] == '\'' && d_quote == 0)
    s_quote = 1;
  else if (d_quote == 1 && str[index] == '"')
    d_quote = 0;
  else if (s_quote == 0 && str[index] == '"'  && d_quote == 0)
    d_quote = 1;
  return ((s_quote == 0 && d_quote == 0 ? TRUE : FALSE));
}

char		*get_cmd(char *str)
{
  static int	i = 0;
  char		*cmd;

  if (str == NULL || str[i] == '\0')
    {
      i = 0;
      return (NULL);
    }
  if ((cmd = malloc(sizeof(char))) == NULL)
    return (NULL);
  cmd[0] = '\0';
  while (str[i] == '|' || str[i] == '<' || str[i] == '>'
	 || str[i] == ';' || str[i] == '&')
    i++;
  while (str[i] != '\0')
    {
      if (end_of_get(str, i) == TRUE)
	if (str[i] == '|' || str[i] == '<' || str[i] == '>'
	    || str[i] == ';' || str[i] == '&')
	  return (cmd);
      if ((cmd = my_str_charconcat(cmd, str[i])) == NULL)
	return (NULL);
      i++;
    }
  return (cmd);
}

char		get_index(char *str, int *i)
{
  while (str && *i < (int)strlen(str) && str[(*i)] && str[(*i)] == ';')
    (*i)++;
  while (*i < (int)strlen(str))
    {
      while (end_of_get(str, (*i)) == FALSE)
	(*i)++;
      if (str[(*i)] == '|' && str[(*i) + 1] == '|')
	return (D_PIPE);
      else if (str[(*i)] == '|')
	return (S_PIPE);
      else if (str[(*i)] == '&' && str[(*i) + 1] == '&')
	return (AMPERSAND);
      else if (str[(*i)] == '>' && str[(*i) + 1] == '>')
	return (D_RIGHT);
      else if (str[(*i)] == '<' && str[(*i) + 1] == '<')
	return (D_LEFT);
      else if (str[(*i)] == '>')
	return (S_RIGHT);
      else if (str[(*i)] == '<')
	return (S_LEFT);
      else if (str[(*i)] == ';')
	return (NOTHING);
      (*i)++;
    }
  return (NOTHING);
}

t_ctrl		*epur_and_add_store(char *cmd, t_ctrl *ctrl, char index,
				    t_env *env)
{
  char		**board;
  int		index_board;

  index_board = 0;
  if ((board = my_str_to_wordtab_quote(cmd, ' ')) != NULL)
    {
      while (board[index_board])
	{
	  if (env != NULL && board[index_board] != NULL)
	    {
	      if (!(board[index_board] = global_var(board[index_board], env, NULL)))
		return (ctrl);
	    }
	  delete_backslash_cmd(board + index_board++);
	}
      ctrl = add_end(ctrl, board, index);
    }
  return (ctrl);
}

t_ctrl		*store_cmds(char *str, t_shell *shell)
{
  t_ctrl	*ctrl;
  char		*cmd;
  char		index;
  int		cpt;

  if ((ctrl = set_ctrl()) == NULL)
    {
      shell->exit_status = 1;
      return (NULL);
    }
  cpt = (str[0] == '<' || str[0] == '>') ? special_redir(str, ctrl, 0, 0) : 0;
  while ((cmd = get_cmd(str)) != NULL)
    {
      index = get_index(str, &cpt);
      cpt = (index == D_LEFT || index == D_RIGHT || index == D_PIPE
	     || index == AMPERSAND ? cpt + 2 : cpt + 1);
      if (cmd[0] != '\0')
	ctrl = epur_and_add_store(cmd, ctrl, index, shell->env);
      if (ctrl == NULL)
	return (NULL);
      free(cmd);
    }
  return (ctrl);
}
