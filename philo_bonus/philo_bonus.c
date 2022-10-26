/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:40:37 by jaehyuki          #+#    #+#             */
/*   Updated: 2022/10/14 17:40:38 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
	table->watch = NULL;
	table->talk = NULL;
	table->philo = NULL;
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
		philo[i].thread_monitor = 0;
		philo[i].cnt_eat = 0;
		philo[i].pid = 0;
		philo[i].table = table;
		i++;
	}
	table->philo = philo;
	return (1);
}

int	init_sem(t_table *table)
{
	sem_unlink("/fork");
	sem_unlink("/watch");
	sem_unlink("/talk");
	table->fork = sem_open("/forks", O_CREAT, S_IRWXU, table->n_philo);
	if (table->fork <= 0)
		return (0);
	table->watch = sem_open("/watch", O_CREAT, S_IRWXU, 1);
	if (table->watch <= 0)
		return (0);
	table->talk = sem_open("/talk", O_CREAT, S_IRWXU, 1);
	if (table->talk <= 0)
		return (0);
	return (1);
}

int	start_table(t_table *table)
{
	int		i;
	t_philo	*philo;

	philo = table->philo;
	table->start_time = get_time();
	i = 0;
	while (i < table->n_philo)
	{
		philo[i].pid = fork();
		if (philo[i].pid < 0)
			return (0);
		if (philo[i].pid == 0)
			philo_routine(&philo[i]);
		i++;
		usleep(50);
	}
	return (1);
}

void	end_table(t_table *table)
{
	t_philo	*philo;
	int		exit_code;
	int		i;

	philo = table->philo;
	i = -1;
	while (++i < table->n_philo)
		waitpid(philo[i].pid, &exit_code, 0);
	//할당 해제
	//세마포어 닫기
}

int	main(int argc, char **argv)
{
	t_table	table;

	if (!parse_arg(argc, argv, &table))
		return (0);
	if (!init_philo(&table))
		return (0);
	if (!init_sem(&table))
		return (0);
	if (!start_table(&table))
		return (0);////에러??
	end_table(&table);
	return (0);
}