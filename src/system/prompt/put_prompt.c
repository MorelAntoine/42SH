/*
** put_prompt.c for 42sh in Documents/annee_1/semestre_2/unix/PSU_2015_42sh/src/system/prompt
**
** Made by Antoine MOREL
** Login   <morel_j@epitech.net>
**
** Started on  Thu May 19 16:19:11 2016 Antoine MOREL
** Last update Thu May 19 16:19:11 2016 Antoine MOREL
*/

#include	<unistd.h>
#include 	<string.h>
#include	"prompt.h"

void		put_prompt(t_prompt *prompt)
{
  if (prompt->select)
    write(1, ">", 1);
  else
    write(1, prompt->display, strlen(prompt->display));
}
