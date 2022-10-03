/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:18:42 by jaehyuki          #+#    #+#             */
/*   Updated: 2022/09/06 17:18:44 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# define EATING 1
# define SLEEPING 2
# define THINKING 3

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

	pthread_mutex_t m_philo;
	pthread_mutex_t *right_fork;
	pthread_mutex_t *left_fork;
	pthread_t		thread_philo;
	struct s_table	*table;
}	t_philo;

typedef struct s_table
{
	int				n_philo;
	u_int64_t		time_to_die;
	u_int64_t		time_to_eat;
	u_int64_t		time_to_sleep;
	int				n_eat_end;
	u_int64_t		start_time;
	int				end_flag;
	
	pthread_mutex_t	*fork;
	pthread_mutex_t m_table;
	pthread_mutex_t	watch;
	t_philo			*philo;
}	t_table;

typedef struct timeval t_timeval;

int	check_args(int argc, char **argv);

//libft
int		ft_atoi(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *s);

//philo_routine
void	*philo_routine(void	*philo);

void	start_table(t_table *table);

//get_time
u_int64_t	get_time(void);

//philo_do
int	philo_eat(t_philo *philo);
int	philo_sleep(t_philo *philo);
int	philo_think(t_philo *philo);

//printf_message
int	print_message(t_philo *philo, char *message_type,
					u_int64_t time);

//philo_utils
int		sleep_loop(t_philo *philo, u_int64_t time);
int		init_fork(t_table *table, t_philo *philo);

//task_mutex
void	set_end_flag(t_table *table, int n);
int		get_end_flag(t_table *table);
void	set_time_last_eat(t_philo *philo, u_int64_t time);
u_int64_t	get_time_last_eat(t_philo *philo);

//task_end
void	task_end(t_table *table);

void	one_philo(u_int64_t	time);

#endif