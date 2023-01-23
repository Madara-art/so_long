/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_fun_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouabda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 19:42:05 by hbouabda          #+#    #+#             */
/*   Updated: 2023/01/22 21:22:19 by hbouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*p;
	size_t			tot;

	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	p = malloc(size * count);
	if (p)
	{
		tot = count * size;
		while (tot--)
			*(p + tot) = 0;
	}
	return (p);
}

void	replace_char(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			str[i] = 0;
		i++;
	}
}

void	apply_replace_char_to_map(t_mlx *vars)
{
	int	i;

	i = 0;
	while (vars->map[i])
	{
		replace_char(vars->map[i++], '\n');
	}
}

char	**read_map(char *path)
{
	int		fd;
	char	*s;
	int		cnt;
	char	**matrix;

	cnt = 0;
	fd = open(path, O_RDONLY);
	s = get_next_line(fd);
	while (s)
	{
		free(s);
		s = get_next_line(fd);
		cnt++;
	}
	close(fd);
	fd = open(path, O_RDONLY);
	matrix = ft_calloc(sizeof(char *), ++cnt);
	cnt = 0;
	matrix[cnt] = get_next_line(fd);
	while (matrix[cnt++])
		matrix[cnt] = get_next_line(fd);
	close(fd);
	return (matrix);
}

size_t	ft_strlen(const char *str)
{
	size_t	l;

	l = 0;
	while (str[l])
		l++;
	return (l);
}
