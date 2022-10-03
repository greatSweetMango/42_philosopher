/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:37:40 by jaehyuki          #+#    #+#             */
/*   Updated: 2022/09/12 16:37:41 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_message(t_philo *philo, int message_type,
					u_int64_t time)
{
	t_table *table;

	table = philo->table;
	pthread_mutex_lock(&table->watch);
	if (get_end_flag(table))
	{
		printf("phlio %d: 읍읍!!!%d\n", philo->philo_no, message_type);
		pthread_mutex_unlock(&table->watch);
		return (1);
	}
	if (message_type == MSG_EAT)
		printf("%llu %d is eating\n", (time - table->start_time)
				, philo->philo_no);
	else if (message_type == MSG_SLEEP)
		printf("%llu %d is sleeping\n", (time - table->start_time)
				, philo->philo_no);
	else if (message_type == MSG_THINK)
		printf("%llu %d is thinking\n", (time - table->start_time)
				, philo->philo_no);
	else if (message_type == MSG_GREP_FORK)
		printf("%llu %d has taken a fork\n", (time - table->start_time)
				, philo->philo_no);
	pthread_mutex_unlock(&table->watch);
	return (1);
}