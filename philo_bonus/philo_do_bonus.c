/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_do_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:28:07 by jaehyuki          #+#    #+#             */
/*   Updated: 2022/09/12 11:28:10 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	grep_fork(t_philo *philo)
{
	t_table	*table;

	table = philo->table;
	sem_wait(table->fork);
	print_message(philo, MSG_GREP_FORK, get_time());
	sem_wait(table->fork);
	print_message(philo, MSG_GREP_FORK, get_time());
}

int	philo_eat(t_philo *philo)
{
	t_table		*table;
	u_int64_t	time;

	table = philo->table;
	grep_fork(philo);
	time = get_time();
	philo->time_last_eat = time;
	print_message(philo, MSG_EAT, time);
	sleep_loop(philo, table->time_to_eat);
	philo->cnt_eat++;
	sem_post(table->fork);
	sem_post(table->fork);
	return (0);
}

int	philo_sleep(t_philo *philo)
{
	t_table		*table;
	u_int64_t	time;

	table = philo->table;
	time = get_time();
	print_message(philo, MSG_SLEEP, time);
	sleep_loop(philo, table->time_to_sleep);
	return (0);
}

int	philo_think(t_philo *philo)
{
	print_message(philo, MSG_THINK, get_time());
	usleep(600);
	return (0);
}