NAME = ft_printf.a

SRCS = 	ft_numfunc.c \
		ft_printf.c  \
		ft_strfunc.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf 
AR = ar -rcs

MAKEFLAGS += --silent

$(NAME): $(OBJS)
		$(AR) $(NAME) $(OBJS)

all : $(NAME)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re