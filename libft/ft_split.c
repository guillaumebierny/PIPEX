/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <gbierny@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 20:12:09 by gbierny           #+#    #+#             */
/*   Updated: 2022/01/26 21:01:28 by gbierny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	int		i;
	size_t	n_word;

	i = -1;
	n_word = 0;
	if (s[0] != c)
		n_word++;
	while (s[++i])
	{
		if (s[i] == c && (s[i + 1] != c && s[i + 1] != '\0'))
			n_word++;
	}
	return (n_word);
}

static size_t	set_size_words(const char *s, char c, size_t n_word)
{
	int		i;
	size_t	j;

	i = -1;
	if (s[0] != c)
		n_word--;
	while (s[++i] && n_word)
	{
		if (s[i] == c && (s[i + 1] != c && s[i + 1] != '\0'))
		{
			n_word--;
		}
	}
	if (n_word <= 0)
	{
		j = 1;
		while ((s + i)[j] != c && (s + i)[j] != 0)
			j++;
		return (j + 1);
	}
	return (0);
}

static char	*put_string(const char *s, char c, size_t n_word, char *split)
{
	int	i;
	int	j;
	int	t;

	t = 0;
	i = -1;
	j = 0;
	if (s[0] != c && n_word != 0)
		n_word--;
	while (s[++i] && n_word != 0)
	{
		if (s[i] == c && (s[i + 1] != c && s[i + 1] != 0))
			n_word--;
	}
	j = i;
	while (s[j] != c && s[j] && n_word == 0)
	{
		split[t++] = s[j];
		j++;
	}
	split[t] = '\0';
	return (split);
}

static char	**column_part(char **split, char c, const char *s, size_t n_word)
{
	size_t	t;
	size_t	i;

	i = 0;
	t = 0;
	while (n_word > 0)
	{
		split[i] = (char *)malloc(sizeof(char) * set_size_words(s, c, i + 1));
		if (!split[i])
		{
			while (split[t])
				free(split[t++]);
			free(split);
			return (NULL);
		}
		split[i] = put_string(s, c, i + 1, split[i]);
		n_word--;
		i++;
	}
	split[i] = 0;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	size_t	n_word;
	char	**split;

	if (!s)
		return (NULL);
	if (s[0] == 0)
		return ((char **)ft_calloc(1, sizeof(char *)));
	n_word = (size_t)count_words(s, c);
	split = (char **)malloc((n_word + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	split[n_word] = NULL;
	split = column_part(split, c, s, n_word);
	return (split);
}
