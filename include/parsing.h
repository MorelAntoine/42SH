/*
** parsing.h for 42sh in Documents/annee_1/semestre_2/unix/PSU_2015_42sh/include
**
** Made by Antoine MOREL
** Login   <morel_j@epitech.net>
**
** Started on  Fri May 20 10:53:04 2016 Antoine MOREL
** Last update Fri May 20 10:53:04 2016 Antoine MOREL
*/

#ifndef		PARSING_H_
# define	PARSING_H_

#include	"bool.h"

# define	PARSING_NULL_CMD	("Invalid null command.\n")
# define	PARSING_REDIR_MISS	("Missing name for redirect.\n")
# define	PARSING_INVALID_CMD	("Invalid command.\n")
# define	PARSING_CMD_NOT_FOUND	(": Command not found.\n")

bool		check_neighbors(char *str);

#endif		/* !PARSING_H_ */
