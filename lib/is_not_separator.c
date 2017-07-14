/*
** is_alpha.c for 42sh in /home/dylan/Documents/PSU/PSU_2015_42sh/src
** 
** Made by Dylan Deu
** Login   <deu_d@epitech.net>
** 
** Started on  Mon May 30 13:33:42 2016 Dylan Deu
** Last update Mon May 30 13:37:04 2016 Dylan Deu
*/

#include	"bool.h"

bool		is_not_separator(const char c)
{
  if (c == '&' || c == '|' || c == '>' || c == '<')
    return (FALSE);
  return (TRUE);
}
