/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compression_fonction.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 17:42:56 by mbelalou          #+#    #+#             */
/*   Updated: 2019/08/10 17:45:03 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

void	ft_f(t_buffer_md5 *buf, int i)
{
	buf->f = ((buf->b & buf->c) | ((~buf->b) & buf->d));
	buf->g = i;
}

void	ft_g(t_buffer_md5 *buf, int i)
{
	buf->f = ((buf->d & buf->b) | (buf->c & (~buf->d)));
	buf->g = ((5 * i + 1) % 16);
}

void	ft_h(t_buffer_md5 *buf, int i)
{
	buf->f = (buf->b ^ buf->c ^ buf->d);
	buf->g = ((3 * i + 5) % 16);
}

void	ft_i(t_buffer_md5 *buf, int i)
{
	buf->f = (buf->c ^ (buf->b | (~buf->d)));
	buf->g = ((7 * i) % 16);
}
