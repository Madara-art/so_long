/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_fun_5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouabda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 21:30:40 by hbouabda          #+#    #+#             */
/*   Updated: 2023/01/24 01:08:48 by hbouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	help_aff_map(t_mlx *vars, int i, int j)
{
	if (vars->map[i][j] == 'C')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->simg.collectable, j
				* vars->simg.width, i * vars->simg.height);
	if (vars->map[i][j] == 'P')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->simg.player, j
				* vars->simg.width, i * vars->simg.height);
	if (vars->map[i][j] == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->simg.boundary, j
				* vars->simg.width, i * vars->simg.height);
	if (vars->map[i][j] == '0')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->simg.ground, j
				* vars->simg.width, i * vars->simg.height);
	if (vars->map[i][j] == 'E')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->simg.exit, j
				* vars->simg.width, i * vars->simg.height);
}

void	aff_map(t_mlx *vars)
{
	int	i;
	int	j;

	i = -1;
	while (vars->map[++i])
	{
		j = -1;
		while (vars->map[i][++j])
			help_aff_map(vars, i, j);
	}
}

int	exit_fun_er(t_mlx *vars)
{
	int	i;

	i = 0;
	while (vars->map[i])
		free(vars->map[i++]);
	free(vars->map);
	free(vars->tab_el);
	write(1, "Good bye!", 9);
	exit(1);
	return (1);
}

void	exit_fun1(t_mlx *vars)
{
	int i;

	i = 0;
	while (vars->map[i])
		free(vars->map[i++]);
	free(vars->map);
	free(vars->tab_el);
	write(1, "You won!", 8);
	exit(0);
}