/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 19:28:21 by jaehyuki          #+#    #+#             */
/*   Updated: 2022/09/06 19:28:22 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_fork(t_table *table, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < table->n_philo)
	{
		if(pthread_mutex_init(&table->fork[i], 0) < 0)
			return (0);
		i++;
	}
	i = 0;
	while (i < table->n_philo)
	{
		if(i == 0)
			philo[i].left_fork = &table->fork[table->n_philo - 1];
		else
			philo[i].left_fork = &table->fork[i - 1];
		philo[i].right_fork = &table->fork[i];
		if (pthread_mutex_init(&philo[i].m_philo, 0) < 0)
			return (0);
		i++;
	}
	return (1);
}

int	sleep_loop(t_philo *philo, u_int64_t time)
{
	u_int64_t	start;

	start = get_time();
	while (1)
	{
		if (philo->time_last_eat + philo->table->time_to_die
			< get_time())
			return (1);
		else if (get_time() > start + time)
			return (0);
		usleep(100);
	}
}

u_int64_t	get_time(void)
{
	t_timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	monitoring(t_table *table)
{
	int		i;
	t_philo *philo;

	philo = table->philo;
	while (!get_end_flag(table))
	{
		pthread_mutex_lock(&table->watch);
		i = 0;
		while (i < table->n_philo && table->started_philo >= table->n_philo)
		{
			pthread_mutex_lock(&philo[i].m_philo);
			if (get_time() - philo[i].time_last_eat > table->time_to_die)
			{
				printf("%llu %d is died\n", (get_time() - table->start_time)
				, philo[i].philo_no);
				set_end_flag(table, 1);
				pthread_mutex_unlock(&philo[i].m_philo);
				break ;
			}
			pthread_mutex_unlock(&philo[i].m_philo);
			i++;
		}
		pthread_mutex_unlock(&table->watch);
		usleep(100);
	}
}

void	wait_thread(t_table *table)
{
	int	i;
	int joinrv;

	i = 0;
	while (i < table->n_philo)
	{
		pthread_join(table->philo[i].thread_philo, (void **)&joinrv);
		i++;
	}
}

void	start_table(t_table *table)
{

	pthread_mutex_lock(&table->m_table);
	table->start_time = get_time();
	pthread_mutex_unlock(&table->m_table);
	pthread_mutex_unlock(&table->watch);
	monitoring(table);
	wait_thread(table);
}