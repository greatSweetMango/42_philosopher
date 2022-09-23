/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 14:27:59 by jaehyuki          #+#    #+#             */
/*   Updated: 2022/09/14 14:28:00 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_end_flag(t_table *table, int n)
{
	pthread_mutex_lock(&table->m_table);
	table->end_flag = n;
	pthread_mutex_unlock(&table->m_table);
}

int		get_end_flag(t_table *table)
{
	pthread_mutex_lock(&table->m_table);
	if (table->end_flag)
	{
		pthread_mutex_unlock(&table->m_table);
		return (1);
	}
	pthread_mutex_unlock(&table->m_table);
	return (0);
}

void	set_is_die(t_philo *philo, int n)
{
	pthread_mutex_lock(&philo->m_philo);
	philo->is_die = n;
	pthread_mutex_unlock(&philo->m_philo);
}

int	get_is_die(t_philo *philo)
{
	pthread_mutex_lock(&philo->m_philo);
	if (philo->is_die)
	{
		pthread_mutex_unlock(&philo->m_philo);
		return (1);
	}
	pthread_mutex_unlock(&philo->m_philo);
	return (0);
}