/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compression_fonction.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 17:42:56 by mbelalou          #+#    #+#             */
/*   Updated: 2019/08/15 14:20:54 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

void	md5_f(t_buffer_md5 *buf, int i)
{
	buf->f = ((buf->b & buf->c) | ((~buf->b) & buf->d));
	buf->g = i;
}

void	md5_g(t_buffer_md5 *buf, int i)
{
	buf->f = ((buf->d & buf->b) | (buf->c & (~buf->d)));
	buf->g = ((5 * i + 1) % 16);
}

void	md5_h(t_buffer_md5 *buf, int i)
{
	buf->f = (buf->b ^ buf->c ^ buf->d);
	buf->g = ((3 * i + 5) % 16);
}

void	md5_i(t_buffer_md5 *buf, int i)
{
	buf->f = (buf->c ^ (buf->b | (~buf->d)));
	buf->g = ((7 * i) % 16);
}
