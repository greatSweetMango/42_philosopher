/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:50:40 by jaehyuki          #+#    #+#             */
/*   Updated: 2022/09/07 18:50:41 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*monitoring(t_philo *philo)
{
	t_table	*table;

	table = philo->table;
	while (1)
	{
		sem_wait(table->watch);
		if (table->end_flag)
		{
			sem_post(table->watch);
			break ;
		}
		if (!table->end_flag
			&& get_time() - philo->time_last_eat > table->time_to_die)
		{
			print_message(philo, MSG_DIE, get_time());
			table->end_flag = 1;
		}
		sem_post(table->watch);
		sleep(50);
	}
	return (NULL);
}

void	*philo_routine(t_philo *philo)
{
	int	*join_rv;

	pthread_create(&philo->thread_monitor, NULL, &monitoring, philo->table);
	if (philo->philo_no % 2 == 0)
		usleep((philo->table->time_to_eat / 2) * 50);
	while (1)
	{
		if (philo->cnt_eat >= philo->table->n_eat_end
			&& philo->table->n_eat_end != -1)
			break;
		if (get_end_flag(table))
			break ;
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	pthread_join(philo->thread_monitor, NULL, &join_rv);
	exit(0);
}