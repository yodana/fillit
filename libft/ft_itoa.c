/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:59:40 by yodana            #+#    #+#             */
/*   Updated: 2018/11/26 16:42:50 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_create(int size, int n, int neg)
{
	char *new;

	if (!(new = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	new[size] = '\0';
	size--;
	while (size >= 0)
	{
		new[size] = (n % 10) + '0';
		if (size == 0 && neg == 1)
			new[size] = '-';
		n = n / 10;
		size--;
	}
	return (new);
}

char		*ft_itoa(int n)
{
	int i;
	int size;
	int neg;

	neg = 0;
	size = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
	{
		n = n * -1;
		neg = 1;
		size++;
	}
	i = n;
	while (i > 0)
	{
		i = i / 10;
		size++;
	}
	return (ft_create(size, n, neg));
}
