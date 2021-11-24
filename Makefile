NAME	=	minishell
HEADER	=	./headers/minishell.h
SRCS	=	./srcs/*.c \
			./lib/*.c
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