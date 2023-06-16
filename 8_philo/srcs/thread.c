/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <sum@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 22:45:45 by sum               #+#    #+#             */
/*   Updated: 2023/06/16 16:15:47 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(1000 * philo->data->time_to_eat);
	while (!check_done(philo->data) && !check_full(philo))
	{
		if (!pickup_fork(philo))
			break ;
		eating(philo);
		if (check_full(philo))
			break ;
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}

void	*monitor(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	i = 0;
	while (!check_done(data))
	{
		if (timestamp() - data->philo[i].last_eat > data->time_to_die
			&& data->philo[i].ate != data->num_must_eat)
		{
			pthread_mutex_lock(&data->meal);
			data->done = 1;
			pthread_mutex_unlock(&data->meal);
			print_status(&data->philo[i], "died");
			break ;
		}
		meal_finished(data);
		i = (i + 1) % data->num_philo;
	}
	return (NULL);
}
