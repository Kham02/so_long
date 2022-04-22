/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:49:33 by estrong           #+#    #+#             */
/*   Updated: 2022/04/22 19:17:31 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	n;
	char	*dst;
	char	*src;

	i = 0;
	dst = (char *)haystack;
	src = (char *)needle;
	if (!*src)
		return ((char *) &haystack[i]);
	while (dst[i] && i < len)
	{
		n = 0;
		while (src[n] == dst[i + n] && i + n < len)
		{
			if (src[n + 1] == '\0')
				return ((char *) &dst[i]);
			n++;
		}
		i++;
	}
	return (NULL);
}
