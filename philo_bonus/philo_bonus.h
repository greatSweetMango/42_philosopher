
#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <pthread.h>
# include <semaphore.h>
# include <fcntl.h>

# define MSG_DIE "is die"
# define MSG_EAT "is eating"
# define MSG_SLEEP "is sleeping"
# define MSG_THINK "is thinking"
# define MSG_GREP_FORK "has taken a fork"

typedef struct s_philo
{
	int			philo_no;
	u_int64_t	time_last_eat;
	int			cnt_eat;
	pid_t		pid;
	pthread_t	thread_monitor;
	struct s_table	*table;
}	t_philo;


typedef struct s_table
{
	int				n_philo;
	int				started_philo;//??
	u_int64_t		time_to_die;
	u_int64_t		time_to_eat;
	u_int64_t		time_to_sleep;
	int				n_eat_end;
	u_int64_t		start_time;
	int				end_flag;
	sem_t			*fork;
	sem_t			*watch;
	sem_t			*talk;
	t_philo			*philo;
}	t_table;

//libft
int		ft_atoi(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *s);
#endif