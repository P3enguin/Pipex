/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 08:58:54 by ybensell          #+#    #+#             */
/*   Updated: 2022/01/14 13:07:50 by ybensell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

static int	words_numb(const char *s, char c)
{
	int	i;

	i = 0;
	while (*s != '\0')
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			i++;
		s++;
	}
	return (i);
}

static int	word_size(const char *s, char c)
{
	int	i;

	i = 0;
	while (*(s + i) != '\0' && *(s + i) != c)
	{
		i++;
	}
	return (i);
}

static char	*fill_str(char *lil_str, const char *s, char c)
{
	int	i;

	i = 0;
	while (*s != '\0' && *s != c)
	{
		*(lil_str + i) = *s;
		i++;
		s++;
	}
	*(lil_str + i) = '\0';
	return (lil_str);
}

static void	*free_f(char **str, int i)
{
	while (i >= 0)
	{
		free(str + i);
		i--;
	}
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		words;

	if (s == NULL)
		return (NULL);
	words = words_numb(s, c);
	tab = (char **)malloc(sizeof(char *) * (words + 1));
	if (tab == 0)
		return (NULL);
	i = 0;
	while (i < words)
	{
		while (*s == c && *s)
			s++;
		*(tab + i) = (char *)malloc(sizeof(char) * (word_size((s), c) + 1));
		if (*(tab + i) == 0)
			return (free_f(tab, i));
		fill_str(*(tab + i), s, c);
		while (*s != c && *s)
			s++;
		i++;
	}
	*(tab + i) = 0;
	return (tab);
}
