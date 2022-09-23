/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 19:44:38 by jaehyuki          #+#    #+#             */
/*   Updated: 2022/09/06 19:44:40 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	digit_check(char *str)
{
	int	i;

	if (!ft_isdigit(str[0]) && str[0] != '-' && str[0] != '+')
	{
		ft_putstr_fd("Error(digit check)\n", 2);
		return (0);
	}
	i = 1;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			ft_putstr_fd("Error(digit check)\n", 2);
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_args(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_atoi(argv[i]) < 0)
			return (0);
		if (!digit_check(argv[i]) || !ft_strncmp(argv[i], "-", 2))
			return (0);
		i++;
	}
	return (1);
}

int	check_sommone_die(t_table *table)
{
	int	i;

	if (get_end_flag(table))
		return (1);
	i = 0;
	while (i < table->n_philo)
	{
		if (get_is_die(&table->philo[i]) == 1)
		{
			set_end_flag(table, 1);
			return (1);
		}
		i++;
	}
	return (0);
}
