/*
** parsing.c for 42sh in Documents/annee_1/semestre_2/unix/PSU_2015_42sh/src/system/parsing
**
** Made by Antoine MOREL
** Login   <morel_j@epitech.net>
**
** Started on  Fri May 20 10:43:43 2016 Antoine MOREL
** Last update Sat Jun  4 17:00:40 2016 Dylan Deu
*/

#include	<string.h>
#include	"bool.h"
#include	"system.h"
#include	"parsing.h"
#include	"error.h"

bool		error_parsing(char context, int token, char *cmd)
{
  if (context == 1 && (token == S_LEFT || token == D_LEFT
		       || token == S_RIGHT || token == D_RIGHT))
    put_error(PARSING_REDIR_MISS);
  else if (context == 1)
    put_error(PARSING_NULL_CMD);
  else if (context == 2)
    put_error(PARSING_NULL_CMD);
  else if (context == 3)
    {
      put_error(cmd);
      put_error(PARSING_CMD_NOT_FOUND);
    }
  else
    put_error(PARSING_INVALID_CMD);
  return (FALSE);
}

bool		is_token(char *str, int *index, int *previous_token)
{
  if (str[*index] == '>' && str[*index + 1] == '>' && (*index += 1))
    *previous_token = D_RIGHT;
  else if (str[*index] == '>')
    *previous_token = S_RIGHT;
  else if (str[*index] == '<' && str[*index + 1] == '<' && (*index += 1))
    *previous_token = D_LEFT;
  else if (str[*index] == '<')
    *previous_token = S_LEFT;
  else if (str[*index] == '|' && str[*index + 1] == '|' && (*index += 1))
    *previous_token = D_PIPE;
  else if (str[*index] == '|')
    *previous_token = S_PIPE;
  else if (str[*index] == '&' && str[*index + 1] == '&' && (*index += 1))
    *previous_token = AMPERSAND;
  else if (str[*index] == '&')
    *previous_token = S_AMPERSAND;
  else if ((*previous_token = NOTHING) == NOTHING)
    return (FALSE);
  return (TRUE);
}

static bool	check_tokens(char *str, int *index, int *quotes, int *token)
{
  int	previous;

  previous = *token;
  if (str[*index] != ' ' && str[*index] != '\t' && *quotes == 0
      && is_token(str, index, token))
    {
      if (previous == -1)
	{
	  if (*token == S_LEFT || *token == D_LEFT
	      || *token == S_RIGHT || *token == D_RIGHT)
	    return (TRUE);
	  return (error_parsing(2, *token, str));
	}
      if (previous != NOTHING)
	return (error_parsing(2, *token, str));
    }
  return (TRUE);
}

bool		check_neighbors(char *str)
{
  int		index;
  int		quotes;
  int		previous_token;

  index = 0;
  quotes = 0;
  previous_token = -1;
  while (index < (int)strlen(str) && str[index])
    {
      if (is_valid_quote(&str, index))
	{
	  if (quotes == 0)
	    quotes = str[index];
	  else if (quotes == str[index])
	    quotes = 0;
	}
      else if (str[index] == ';' && quotes == 0)
	previous_token = -1;
      else if (!check_tokens(str, &index, &quotes, &previous_token))
	return (FALSE);
      index++;
    }
  if (previous_token != NOTHING && previous_token != -1)
    return (error_parsing(1, previous_token, str));
  return (TRUE);
}
