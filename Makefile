NAME	=	minishell
HEADER	=	./headers/minishell.h
SRCS	=	./srcs/minishell.c
CC		=	GCC
CFLAGS	=	-Wall -Wextra -Werror
SANFLAG	=	-fsanaitize=address -g
OBJ		=	$(SRCS:.c=.o)

%.o:	%.c	$(HEADER)
		$(CC) -c -o $@ $< $c $(FLAGS)

.PHONY:	all
all		$(NAME)

.PHONY:	clean
clean:
		$(RM) $(OBJ)

.PHONY:	fclean
fclean:	clean
		$(RM) $(NAME)

.PHONY:	re
re:		clean all

.PHONY:	san
san:	re
		$(NAME) $(SANFLAG)