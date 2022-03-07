NAME	=	minishell

HEADER	=	./headers/minishell.h

SRCS	=	./srcs/minishell.c\
			./signals/signals.c\
			./redirfiles/check_files_utils.c\
			./redirfiles/check_files.c\
			./redirfiles/init_pipe.c\
			./redirfiles/redir_all.c\
			./parsing/delempty.c\
			./parsing/handle_msh.c\
			./parsing/handle_quotes_utils.c\
			./parsing/handle_quotes.c\
			./parsing/init_files.c\
			./parsing/init_msh.c\
			./parsing/parse_all_error.c\
			./parsing/parse_all_utils_var.c\
			./parsing/parse_all.c\
			./parsing/splitline_check.c\
			./parsing/splitline_is_next.c\
			./parsing/splitline.c\
			./parsing/tmp_get_var_quotes.c\
			./parsing/tmp_get_var.c\
			./parsing/tmp_var_utils.c\
			./parsing/tmp_var.c\
			./parsing/var_heredoc.c\
			./parsing/var_loop.c\
			./parsing/var.c\
			./heredoc/heredoc_utils.c\
			./heredoc/init_heredoc.c\
			./free/free_all.c\
			./free/free_env.c\
			./free/free_msh.c\
			./exe/close.c\
			./exe/exe_all.c\
			./exe/exe_btn_redir.c\
			./exe/exe_btn.c\
			./exe/exe_cmd.c\
			./exe/path_utils.c\
			./env/get_env.c\
			./env/parsing_env.c\
			./builtin/btn_cd_back.c\
			./builtin/btn_cd.c\
			./builtin/btn_echo.c\
			./builtin/btn_env.c\
			./builtin/btn_exit_too_big.c\
			./builtin/btn_exit.c\
			./builtin/btn_export_empty_utils.c\
			./builtin/btn_export_empty.c\
			./builtin/btn_export.c\
			./builtin/btn_pwd.c\
			./builtin/btn_unset.c\
			./builtin/is_btn.c\
			./lib/ft_atoi.c\
			./lib/ft_itoa.c\
			./lib/ft_calloc.c\
			./lib/ft_is_digit.c\
			./lib/ft_list_to_tab.c\
			./lib/ft_duptwotab.c\
			./lib/ft_free_twochar.c\
			./lib/ft_charset.c\
			./lib/ft_memset.c\
			./lib/ft_memcpy.c\
			./lib/ft_newarray.c\
			./lib/ft_printarray.c\
			./lib/ft_putstr_fd.c\
			./lib/ft_strcat.c\
			./lib/ft_strlcat.c\
			./lib/ft_strjoin.c\
			./lib/ft_strjoinmore.c\
			./lib/ft_strlcpy.c\
			./lib/ft_strcmp.c\
			./lib/ft_strlen.c\
			./lib/ft_strdup.c\
			./lib/ft_split.c\

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

SANFLAG	=	-fsanitize=address

OBJ		=	$(SRCS:.c=.o)

.PHONY:		all
all:		$(NAME)

%.o:%.c
			$(CC) -g -c -o $@ $< $c $(CFLAGS)

$(NAME):	$(OBJ) $(HEADER)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -lreadline

.PHONY:		clean
clean:
			$(RM) $(OBJ)

.PHONY:		fclean
fclean:		clean
			$(RM) $(NAME) heredoc_*

.PHONY:		re
re:			fclean all

.PHONY:		san
san:		fclean all
			$(CC) $(CFLAGS) $(SANFLAG) -o $(NAME) $(OBJ) -lreadline