/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:37:40 by jaehyuki          #+#    #+#             */
/*   Updated: 2022/09/12 16:37:41 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	print_message(t_philo *philo, char *message,
					u_int64_t time)
{
	t_table *table;

	table = philo->table;
	sem_wait(table->talk);
	if (!table->end_flag)
		printf("%llu %d %s\n", (time - table->start_time)
				, philo->philo_no, message);
	sem_post(table->talk);
	return (1);
}