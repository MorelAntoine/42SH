/*
** exit.c for PSU_2015_42sh in C:/Users/geoff/OneDrive - Epitech/Geof/rendu/PSU_2015_42sh
**
** Made by Geoffrey Davril
** Login   <davril_g@epitech.net>
**
** Started on  Thu May 19 14:30:21 2016 Geoffrey Davril
** Last update Sun Jun  5 08:59:33 2016 Dylan Deu
*/

#include	<stdlib.h>
#include	"shell.h"
#include	"bool.h"
#include	"library.h"

bool		my_exit(char **cmd, t_shell *shell)
{
  if (cmd[1] == NULL)
    return (TRUE_EXIT);
  else if (cmd[2] != NULL)
    {
      put_error("exit: Expression Syntax.\n");
      return (FALSE);
    }
  if (!is_number(cmd[1]))
    {
      put_error("exit: Expression Syntax.\n");
      return (FALSE);
    }
  shell->exit_status = (unsigned char)(my_getnbr(cmd[1]) % 256);
  return (TRUE_EXIT);
}
