/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <sum@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 22:36:47 by sum               #+#    #+#             */
/*   Updated: 2023/06/16 16:15:41 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	pickup_fork(t_philo *philo)
{
	if (philo->data->num_philo == 1)
	{	
		pthread_mutex_lock(&philo->data->fork[philo->right]);
		print_status(philo, "has taken a fork");
		pthread_mutex_unlock(&philo->data->fork[philo->left]);
		return (0);
	}
	if (philo->data->num_philo % 2 == 1 && philo->id == 2)
		usleep(1000);
	if (&philo->data->fork[philo->left] > &philo->data->fork[philo->right])
	{	
		pthread_mutex_lock(&philo->data->fork[philo->right]);
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(&philo->data->fork[philo->left]);
		print_status(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(&philo->data->fork[philo->left]);
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(&philo->data->fork[philo->right]);
		print_status(philo, "has taken a fork");
	}
	return (1);
}

void	putdown_fork(t_philo *philo, int left, int right)
{
	pthread_mutex_unlock(&philo->data->fork[right]);
	pthread_mutex_unlock(&philo->data->fork[left]);
}

void	eating(t_philo *philo)
{
	print_status(philo, "is eating");
	pthread_mutex_lock(&philo->data->meal);
	philo->last_eat = timestamp();
	pthread_mutex_unlock(&philo->data->meal);
	ft_usleep(philo->data->time_to_eat);
	putdown_fork(philo, philo->left, philo->right);
	pthread_mutex_lock(&philo->data->meal);
	if (++philo->ate == philo->data->num_must_eat)
		philo->data->ate_done++;
	pthread_mutex_unlock(&philo->data->meal);
}

void	sleeping(t_philo *philo)
{
	print_status(philo, "is sleeping");
	ft_usleep(philo->data->time_to_sleep);
}

void	thinking(t_philo *philo)
{
	print_status(philo, "is thinking");
}
