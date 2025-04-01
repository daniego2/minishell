/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniego2 <daniego2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:43:28 by daniego2          #+#    #+#             */
/*   Updated: 2025/01/29 17:20:10 by daniego2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Counts words

int	word_counter(const char *s, char c)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			j++;
			while (s[i] && s[i] != c)
			{
				i++;
			}
		}
		else if (s[i] == c)
		{
			i++;
		}
	}
	return (j);
}

// Count characters

int	word_len(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		i++;
	}
	return (i);
}

// Frees the memory

void	ft_free(int i, char **ptr)
{
	while (i > 0)
	{
		i--;
		free(ptr[i]);
	}
	free(ptr);
}

// Split the array

static char	**ft_splitter(const char *s, char c, char **ptr, int words_count)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < words_count)
	{
		while (s[j] && s[j] == c)
			j++;
		ptr[i] = ft_substr(s, j, word_len(&s[j], c));
		if (!ptr[i])
		{
			ft_free(i, ptr);
			return (NULL);
		}
		while (s[j] && s[j] != c)
			j++;
		i++;
	}
	ptr[i] = NULL;
	return (ptr);
}
// Separates a string "s" into a string array composed by these strings.
// The character "c" is the delimiter. It finishes in NULL.

char	**ft_split(const char *s, char c)
{
	char	**ptr;
	int		words;

	if (!s)
	{
		return (NULL);
	}
	words = word_counter(s, c);
	ptr = (char **)malloc(sizeof(char *) * (words + 1));
	if (!ptr)
	{
		return (NULL);
	}
	ptr = ft_splitter(s, c, ptr, words);
	return (ptr);
}
