/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <sum@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 22:59:59 by sum               #+#    #+#             */
/*   Updated: 2023/06/01 15:25:19 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long long	timestamp(void)
{
	struct timeval	te;
	long long		microtime;

	gettimeofday(&te, NULL);
	microtime = te.tv_sec * 1000LL + te.tv_usec / 1000;
	return (microtime);
}

void	ft_usleep(int time)
{
	long long	now;

	now = timestamp();
	while (timestamp() < now + time)
		usleep(500);
}

int	check_done(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&data->meal);
	if (data->done)
		i = 1;
	pthread_mutex_unlock(&data->meal);
	return (i);
}

int	check_full(t_philo *philo)
{
	if (philo->data->num_must_eat == 0)
		return (1);
	if (philo->ate == philo->data->num_must_eat)
		return (1);
	return (0);
}

void	print_status(t_philo *philo, char *status)
{
	pthread_mutex_lock(&philo->data->printing);
	if (!check_done(philo->data))
	{
		printf(GREEN "%lldms " RESET, timestamp() - philo->data->time_started);
		printf("%d ", philo->id);
		if (ft_strcmp(status, "is eating") == 0)
			printf("%s"BLUE " (%d)\n" RESET, status, philo->ate + 1);
		else
			printf("%s\n", status);
	}
	else if (check_done(philo->data) && ft_strcmp(status, "died") == 0)
	{
		printf(GREEN "%lldms " RESET, timestamp() - philo->data->time_started);
		printf("%d ", philo->id);
		printf(RED "%s\n"RESET, status);
	}
	pthread_mutex_unlock(&philo->data->printing);
}
