/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task_sem_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:23:06 by jaehyuki          #+#    #+#             */
/*   Updated: 2022/10/26 16:23:07 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	get_end_flag(t_table *table)
{
	sem_wait(table->watch);
	if (table->end_flag)
	{
		sem_post(table->watch);
		return (1);
	}
	else
	{
		sem_post(table->watch);
		return (0);
	}
}
