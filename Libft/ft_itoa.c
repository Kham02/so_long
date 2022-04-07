/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 20:08:28 by estrong           #+#    #+#             */
/*   Updated: 2022/03/11 12:04:15 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	else
	{
		while (n > 0)
		{
			n = n / 10;
			len = len + 1;
		}
	}
	return (len);
}

static char	*ft_c(char *c, int len, int n)
{
	if (n == 0)
	{
		c[0] = '0';
		return (c);
	}
	while (len--)
	{
		c[len] = n % 10 + '0';
		n = n / 10;
	}
	return (c);
}

char	*ft_itoa(int n)
{
	char	*c;
	int		len;
	int		neg;

	neg = 0;
	if (n >= 2147483647)
		return (ft_strdup("2147483647"));
	if (n <= -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		n = n * (-1);
		neg = 1;
	}
	len = ft_intlen(n);
	c = ft_calloc(len + 1 + neg, sizeof(char));
	if (!c)
		return (NULL);
	c = (ft_c(c, len + neg, n));
	if (neg > 0)
		c[0] = '-';
	return (c);
}
