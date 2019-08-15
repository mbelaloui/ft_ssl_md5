/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress_block_md5.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 17:47:14 by mbelalou          #+#    #+#             */
/*   Updated: 2019/08/15 15:18:59 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

/*
** void	compress_block_md5(t_buffer_md5 temp_val_buf, t_buffer_md5 *buf,
**int round)
*/

void	compress_block_md5(t_buffer_md5 temp_val_buf, t_buffer_md5 *buf)
{
	int bit;

	bit = 0;
	while (bit < 64)
	{
		if (bit < 16)
			md5_f(buf, bit);
		else if (bit < 32)
			md5_g(buf, bit);
		else if (bit < 48)
			md5_h(buf, bit);
		else
			md5_i(buf, bit);
		swap_byts(buf, bit, buf->f, buf->g);
		bit++;
	}
	add_buffer_16byts(buf, temp_val_buf);
}
