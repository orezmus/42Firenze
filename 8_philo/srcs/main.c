/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <sum@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:15:43 by sum               #+#    #+#             */
/*   Updated: 2023/06/01 14:22:23 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	error_free(void)
{
	printf("Error\n");
	exit (1);
}

void	meal_finished(t_data *data)
{
	pthread_mutex_lock(&data->meal);
	if (data->ate_done == data->num_philo || data->num_must_eat == 0)
	{
		data->done = 1;
		pthread_mutex_lock(&data->printing);
		printf(GREEN "%lldms " RESET, timestamp() - data->time_started);
		printf(BLUE "All philosophers have eaten %d time(s)\n" RESET, \
			data->num_must_eat);
		pthread_mutex_unlock(&data->printing);
	}
	pthread_mutex_unlock(&data->meal);
}

int	parsing(t_data *data, int ac, char **av)
{
	int	i;

	i = 1;
	if (ac < 5 || ac > 6)
		return (0);
	while (i < ac && check_valid(av[i]))
		i++;
	data->num_philo = ft_atoi_long(av[1]);
	data->time_to_die = ft_atoi_long(av[2]);
	data->time_to_eat = ft_atoi_long(av[3]);
	data->time_to_sleep = ft_atoi_long(av[4]);
	data->done = 0;
	data->ate_done = 0;
	data->num_must_eat = -1;
	if (data->num_philo == 0)
		return (0);
	if (ac == 6)
		data->num_must_eat = ft_atoi_long(av[5]);
	return (1);
}

void	end_meal(t_data *data)
{
	int		num;

	num = data->num_philo;
	while (--num > -1)
		pthread_mutex_destroy(&data->fork[num]);
	free(data->philo);
	free(data->thread_id);
	free(data->fork);
	pthread_mutex_destroy(&data->printing);
	pthread_mutex_destroy(&data->meal);
}

int	main(int ac, char **av)
{
	t_data	data;

	memset(&data, 0, sizeof(t_data));
	if (!parsing(&data, ac, av))
		error_free();
	init_data(&data);
	init_thread(&data);
	end_meal(&data);
	return (0);
}
