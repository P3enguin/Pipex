/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:47:31 by ybensell          #+#    #+#             */
/*   Updated: 2022/01/12 10:32:21 by ybensell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	char	*p1;
	char	*p2;
	int				i;

	i = 0;
	p1 = s1;
	p2 = s2;
	while ((p1[i] != '\0' || p2[i] != '\0') && i < n)
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		i++;
	}
	return (0);
}