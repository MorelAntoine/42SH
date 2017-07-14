/*
** exit_waterfall.c for 42sh in /home/dylan/Documents/PSU/PSU_2015_42sh/src/system/index_actions
** 
** Made by Dylan Deu
** Login   <deu_d@epitech.net>
** 
** Started on  Fri Jun  3 18:56:23 2016 Dylan Deu
** Last update Fri Jun  3 19:02:27 2016 Dylan Deu
*/

#include	<sys/types.h>
#include	<sys/wait.h>
#include	<unistd.h>
#include	"shell.h"
#include	"actions.h"
#include	"bool.h"

bool		exit_waterfall(t_shell *shell, pid_t pid, int status[4], int fd[2])
{
  waitpid(pid, &status[0], WCONTINUED);
  status[0] = get_invalid_status(shell, status[0], status[3]);
  close(fd[0]);
  return (FALSE);
}
