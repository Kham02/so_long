/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 15:02:14 by estrong           #+#    #+#             */
/*   Updated: 2022/04/21 16:20:07 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(char *s, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

static size_t	ft_words(char *str, char c)
{
	size_t	size;
	size_t	words;

	size = 0;
	words = 0;
	while (str[size])
	{
		if (str[size] && str[size] != c)
			words++;
		while (str[size] && str[size] != c)
			size++;
		while (str[size] && str[size] == c)
			size++;
	}
	return (words);
}

static char	**ft_err(char **arr, size_t n)
{
	while (n >= 0)
		free(arr[--n]);
	free(arr);
	return (NULL);
}

static char	**ft_write_arr(char **arr, char *s, char c, size_t words)
{
	size_t	i;
	size_t	len;
	size_t	n;

	i = 0;
	n = 0;
	while (n < words)
	{
		while (s[i] == c)
			i++;
		if (s[i] != c)
		{
			len = 0;
			len = ft_len(&s[i], c);
			arr[n] = ft_substr(s, i, len);
			if (arr[n] == NULL)
				return (ft_err(arr, n));
			n++;
			i += len;
		}
	}
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	words;

	if (!s)
		return (0);
	words = ft_words((char *)s, c);
	arr = (char **) malloc(sizeof(char *) * (words + 1));
	if (!arr)
		return (NULL);
	arr = ft_write_arr(arr, (char *)s, c, words);
	arr[words] = NULL;
	return (arr);
}
