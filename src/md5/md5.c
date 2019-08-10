/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 17:31:38 by mbelalou          #+#    #+#             */
/*   Updated: 2019/08/10 18:03:44 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

void	print_register(t_buffer_md5 buf, int round)
{
	uint8_t *p;

	ft_printf("Round %d\n", round);
	p = (uint8_t *)&buf.a;
	ft_printf("A [%2.2x %2.2x %2.2x %2.2x]\n", p[0], p[1], p[2], p[3]);
	p = (uint8_t *)&buf.b;
	ft_printf("B [%2.2x %2.2x %2.2x %2.2x]\n", p[0], p[1], p[2], p[3]);
	p = (uint8_t *)&buf.c;
	ft_printf("C [%2.2x %2.2x %2.2x %2.2x]\n", p[0], p[1], p[2], p[3]);
	p = (uint8_t *)&buf.d;
	ft_printf("D [%2.2x %2.2x %2.2x %2.2x]\n", p[0], p[1], p[2], p[3]);
	ft_printf("\t\t\t----------------------\n");
}

void	swap_byts(t_buffer_md5 *buf, size_t i, uint32_t f, uint32_t g)
{
	uint32_t r[] = {7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7,
	 12, 17, 22, 5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20, 5, 9,
	 14, 20, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 
	 23, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21};
	uint32_t k[] = {
		0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
		0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
		0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
		0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
		0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
		0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
		0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
		0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
		0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
		0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
		0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
		0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
		0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
		0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
		0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
		0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391};
	unsigned int temp;
	unsigned int t;

	temp = buf->d;
	t = buf->a + f + k[i] + buf->pt[g];
	buf->d = buf->c;
	buf->c = buf->b;
	t = (t << r[i]) | (t >> (32 - r[i]));
	buf->b = buf->b + t;
	buf->a = temp;
}

void	init_buffer(t_buffer_md5 *buf)
{
	buf->a = 0x67452301;
	buf->b = 0xefcdab89;
	buf->c = 0x98badcfe;
	buf->d = 0x10325476;
}

t_buffer_md5	norm_val(uint32_t h1, uint32_t h2, uint32_t h3, uint32_t h4)
{
	t_buffer_md5 ret;

	ret.a = h1;
	ret.b = h2;
	ret.c = h3;
	ret.d = h4;
	return (ret);
}

void	add_buffer(t_buffer_md5 *buf, t_buffer_md5 temp)
{
	buf->a += temp.a;
	buf->b += temp.b;
	buf->c += temp.c;
	buf->d += temp.d;
}

void	put_result_md5(t_general *gen, t_buffer_md5 buf, char *url_file)
{
	uint8_t *p;

	(void)gen;
	if (url_file)
		ft_printf("MD5(%s)= ", url_file);
	p = (uint8_t *)&buf.a;
	ft_printf("%2.2x%2.2x%2.2x%2.2x", p[0], p[1], p[2], p[3]);
	p = (uint8_t *)&buf.b;
	ft_printf("%2.2x%2.2x%2.2x%2.2x", p[0], p[1], p[2], p[3]);
	p = (uint8_t *)&buf.c;
	ft_printf("%2.2x%2.2x%2.2x%2.2x", p[0], p[1], p[2], p[3]);
	p = (uint8_t *)&buf.d;
	ft_printf("%2.2x%2.2x%2.2x%2.2x\n", p[0], p[1], p[2], p[3]);
}

/*
**	print_register(temp_val_buf, (offset / 64) - 1);
**	print_register(buf, (offset / 64) - 1);
**	print_register(buf, (offset / 64) - 1);
**	print_register(buf, (offset / 64) - 1);
*/

void	ft_md5(t_general *gen, t_md5 *md5, char *url_file)
{
	t_buffer_md5	buf;
	t_buffer_md5	temp_val_buf;
	size_t			offset;

	ft_memset(&buf, 0, sizeof(buf));
	offset = 0;
	temp_val_buf = norm_val(H0, H1, H2, H3);
	add_buffer(&buf, temp_val_buf);
	while (offset < md5->total_size_msg)
	{
		temp_val_buf = norm_val(buf.a, buf.b, buf.c, buf.d);
		buf.pt = (uint32_t *)(md5->prepared_msg + offset);
		compress_block_md5(temp_val_buf, &buf);
//		compress_block_md5(temp_val_buf, &buf, offset % 64);
		offset = offset + 64;
	}
	put_result_md5(gen, buf, url_file);
	free(md5->prepared_msg);
}

void	md5(t_general *gen)
{
	t_md5	md5;
	char	*str;

	ft_bzero(&md5, sizeof(md5));
	if (ft_size_charlist(gen->url_file))
	{
		while (gen->url_file)
		{
			if (!(str = read_file(gen->url_file->data)))
				ft_error(ERROR_CAN_NOT_OPEN_FILE, gen->url_file->data);
			serialization_md5(gen, &md5, str);
			ft_md5(gen, &md5, gen->url_file->data);
			gen->url_file = gen->url_file->next;
		}
	}
	else
	{
		str = read_stdin();
		serialization_md5(gen, &md5, str);
		ft_md5(gen, &md5, gen->url_file->data);
	}
}
