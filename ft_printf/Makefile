SRCS =  ft_printf.c ft_printchar.c ft_printnbr.c ft_printstr.c ft_strlen.c ft_printpercent.c ft_printunsigned.c ft_printhexa.c ft_putchar_fd.c ft_printptr.c

OBJS = ${SRCS:.c=.o}
NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
CC = gcc

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all : ${NAME}

${NAME}: ${OBJS}
	ar -rcs ${NAME} ${OBJS}
clean: 
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all