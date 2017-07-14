/*
** special_redir.c for 42sh in Documents/annee_1/semestre_2/unix/PSU_2015_42sh/src/system
**
** Made by Antoine MOREL
** Login   <morel_j@epitech.net>
**
** Started on  Mon May 30 17:38:40 2016 Antoine MOREL
** Last update Sat Jun  4 17:01:14 2016 Dylan Deu
*/

#include	<stdlib.h>
#include 	<string.h>
#include	"system.h"
#include	"library.h"

static char	*get_first(char *cmd, int *cpt)
{
  char		*tmp;

  if ((tmp = malloc(sizeof(char))) == NULL)
    return (NULL);
  tmp[0] = '\0';
  while (*cpt < (int)strlen(cmd) &&
	 (cmd[(*cpt)] == ' ' || cmd[(*cpt)] == '\t'))
    (*cpt)++;
  while (*cpt < (int)strlen(cmd) &&
	 (cmd[(*cpt)] != ' ' && cmd[(*cpt)] != '\t'))
    {
      if ((tmp = my_str_charconcat(tmp, cmd[(*cpt)])) == NULL)
	return (NULL);
      (*cpt)++;
    }
  return (tmp);
}

static char	*get_second(char *cmd, int *cpt)
{
  char		*tmp;

  if ((tmp = malloc(sizeof(char))) == NULL)
    return (NULL);
  tmp[0] = '\0';
  while (cmd[(*cpt)] == ' ' || cmd[(*cpt)] == '\t')
    (*cpt)++;
  while (cmd[(*cpt)] != '\0')
    {
      if ((tmp = my_str_charconcat(tmp, cmd[(*cpt)])) == NULL)
	return (NULL);
      (*cpt)++;
    }
  return (tmp);
}

int		special_redir(char *str, t_ctrl *ctrl, int cpt, char f_idx)
{
  char		*cmd;
  char		index;
  char		*first;
  char		*second;

  if (!(cmd = get_cmd(str)))
    return (0);
  f_idx = get_index(str, &cpt);
  if ((first = get_first(cmd, &cpt)) == NULL)
    return (0);
  if ((second = get_second(cmd, &cpt)) == NULL)
    return (0);
  index = get_index(str, &cpt);
  cpt = (index == D_LEFT || index == D_RIGHT || index == D_PIPE
	 || index == AMPERSAND ? cpt + 2 : cpt + 1);
  if (cmd[0] != '\0')
    ctrl = epur_and_add_store(second, ctrl, f_idx, NULL);
  if (cmd[0] != '\0')
    ctrl = epur_and_add_store(first, ctrl, index, NULL);
  free(first);
  free(second);
  free(cmd);
  return (cpt);
}
