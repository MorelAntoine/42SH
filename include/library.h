/*
** library.h for 42sh in Documents/annee_1/semestre_2/unix/PSU_2015_42sh/include
**
** Made by Antoine MOREL
** Login   <morel_j@epitech.net>
**
** Started on  Thu May 19 11:30:15 2016 Antoine MOREL
** Last update Mon May 30 13:39:40 2016 Dylan Deu
*/

#ifndef		LIBRARY_H_
# define	LIBRARY_H_

# include	"bool.h"

/*
** STRING
*/
char		*my_strdup(char *str);
char		*my_strncpy(char *str, int n);
char		*my_strconcat(char *a, char *b);
char		*my_str_charconcat(char *src, char c);
bool		same_str(char *a, char *b);
bool		str_contains(char *content, char *str);
char		*my_strcat(char *dest, char *src);
int		my_strcmp(char *s1, char *s2);
int		my_strlen(char *str);
bool		same_str_begin(char *begin, char *str);
bool		is_not_separator(const char c);

/*
** ARRAY
*/
char		**my_str_to_wordtab(char *str, char sep);
void		print_board(char **board);
void		free_board(char **board);
char		**clone_board(char **board);

/*
** ERROR
*/
bool		put_error(char *msg);

/*
** NUMBER
*/
bool		is_number(char *s);
int		my_getnbr(char *nb);

#endif		/* !LIBRARY_H_ */
