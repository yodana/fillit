/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:50:44 by yodana            #+#    #+#             */
/*   Updated: 2018/12/04 16:35:26 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *nptr)
{
	unsigned int		res;
	int					i;
	int					sign;

	sign = 1;
	i = 0;
	res = 0;
	while (nptr[i] == 32 || nptr[i] == '\f' || nptr[i] == '\t'
			|| nptr[i] == '\n' || nptr[i] == '\r' || nptr[i] == '\v'
				|| nptr[i] == '\a')
		i++;
	if (nptr[i] == '+')
		i++;
	if (nptr[i] == '-' && nptr[i - 1] != '+')
	{
		sign = -1;
		i++;
	}
	while (ft_isdigit((int)nptr[i]))
	{
		res = res * 10;
		res = res + (nptr[i] - '0');
		i++;
	}
	return ((int)res * sign);
}
