/*
** prompt_settings.c for 42sh in Documents/annee_1/semestre_2/unix/PSU_2015_42sh/src/system/prompt
**
** Made by Antoine MOREL
** Login   <morel_j@epitech.net>
**
** Started on  Thu May 19 16:14:09 2016 Antoine MOREL
** Last update Tue May 24 09:31:34 2016 Baptiste Mairesse
*/

#include	<stdlib.h>
#include 	"library.h"
#include	"prompt.h"

t_prompt	*init_prompt()
{
  t_prompt	*prompt;

  if ((prompt = malloc(sizeof(t_prompt))) == NULL)
    return (NULL);
  prompt->select = FALSE;
  update_prompt(prompt);
  return (prompt);
}

void		update_prompt(t_prompt *prompt)
{
  prompt->display = my_strdup("?> ");
}

void		clean_prompt(t_prompt *prompt)
{
  if (prompt == NULL)
    return ;
  if (prompt->display)
    free(prompt->display);
  free(prompt);
}
