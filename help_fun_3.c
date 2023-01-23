/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_fun_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouabda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 21:30:48 by hbouabda          #+#    #+#             */
/*   Updated: 2023/01/23 19:09:38 by hbouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_invalid_el(t_mlx *vars)
{
	int	i;
	int	j;

	i = -1;
	while (vars->map[++i])
	{
		j = -1;
		while (vars->map[i][++j])
		{
			if (vars->map[i][j] != '1' && vars->map[i][j] != '0'
				&& vars->map[i][j] != 'C' && vars->map[i][j] != 'E'
				&& vars->map[i][j] != 'P')
			{
				free_matrix(vars->map);
				free(vars->tab_el);
				write(1, "Error\nmap invalide 4!\n", 22);
				exit(1);
			}
		}
	}
}

void	flood_fill(t_mlx *vars, int x, int y, int *tab)
{
	if (x >= vars->l || x < 0 || y >= vars->c || y < 0)
		return ;
	if (vars->map[x][y] != 'P' && vars->map[x][y] != 'C'
		&& vars->map[x][y] != 'E' && vars->map[x][y] != '0')
		return ;
	if (vars->map[x][y] == 'P' && ++(tab[0]))
		vars->map[x][y] = 'p';
	else if (vars->map[x][y] == 'E' && ++(tab[1]))
		vars->map[x][y] = 'e';
	else if (vars->map[x][y] == 'C' && ++(tab[2]))
		vars->map[x][y] = 'c';
	else if (vars->map[x][y] == '0')
		vars->map[x][y] = 'g';
	flood_fill(vars, x - 1, y, tab);
	flood_fill(vars, x + 1, y, tab);
	flood_fill(vars, x, y - 1, tab);
	flood_fill(vars, x, y + 1, tab);
}

t_mlx	*is_map_valid(char **argv)
{
	t_mlx	*vars;
	int		*tab;

	vars = malloc(sizeof(t_mlx));
	check_map_size(vars, argv[1]);
	check_map_elements(vars);
	check_map_boundaries(vars);
	check_map_invalid_el(vars);
	tab = ft_calloc(sizeof(int), 4);
	player_pos(vars);
	flood_fill(vars, vars->p_x, vars->p_y, tab);
	if (tab[0] != vars->tab_el[0] || tab[1] != vars->tab_el[1]
		|| tab[2] != vars->tab_el[2])
	{
		free_matrix(vars->map);
		free(vars->tab_el);
		write(1, "Error\nmap invalide 5!\n", 22);
		free(tab);
		exit(1);
	}
	free(tab);
	return (vars);
}

void	player_pos(t_mlx *vars)
{
	int	i;
	int	j;

	i = -1;
	while (vars->map[++i])
	{
		j = -1;
		while (vars->map[i][++j])
		{
			if (vars->map[i][j] == 'P')
			{
				vars->p_x = i;
				vars->p_y = j;
				return ;
			}
		}
	}
}
