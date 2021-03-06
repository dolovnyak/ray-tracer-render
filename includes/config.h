/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 02:46:07 by sbecker           #+#    #+#             */
/*   Updated: 2019/07/04 16:36:52 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# include <OpenCL/opencl.h>
# include <mlx.h>
# include <math.h>
# include "libft.h"
# include "utilits.h"
# include "ray_trace.h"
# include <stdio.h>

typedef struct			s_cl
{
	cl_command_queue	queue;
	cl_context			context;
	cl_kernel			kernel;
}						t_cl;

typedef struct			s_mlx
{
	void				*img_ptr;
	void				*mlx;
	void				*win;
	char				*img_data;
	int					bpp;
	int					endian;
	int					size_line;
	int					width;
	int					height;
}						t_mlx;

typedef struct			s_config
{
	int					mouse_x;
	int					mouse_y;
	int					flag_rotation_z_left;
	int					flag_rotation_z_right;
	int					lights_num;
	int					objects_num;
	t_object3d			*objects;
	t_canvas			canvas;
	t_lights			*lights;
	t_mlx				mlx;
	t_cl				cl;
}						t_conf;

cl_device_id			get_device_id(void);
char					*get_program_buf(const char *name,
		size_t *program_size);
void					initialization_mlx(t_mlx *mlx);
void					initialization_canvas(t_canvas *canvas);
void					initialization_scene(t_conf *conf);
void					initialization_cl(t_cl *cl);
t_lights				new_light_ambient(float intensity);
t_lights				new_light_point(float intensity, t_vector3d position);
t_lights				new_light_directional(float intensity,
		t_vector3d direction);
int						key_press(int key, t_conf *conf);
int						key_release(int key, t_conf *conf);
int						exit_event(void *param);
int						mouse_move(int x, int y, t_conf *conf);
int						refresh(t_conf *conf);
void					scene_1(t_conf *conf);
void					scene_2(t_conf *conf);
void					scene_mario_eden(t_conf *conf);
void					scene_too_many_problems(t_conf *conf);

#endif
