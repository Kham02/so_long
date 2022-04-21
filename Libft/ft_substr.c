/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 20:41:31 by estrong           #+#    #+#             */
/*   Updated: 2022/04/21 16:19:09 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	if (!s)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	str = (char *) malloc(sizeof(*str) * len + 1);
	if (!str || !s)
		return (NULL);
	while (s[i])
	{
		if (n < len && i >= start)
		{
			str[n] = s[i];
			n++;
		}
		i++;
	}
	str[n] = '\0';
	return (str);
}
