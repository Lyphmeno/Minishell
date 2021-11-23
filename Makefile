NAME	=	minishell
HEADER	=	./headers/minishell.h
SRCS	=	./srcs/minishell.c\
			./srcs/parsing.c\
			./srcs/static.c\
			./lib/ft_calloc.c\
			./lib/ft_memset.c\
			./lib/ft_newarray.c\
			./lib/ft_split.c\
			./lib/ft_strlcpy.c\
			./lib/ft_strlen.c
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
SANFLAG	=	-fsanitize=address -g
OBJ		=	$(SRCS:.c=.o)

%.o:	%.c	$(HEADER)
		$(CC) -c -o $@ $< $c $(CFLAGS)

.PHONY:	all
all:	$(NAME)

$(NAME):$(OBJ)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -lreadline

.PHONY:	clean
clean:
		$(RM) $(OBJ)

.PHONY:	fclean
fclean:	clean
		$(RM) $(NAME)

.PHONY:	re
re:		fclean all

.PHONY:	san
san:	fclean all
		$(CC) $(CFLAGS) $(SANFLAG) -o $(NAME) $(OBJ) -lreadline