NAME		= mcu

CORE		= 	main.c \
				memory_infrastructure.c \
				write.c \
				read.c \

SRCS        = $(addprefix srcs/, $(CORE))

CFLAGS		= -Wall -Wextra -Werror
OBJECTS 	= $(SRCS:.c=.o)
INC			= ./includes/mcu.h

#colors
RESET		= \033[m
RED         = \033[1;31m
GREEN       = \033[01;38;05;46m
YELLOW      = \033[01;38;05;226m
BLUE        = \033[03;38;05;21m
VIOLET      = \033[01;38;05;201m
CYAN        = \033[1;36m
WHITE       = \033[01;38;05;15m

all: $(NAME)

$(NAME): $(OBJECTS) $(INC)
	@ gcc $(CFLAGS) -I $(INC) $(SRCS) -o $(NAME)
	@ echo  "$(GREEN)Compilation$(RESET)\c)"
	@ echo  "$(YELLOW) : OK$(RESET)"

$(OBJECTS): %.o: %.c
	@ gcc -c $(CFLAGS) $< -o $@

clean:
	@ rm -f $(OBJECTS)

fclean: clean
	@ rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re