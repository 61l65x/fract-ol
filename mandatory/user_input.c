/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:23:40 by apyykone          #+#    #+#             */
/*   Updated: 2023/11/26 16:23:42 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

/* Keyboard callbacks */
int	keyboard_events(int keycode, t_data *data)
{
	if (keycode == ESC)
		ft_clean_exit(data, NULL);
	if (keycode == RIGHT)
	{
		data->calc.min.r += 0.05;
		data->calc.max.r += 0.05;
	}
	else if (keycode == LEFT)
	{
		data->calc.min.r -= 0.05;
		data->calc.max.r -= 0.05;
	}
	else if (keycode == DOWN)
	{
		data->calc.min.i -= 0.05;
		data->calc.max.i -= 0.05;
	}
	else if (keycode == UP)
	{
		data->calc.min.i += 0.05;
		data->calc.max.i += 0.05;
	}
	ft_refresh(data);
	return (SUCCESS);
}

/* Mouse callbacks */
int	mouse_events(int event, int x, int y, t_data *data)
{
	t_complex	mouse;
	double		zoom;
	double		inter;

	if (event == SCROLL_UP || event == SCROLL_DOWN)
	{
		mouse.r = (double)x / (data->calc.size_x / (data->calc.max.r
					- data->calc.min.r)) + data->calc.min.r;
		mouse.i = (double)y / (data->calc.size_y / (data->calc.max.i
					- data->calc.min.i)) * -1 + data->calc.max.i;
		if (event == SCROLL_DOWN)
			zoom = 0.70;
		else
			zoom = 1.30;
		inter = 1.0 / zoom;
		data->calc.min.r *= zoom;
		data->calc.min.i *= zoom;
		data->calc.max.r *= zoom;
		data->calc.max.i *= zoom;
		ft_refresh(data);
	}
	return (SUCCESS);
}
