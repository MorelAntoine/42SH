##
## Makefile for 42sh in /home/maires_b/Dropbox/PSU_2015_42sh/
##
## Made by Baptiste Mairesse (maires_b)
## Login   <maires_b@epitech.eu>
##
## Started on  Tue May 17 14:50:00 2016 Baptiste Mairesse (maires_b)
## Last update Fri Jun  3 19:00:18 2016 Dylan Deu
##

DEBUG		=		no

CC		=		clang $(INC)

RM		=		rm -f

EXEC		=		42sh

INC		=		-I./include/

LIB		=		lib/board_tools.c		\
				lib/get_next_line.c		\
				lib/str_cpy.c			\
				lib/str_cmp.c			\
				lib/nb.c			\
				lib/my_str_charconcat.c		\
				lib/my_str_to_wordtab.c		\
				lib/error.c			\
				lib/is_not_separator.c

SRC		=		src/main.c					\
				src/env/env.c					\
				src/env/unset_env.c				\
				src/system/core_shell.c				\
				src/system/store_cmds.c				\
				src/system/good_following.c			\
				src/system/special_redir.c			\
				src/system/my_str_to_wordtab_quote.c		\
				src/system/global_var.c				\
				src/system/exec/exec_here.c			\
				src/system/exec/exec_systems.c			\
				src/system/exec/mysh_actions.c			\
				src/system/exec/present_on_cp.c			\
				src/system/index_actions/do_d_left.c		\
				src/system/index_actions/do_d_right.c		\
				src/system/index_actions/do_pipe.c		\
				src/system/index_actions/do_pipe_next.c		\
				src/system/index_actions/do_s_left.c		\
				src/system/index_actions/do_s_right.c		\
				src/system/index_actions/my_fork.c		\
				src/system/index_actions/exit_waterfall.c	\
				src/system/initialization/shell.c		\
				src/system/initialization/env_settings.c	\
				src/system/linked_lists/add_end.c		\
				src/system/linked_lists/free_list.c		\
				src/system/linked_lists/set_ctrl.c		\
				src/system/parsing/parsing.c			\
				src/system/parsing/delete_backslash_cmd.c	\
				src/system/prompt/prompt_settings.c		\
				src/system/prompt/put_prompt.c			\
				src/system/mainloop.c				\
				src/job_control/job_control_settings.c		\
				src/job_control/kill_child.c			\
				src/job_control/jobs.c				\
				src/history/history_settings.c			\
				src/history/history_manage.c			\
				src/history/history_get.c			\
				src/builtins/cd.c				\
				src/builtins/echo.c				\
				src/builtins/exit.c				\
				$(LIB)

OBJS		=		$(SRC:.c=.o)

OBJSLIB		=		$(LIB:.c=.o)

ifeq ($(DEBUG),yes)
	CFLAGS = -W -Wall -Wextra -ansi -pedantic -Werror -g -ggdb3
	LDFLAGS = -lm
else
	CFLAGS = -W -Wall -Wextra -ansi -pedantic -Werror
	LDFLAGS = -lm
endif

all:				$(EXEC)
ifeq ($(DEBUG),yes)
	@echo "Génération en mode debug"
else
	@echo "Génération en mode release"
endif

$(EXEC):			$(OBJS)
				$(CC) $(OBJS) -o $(EXEC) $(LDFLAGS)

clean:
				$(RM) $(OBJS)

fclean:				clean
				$(RM) $(EXEC)

re:				fclean all
