/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiski <amiski@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 20:55:43 by amiski            #+#    #+#             */
/*   Updated: 2022/09/08 20:55:44 by amiski           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosohers.h"

int	ft_atoi(const char *str)
{
	int	rus;
	int	sign;
	int	i;

	i = 0;
	sign = 1;
	rus = 0;
	while (str[i] <= 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		rus = (rus * 10) + ((int)str[i] - '0');
		i++;
	}	
	return (sign * rus);
}