/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramedjra <ramedjra@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:20:50 by ramedjra          #+#    #+#             */
/*   Updated: 2023/09/13 17:41:17 by ramedjra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

unsigned long	ft_abs_time(void)
{
	struct timeval	time;
	unsigned long	s;
	unsigned long	u;

	if (gettimeofday (&time, NULL) == -1)
		printf("Error: GETTIMEOFDAY(2)\n");
	s = time.tv_sec * 1000;
	u = time.tv_usec / 1000;
	return (s + u);
}

unsigned long	ft_rel_time(unsigned long begin)
{
	unsigned long	abs_time;

	abs_time = ft_abs_time ();
	return (abs_time - begin);
}

void	ft_msleep(unsigned long msec)
{
	usleep (msec * 100);
	usleep (msec * 100);
	usleep (msec * 100);
	usleep (msec * 100);
	usleep (msec * 100);
	usleep (msec * 100);
	usleep (msec * 100);
	usleep (msec * 100);
	usleep (msec * 100);
	usleep (msec * 100);
}
