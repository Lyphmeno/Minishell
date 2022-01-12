NAME	=	minishell

HEADER	=	./headers/minishell.h

SRCS	=	./srcs/minishell.c\
			./srcs/static.c\
			./builtin/btn_echo.c\
			./builtin/btn_pwd.c\
			./builtin/btn_env.c\
			./builtin/btn_export.c\
			./builtin/btn_unset.c\
			./env/get_env.c\
			./env/parsing_env.c\
			./lib/ft_calloc.c\
			./lib/ft_charset.c\
			./lib/ft_memset.c\
			./lib/ft_memcpy.c\
			./lib/ft_newarray.c\
			./lib/ft_strlcpy.c\
			./lib/ft_strcmp.c\
			./lib/ft_strlen.c\
			./lib/ft_strdup.c\
			# ./srcs/parsing.c\
			# ./lib/ft_lst_count_occur.c\
			# ./lib/ft_lst_elem_join.c\
			# ./lib/ft_lst_free_elem.c\
			# ./lib/ft_lst_add_bot.c\
			# ./lib/ft_lst_add_top.c\
			# ./lib/ft_lst_before_last.c\
			# ./lib/ft_lst_free.c\
			# ./lib/ft_lst_last_elem.c\
			# ./lib/ft_lst_new_elem.c\
			# ./lib/ft_lstlen.c\
			# ./lib/ft_lst_show.c\
			# ./lib/ft_lst_join.c\
			#./lib/ft_split.c\

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
			$(RM) $(NAME)

.PHONY:		re
re:			fclean all

.PHONY:		san
san:		fclean all
			$(CC) $(CFLAGS) $(SANFLAG) -o $(NAME) $(OBJ) -lreadline