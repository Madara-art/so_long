/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouabda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 22:38:47 by hbouabda          #+#    #+#             */
/*   Updated: 2023/01/23 21:49:43 by hbouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <fcntl.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_img
{
	void	*player;
	void	*ground;
	void	*collectable;
	void	*boundary;
	void	*exit;
	int		width;
	int		height;
}			t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	int		width;
	int		height;
	char	**map;
	int		*tab_el;
	int		c;
	int		l;
	int		p_x;
	int		p_y;
	t_img	simg;
}			t_mlx;

size_t
ft_strlen(const char *str);
char		*get_next_line(int fd);
char		*ft_strjoin(char *s1, char *s2, int freedom);
char		*ft_substr(char const *s, unsigned int start, size_t len);
void		ft_bzero(void *s, unsigned long n);
void		*ft_calloc(size_t count, size_t size);
void		*ft_memcpy(void *dst, const void *src, size_t n);
char		**read_map(char *path);
void		free_matrix(char **matrix);
void		check_map_size(t_mlx *vars, char *path);
void		check_map_elements(t_mlx *vars);
void		check_map_boundaries(t_mlx *vars);
void		apply_replace_char_to_map(t_mlx *vars);
void		replace_char(char *str, char c);
void		check_map_invalid_el(t_mlx *vars);
void		flood_fill(t_mlx *vars, int x, int y, int *tab);
t_mlx		*is_map_valid(char **argv);
void		player_pos(t_mlx *vars);
void		check_input_file(char *file);
void		restore_original_map(t_mlx *vars);
void		aff_map(t_mlx *vars);
void		map_init(t_mlx *vars);
int			key_hook(int keycode, t_mlx *vars);
void		exit_fun1(t_mlx *vars);
int			exit_fun_er(t_mlx *vars);

#endif
