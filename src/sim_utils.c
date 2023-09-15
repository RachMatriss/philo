/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramedjra <ramedjra@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:20:28 by ramedjra          #+#    #+#             */
/*   Updated: 2023/09/13 17:15:46 by ramedjra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_print(t_philo *philo, char const *const a)
{
	pthread_mutex_lock (&philo->data->mutex[PRINT]);
	if (*a == 'd' || (!ft_check_died (philo) && !ft_check_done (philo)))
		printf("%lu %d %s\n", ft_rel_time(philo->data->simbegin), philo->id, a);
	pthread_mutex_unlock (&philo->data->mutex[PRINT]);
}

void	ft_died(t_data *data)
{
	pthread_mutex_lock (&data->mutex[DIED]);
	data->died = TRUE;
	pthread_mutex_unlock (&data->mutex[DIED]);
}

void	ft_done(t_data *data)
{
	pthread_mutex_lock (&data->mutex[DONE]);
	data->done = TRUE;
	pthread_mutex_unlock (&data->mutex[DONE]);
}

int	ft_check_died(t_philo *philo)
{
	pthread_mutex_lock (&philo->data->mutex[DIED]);
	if (philo->data->died)
	{
		pthread_mutex_unlock (&philo->data->mutex[DIED]);
		return (TRUE);
	}
	pthread_mutex_unlock (&philo->data->mutex[DIED]);
	return (FALSE);
}

int	ft_check_done(t_philo *philo)
{
	pthread_mutex_lock (&philo->data->mutex[DONE]);
	if (philo->data->done)
	{
		pthread_mutex_unlock (&philo->data->mutex[DONE]);
		return (TRUE);
	}
	pthread_mutex_unlock (&philo->data->mutex[DONE]);
	return (FALSE);
}
