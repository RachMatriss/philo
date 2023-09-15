/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramedjra <ramedjra@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:20:14 by ramedjra          #+#    #+#             */
/*   Updated: 2023/09/13 17:15:39 by ramedjra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static void	ft_memclear(t_philo *philo, t_data *data)
{
	if (data && data->mutex)
		free (data->mutex);
	if (data)
		free (data);
	if (philo && philo->fork)
		free (philo->fork);
	if (philo)
		free (philo);
}

static int	ft_edgecases(int ac, char const *const *av)
{
	if ((ac == 6 && ft_atol (av[5]) == 0))
		return (TRUE);
	if (ft_atol (av[1]) == 0)
		return (TRUE);
	return (FALSE);
}

int	main(int ac, char const *const *av)
{
	t_data	*data;
	t_philo	*philo;

	data = NULL;
	philo = NULL;
	if (ft_check_args (ac, av) != SUCCESS)
		return ((void)ft_memclear (philo, data), EXIT_FAILURE);
	if (ft_edgecases (ac, av))
		return ((void)ft_memclear (philo, data), EXIT_SUCCESS);
	if (ft_init (&philo, &data, ac, av) != SUCCESS)
		return ((void)ft_memclear (philo, data), EXIT_FAILURE);
	if (ft_simulator (philo, data) != SUCCESS)
		return ((void)ft_memclear (philo, data), EXIT_FAILURE);
	return ((void)ft_memclear (philo, data), EXIT_SUCCESS);
}
