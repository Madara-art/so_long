/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_fun_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouabda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 23:15:00 by hbouabda          #+#    #+#             */
/*   Updated: 2023/01/24 01:25:50 by hbouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_input_file(char *file)
{
	int		fd;
	int		i;
	char	*ex;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		write(1, "File error!\n", 12);
		exit(1);
	}
	ex = ".ber";
	while (file[i] && file[i] != '.')
		i++;
	while (file[i] && file[i] == *(ex++))
		i++;
	if (*ex)
	{
		write(1, "File extension error!\n", 22);
		exit(1);
	}
}

void	restore_original_map(t_mlx *vars)
{
	int	i;
	int	j;

	i = -1;
	while (vars->map[++i])
	{
		j = -1;
		while (vars->map[i][++j])
		{
			if (vars->map[i][j] == 'p')
				vars->map[i][j] = 'P';
			else if (vars->map[i][j] == 'e')
				vars->map[i][j] = 'E';
			else if (vars->map[i][j] == 'c')
				vars->map[i][j] = 'C';
			else if (vars->map[i][j] == 'g')
				vars->map[i][j] = '0';
		}
	}
}

void	map_init(t_mlx *vars)
{
	vars->simg.ground = mlx_xpm_file_to_image(vars->mlx, "assets/ground.xpm",
			&(vars->simg.width), &(vars->simg.height));
	vars->simg.collectable = mlx_xpm_file_to_image(vars->mlx,
													"assets/collectible.xpm",
													&(vars->simg.width),
													&(vars->simg.height));
	vars->simg.exit = mlx_xpm_file_to_image(vars->mlx,
											"assets/exit.xpm",
											&vars->simg.width,
											&vars->simg.height);
	vars->simg.boundary = mlx_xpm_file_to_image(vars->mlx,
												"assets/boundary.xpm",
												&vars->simg.width,
												&vars->simg.height);
	vars->simg.player = mlx_xpm_file_to_image(vars->mlx,
												"assets/player.xpm",
												&vars->simg.width,
												&vars->simg.height);
}

void	help_key_hook(t_mlx *vars, int x, int y)
{
	if (vars->map[x][y] != '1' && (vars->map[x][y] != 'E' || !vars->tab_el[2]))
	{
		if (vars->map[x][y] == 'C')
			vars->tab_el[2]--;
		if (vars->map[x][y] == 'E')
			exit_fun1(vars);
		vars->map[vars->p_x][vars->p_y] = '0';
		vars->map[x][y] = 'P';
	}
}

int	key_hook(int keycode, t_mlx *vars)
{
	if (keycode == 53)
		exit_fun_er(vars);
	player_pos(vars);
	if (keycode == 1)
		help_key_hook(vars, vars->p_x + 1, vars->p_y);
	if (keycode == 0)
		help_key_hook(vars, vars->p_x, vars->p_y - 1);
	if (keycode == 2)
		help_key_hook(vars, vars->p_x, vars->p_y + 1);
	if (keycode == 13)
		help_key_hook(vars, vars->p_x - 1, vars->p_y);
	aff_map(vars);
	return (0);
}
