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
	u_int64_t	die_time;

	start = get_time();
	die_time = get_time_last_eat(philo) + philo->table->time_to_die;
	while (1)
	{
		if (die_time < get_time())
			return (1);
		else if (get_time() >= start + time)
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
		while (i < table->n_philo)
		{
			if (get_time() - get_time_last_eat(&philo[i]) > table->time_to_die)
			{
				set_end_flag(table, 1);
				if (philo[i].cnt_eat < table->n_eat_end || table->n_eat_end < 0)
					printf("%llu %d is died\n", (get_time() - table->start_time)
						, philo[i].philo_no);
				break ;
			}
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
	int	i;

	table->start_time = get_time();
	i = 0;
	while (i < table->n_philo)
	{
		table->philo[i].time_last_eat = table->start_time;
		i++;
	}
	pthread_mutex_unlock(&table->watch);
	usleep(table->n_philo * 10);
	monitoring(table);
	wait_thread(table);
}