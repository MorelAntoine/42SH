/*
** mainloop.c for 42sh in Documents/annee_1/semestre_2/unix/PSU_2015_42sh/src/system
**
** Made by Antoine MOREL
** Login   <morel_j@epitech.net>
**
** Started on  Thu May 19 15:42:31 2016 Antoine MOREL
** Last update Fri Jun  3 15:42:14 2016 Dylan Deu
*/

#include	<stdlib.h>
#include	<signal.h>
#include	<unistd.h>
#include	"shell.h"
#include	"system.h"
#include	"bool.h"
#include	"library.h"
#include	"get_next_line.h"

bool		g_is_sigint;
pid_t		g_cur_child_pid;

bool		is_valid_quote(char **full_str, int index)
{
  int		nb_antishlah;

  if (index >= my_strlen(*full_str) || !full_str[0][index] ||
      (full_str[0][index] != '\'' && full_str[0][index] != '"'))
    return (FALSE);
  index--;
  nb_antishlah = 0;
  while (index != -1 && full_str[0][index] == '\\')
    {
      nb_antishlah++;
      index--;
    }
  if (nb_antishlah % 2)
    return (FALSE);
  return (TRUE);
}

static bool	analyze_command_quotes(t_shell *sh, char *str, char **full_str)
{
  int		index;
  int		quote;
  char		*tmp;

  signal(SIGCHLD, SIG_DFL);
  tmp = *full_str;
  if (*full_str != NULL && (*full_str = my_strconcat(*full_str, "\n")))
    free(tmp);
  tmp = *full_str;
  *full_str = my_strconcat(*full_str, str);
  free(tmp);
  quote = 0;
  index = 0;
  while (full_str[0][index])
    {
      if (quote == 0 && is_valid_quote(full_str, index))
	quote = full_str[0][index];
      else if (full_str[0][index] == quote && is_valid_quote(full_str, index))
	quote = 0;
      index++;
    }
  if (quote == 0 && !(sh->prompt->select = FALSE))
    return (TRUE);
  sh->prompt->select = TRUE;
  return (FALSE);
}

void		mainloop(t_shell *shell)
{
  bool		stay;
  char		*str;
  char		*full_str;

  stay = TRUE;
  full_str = NULL;
  while (stay == TRUE)
    {
      put_prompt(shell->prompt);
      if ((str = get_next_line(0)) != NULL)
	{
	  if (analyze_command_quotes(shell, str, &full_str) == TRUE)
	    {
	      stay = core_shell(shell, full_str);
	      free(full_str);
	      full_str = NULL;
	    }
	  free(str);
	}
      else
	stay = (g_is_sigint == TRUE ? TRUE : FALSE);
      g_is_sigint = FALSE;
    }
  if (stay == FALSE)
    write(1, "exit\n", 5);
}
