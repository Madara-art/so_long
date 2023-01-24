/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouabda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 22:38:44 by hbouabda          #+#    #+#             */
/*   Updated: 2023/01/24 01:28:01 by hbouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_mlx	*vars;

	if (argc != 2)
	{
		write(1, "invalid arguments!", 18);
		return (1);
	}
	check_input_file(argv[1]);
	vars = is_map_valid(argv);
	restore_original_map(vars);
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->c * 64, vars->l * 64, "hi");
	map_init(vars);
	aff_map(vars);
	mlx_key_hook(vars->win, key_hook, vars);
	mlx_hook(vars->win, 17, 0, exit_fun_er, vars);
	mlx_loop(vars->mlx);
	return (0);
}
