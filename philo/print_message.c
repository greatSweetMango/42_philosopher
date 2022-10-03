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

int	print_message(t_philo *philo, char *message,
					u_int64_t time)
{
	t_table *table;

	table = philo->table;
	pthread_mutex_lock(&table->watch);
	if (!get_end_flag(table))
		printf("%llu %d %s\n", (time - table->start_time)
				, philo->philo_no, message);
	pthread_mutex_unlock(&table->watch);
	//else
	//	printf("philo %d : 읍읍!!\n", philo->philo_no);
	return (1);
}