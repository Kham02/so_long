/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:08:34 by estrong           #+#    #+#             */
/*   Updated: 2022/03/11 12:03:45 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		n;

	i = 0;
	if (!s1)
		return (NULL);
	if (!set)
		return ((char *)s1);
	n = ft_strlen(s1) - 1;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while ((n > -1) && ft_strchr(set, s1[n]))
		n--;
	n = n - i;
	if (n < 0)
		return (ft_strdup(""));
	str = ft_substr(s1, i, n + 1);
	return (str);
}
