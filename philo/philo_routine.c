/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:50:40 by jaehyuki          #+#    #+#             */
/*   Updated: 2022/09/07 18:50:41 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_watch(t_table *table, t_philo *philo)
{
	pthread_mutex_lock(&table->watch);
	pthread_mutex_unlock(&table->watch);
	usleep(philo->philo_no);
	if (philo->philo_no % 2 == 0)
		usleep(100);
}

void	*philo_routine(void *arg)
{
	t_philo			*philo;

	philo = (t_philo *)arg;
	wait_watch(philo->table, philo);
	if (philo->philo_no % 2 == 0)
		usleep(900);
	philo->time_last_eat = philo->table->start_time;
	while (1)
	{
		if (philo->cnt_eat >= philo->table->n_eat_end
			&& philo->table->n_eat_end != -1)
			break;
		if (get_end_flag(philo->table) || philo_eat(philo))
			break ;
		if (get_end_flag(philo->table) || philo_sleep(philo))
			break ;
		if (get_end_flag(philo->table) || philo_think(philo))
			break ;
	}
	return (NULL);
}