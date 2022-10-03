#include "philo.h"

void	destory_mutex_all(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->n_philo)
	{
		pthread_mutex_destroy(&table->fork[i]);
		pthread_mutex_destroy(&table->philo[i].m_philo);
		i++;
	}
	pthread_mutex_destroy(&table->m_table);
	pthread_mutex_destroy(&table->watch);
}

void	free_all(t_table *table)
{
	free(table->fork);
	free(table->philo);
}

void	task_end(t_table *table)
{
	destory_mutex_all(table);
	free_all(table);
}