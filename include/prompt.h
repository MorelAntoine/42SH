/*
** prompt.h for 42sh in Documents/annee_1/semestre_2/unix/PSU_2015_42sh/include
**
** Made by Antoine MOREL
** Login   <morel_j@epitech.net>
**
** Started on  Thu May 19 16:07:06 2016 Antoine MOREL
** Last update Thu May 19 16:07:06 2016 Antoine MOREL
*/

#ifndef			PROMPT_H_
# define		PROMPT_H_

#include		"bool.h"

typedef struct		s_prompt
{
  bool			select;
  char			*display;
}			t_prompt;

t_prompt		*init_prompt();
void			update_prompt(t_prompt *prompt);
void			put_prompt(t_prompt *prompt);
void			clean_prompt(t_prompt *prompt);

#endif			/* !PROMPT_H_ */
