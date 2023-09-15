/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkargs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramedjra <ramedjra@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:20:02 by ramedjra          #+#    #+#             */
/*   Updated: 2023/09/13 18:02:39 by ramedjra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static int	ft_is_numeric(char const *str)
{
	int	i;

	i = 0;
	if (*str == '+')
		str++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '\0')
		return (TRUE);
	return (FALSE);
}

int	ft_check_args(int ac, char const *const *av)
{
	if (ac < 5)
	{
		printf ("Error: Too few arguments.\n %s", ARGS_INPUT);
		return (FAILURE);
	}
	if (ac > 6)
	{
		printf ("Error: Too many arguments.\n %s", ARGS_INPUT);
		return (FAILURE);
	}
	while (ac-- > 1)
	{
		if (ft_is_numeric (av[ac]) == FALSE)
		{
			write (2, "Error: Invalid character.\n", 26);
			return (FAILURE);
		}
		if (ft_atol (av[ac]) > INT_MAX || ft_atol (av[ac]) < 0)
		{
			write (2, "Error: Out of range value.\n", 27);
			return (FAILURE);
		}
	}
	return (SUCCESS);
}
