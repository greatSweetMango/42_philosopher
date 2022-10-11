NAME		= philo

LIBFT		= libft

INCLUDE    	= include

MANDATORYDIR= ./

CC			= gcc
CFLAGS		= -g -Wall -Werror -Wextra -g3 -fsanitize=thread
RM			= rm -rf
AR			= ar rcs

FILES 		= philo.c			\
				philo_utils.c	\
				ft_lib.c		\
				task_check.c	\
				philo_routine.c	\
				print_message.c	\
				philo_do.c		\
				task_mutex.c	\
				task_end.c

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