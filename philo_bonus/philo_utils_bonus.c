/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 19:28:21 by jaehyuki          #+#    #+#             */
/*   Updated: 2022/09/06 19:28:22 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	sleep_loop(t_philo *philo, u_int64_t time)
{
	u_int64_t	start;
	u_int64_t	die_time;
	
	start = get_time();
	die_time = philo->time_last_eat + philo->table->time_to_die;
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
