/*
** get_next_line.h for 42sh in Documents/annee_1/semestre_2/unix/PSU_2015_42sh/include
**
** Made by Antoine MOREL
** Login   <morel_j@epitech.net>
**
** Started on  Sun Jun 05 10:47:35 2016 Antoine MOREL
** Last update Sun Jun 05 10:47:35 2016 Antoine MOREL
*/

#ifndef		GET_NEXT_LINE_H_
# define	GET_NEXT_LINE_H_

# ifndef	READ_SIZE
#  define	READ_SIZE (4096)
# endif		/* !READ_SIZE */

char		*get_next_line(const int fd);

typedef	struct	s_gnl
{
  char		*str;
  int		i;
  int		j;
  int		final;
}		t_gnl;

typedef	struct	s_read
{
  int		ret;
  char		buffer[READ_SIZE];
  int		i;
  int		stop;
}		t_read;

#endif		/* !GET_NEXT_LINE_H_ */
