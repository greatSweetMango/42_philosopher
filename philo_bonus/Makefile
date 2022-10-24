NAME		= philo_bonus

LIBFT		= libft

INCLUDE    	= include

MANDATORYDIR= ./

CC			= gcc
CFLAGS		= -g -Wall -Werror -Wextra
FWS			= -framework OpenGL -framework AppKit
RM			= rm -rf
AR			= ar rcs

FILES 		= philo_bonus.c				\
				philo_utils_bonus.c		\
				ft_lib.c				\
				philo_routine_bonus.c	\
				philo_do_bonus.c		\
				print_message_bonus.c

SRCS		= $(addprefix $(MANDATORYDIR), $(FILES))

OBJS		= $(SRCS:.c=.o)

$(MANDATORYDIR)%.o: $(MANDATORYDIR)%.c
			$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDE)
			
all		: $(NAME)

$(NAME) : $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -I $(INCLUDE)
clean	:
			$(RM) $(OBJS)

fclean	: clean
			$(RM) $(NAME)

re		: fclean all

.PHONY:		all clean fclean re