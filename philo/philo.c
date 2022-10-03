/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 19:28:21 by jaehyuki          #+#    #+#             */
/*   Updated: 2022/09/06 19:28:22 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_philo_thread(t_table *table)
{
	int	i;
	t_philo	*philo;

	philo = table->philo;
	i = 0;
	while (i < table->n_philo)
	{
		pthread_create(&philo[i].thread_philo, NULL, &philo_routine, &philo[i]);
		i++;
	}
	return (1);
}

int	init_philo(t_table *table)
{
	int		i;
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo) * table->n_philo);
	if (!philo)
		return (0);
	i = 0;
	while (i < table->n_philo)
	{
		philo[i].philo_no = i + 1;
		philo[i].time_last_eat = 0;
		philo[i].thread_philo = 0;
		philo[i].table = table;
		philo[i].cnt_eat = 0;
		i++;
	}
	table->philo = philo;
	return (1);
}

int	init_mutex(t_table *table)
{
	t_philo *philo;

	philo = table->philo;
	table->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
					* table->n_philo);
	if (!init_fork(table, philo))
		return (0);
	if (pthread_mutex_init(&table->watch, 0) < 0)
		return (0);
	if (pthread_mutex_init(&table->m_table, 0) < 0)
		return (0);
	pthread_mutex_lock(&table->watch);
	return (1);
}

int	parse_arg(int argc, char **argv, t_table *table)
{
	if ((argc != 5 && argc != 6) || !check_args(argc, argv))
		return (0);
	table->n_philo = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		table->n_eat_end = ft_atoi(argv[5]);
	else
		table->n_eat_end = -1;
	table->start_time = 0;
	table->end_flag = 0;
	table->fork = NULL;
	table->philo = NULL;
	if (table->n_philo <= 0 || table->n_eat_end == 0)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_table			table;

	if (!parse_arg(argc, argv, &table))
		return (0); //////////에러함수 추가예정
	if (table.n_philo == 1)
	{
		one_philo(table.time_to_die);
		return (0);
	}
	if (!init_philo(&table))
		return (0); /////////에러함수 추가 예정
	if (!init_mutex(&table))
		return (0); /////////에러함수 추가 예정
	if (!create_philo_thread(&table))
		return (0);
	start_table(&table);
	task_end(&table);
	system("leaks philo");
	return (0);
}