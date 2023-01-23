/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_fun_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouabda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:01:13 by hbouabda          #+#    #+#             */
/*   Updated: 2023/01/22 23:00:52 by hbouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_size(t_mlx *vars, char *path)
{
	int		i;
	size_t	cnt;

	vars->map = read_map(path);
	apply_replace_char_to_map(vars);
	i = 0;
	cnt = 0;
	if (vars->map[i])
		cnt = ft_strlen(vars->map[i++]);
	while (vars->map[i])
	{
		if (cnt != ft_strlen(vars->map[i]))
		{
			write(1, "map invalide 1!\n", 16);
			free_matrix(vars->map);
			exit(1);
		}
		cnt = ft_strlen(vars->map[i++]);
	}
	vars->c = cnt;
	vars->l = i;
}

void	check_map_elements(t_mlx *vars)
{
	int	i;
	int	j;

	i = -1;
	vars->tab_el = ft_calloc(4, sizeof(int));
	while (vars->map[++i])
	{
		j = -1;
		while (vars->map[i][++j])
		{
			if (vars->map[i][j] == 'P')
				vars->tab_el[0]++;
			if (vars->map[i][j] == 'E')
				vars->tab_el[1]++;
			if (vars->map[i][j] == 'C')
				vars->tab_el[2]++;
		}
	}
	if (vars->tab_el[0] != 1 || vars->tab_el[1] != 1 || vars->tab_el[1] == 0)
	{
		free_matrix(vars->map);
		free(vars->tab_el);
		write(1, "Error\nmap invalide 2!\n", 22);
		exit(1);
	}
}

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
}

void	check_map_boundaries(t_mlx *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			if ((vars->map[i][j] != '1') && (!i || !vars->map[i + 1] || !j
					|| !vars->map[i][j + 1]))
			{
				write(1, "map invalide 3!\n", 16);
				free_matrix(vars->map);
				free(vars->tab_el);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (dst || src)
	{
		i = -1;
		while (++i < n)
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
	}
	return (dst);
}
