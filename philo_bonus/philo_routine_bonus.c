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

#include "philo.h"

void	*philo_routine(t_philo *philo)
{
	if (philo->philo_no % 2 == 0)
		usleep((philo->table->time_to_eat / 2) * 800 + 500);
	while (1)
	{
		if (philo->cnt_eat >= philo->table->n_eat_end
			&& philo->table->n_eat_end != -1)
			while(1)
			;
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}