/*
** error.c for PSU_2015_42sh in C:/Users/geoff/OneDrive - Epitech/Geof/rendu/PSU_2015_42sh
**
** Made by Geoffrey Davril
** Login   <davril_g@epitech.net>
**
** Started on  Thu May 19 14:05:28 2016 Geoffrey Davril
** Last update Thu May 19 14:05:28 2016 Geoffrey Davril
*/

#include	<unistd.h>
#include	<string.h>
#include	"bool.h"

bool		put_error(char *msg)
{
  write(2, msg, strlen(msg));
  return (FALSE);
}
