/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <sum@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 22:43:48 by sum               #+#    #+#             */
/*   Updated: 2023/05/30 22:21:48 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	init_thread(t_data *data)
{
	int	num;

	num = data->num_philo;
	while (--num >= 0)
		pthread_mutex_init(&data->fork[num], NULL);
	num = data->num_philo;
	while (--num >= 0)
		pthread_create(&data->thread_id[num], NULL, routine, &data->philo[num]);
	pthread_create(&data->monitor, NULL, monitor, data);
	num = data->num_philo;
	while (--num >= 0)
		pthread_join(data->thread_id[num], NULL);
	pthread_join(data->monitor, NULL);
}

void	init_philo(t_philo *philo, t_data *data)
{
	int	num;

	num = data->num_philo;
	while (--num >= 0)
	{
		philo[num].id = num + 1;
		philo[num].left = num;
		philo[num].right = (num + 1) % data->num_philo;
		philo[num].ate = 0;
		philo[num].data = data;
		philo[num].last_eat = timestamp();
	}
}

void	init_data(t_data *data)
{
	data->time_started = timestamp();
	data->philo = (t_philo *)malloc(sizeof(t_philo) * data->num_philo);
	data->thread_id = (pthread_t *)malloc(sizeof(pthread_t) * data->num_philo);
	data->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
			* data->num_philo);
	pthread_mutex_init(&data->printing, NULL);
	pthread_mutex_init(&data->meal, NULL);
	init_philo(data->philo, data);
}
