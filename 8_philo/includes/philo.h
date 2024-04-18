/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <sum@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:21:53 by sum               #+#    #+#             */
/*   Updated: 2023/05/30 22:21:48 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <string.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <time.h>

# define RED		"\x1b[31m"
# define GREEN		"\x1b[32m"
# define BLUE		"\x1b[34m"
# define RESET		"\x1b[0m"

typedef struct s_philo{
	int					id;
	int					left;
	int					right;
	int					ate;
	long long			last_eat;
	struct s_data		*data;
}	t_philo;

typedef struct s_data{
	t_philo				*philo;
	int					num_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					num_must_eat;
	int					done;
	int					ate_done;
	long long			time_started;
	pthread_t			*thread_id;
	pthread_t			monitor;
	pthread_mutex_t		printing;
	pthread_mutex_t		meal;
	pthread_mutex_t		*fork;
}	t_data;

int			check_done(t_data *data);
int			check_full(t_philo *philo);

int			check_valid(char *str);
int			ft_strcmp(const char *s1, const char *s2);
long long	ft_atoi_long(char *str);
long long	timestamp(void);
void		error_free(void);
void		ft_usleep(int time);

void		init_thread(t_data *data);
void		init_philo(t_philo *philo, t_data *data);
void		init_data(t_data *data);

void		*monitor(void *arg);
void		*routine(void *arg);

int			pickup_fork(t_philo *philo);
void		putdown_fork(t_philo *philo, int left, int right);
void		eating(t_philo *philo);
void		sleeping(t_philo *philo);
void		thinking(t_philo *philo);

void		meal_finished(t_data *data);
void		print_status(t_philo *philo, char *status);

#endif
