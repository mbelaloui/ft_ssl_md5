/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 17:31:38 by mbelalou          #+#    #+#             */
/*   Updated: 2019/08/15 15:18:34 by mbelalou         ###   ########.fr       */
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

void	set_val(uint32_t *k, uint32_t a, uint32_t b, int pos)
{
	k[pos] = a;
	k[pos + 1] = b;
}

void	init_k_md5_part_2(uint32_t *k)
{
	set_val(k, 0xfffa3942, 0x8771f681, 32);
	set_val(k, 0x6d9d6122, 0xfde5380c, 34);
	set_val(k, 0xa4beea44, 0x4bdecfa9, 36);
	set_val(k, 0xf6bb4b60, 0xbebfbc70, 38);
	set_val(k, 0x289b7ec6, 0xeaa127fa, 40);
	set_val(k, 0xd4ef3085, 0x04881d05, 42);
	set_val(k, 0xd9d4d039, 0xe6db99e5, 44);
	set_val(k, 0x1fa27cf8, 0xc4ac5665, 46);
	set_val(k, 0xf4292244, 0x432aff97, 48);
	set_val(k, 0xab9423a7, 0xfc93a039, 50);
	set_val(k, 0x655b59c3, 0x8f0ccc92, 52);
	set_val(k, 0xffeff47d, 0x85845dd1, 54);
	set_val(k, 0x6fa87e4f, 0xfe2ce6e0, 56);
	set_val(k, 0xa3014314, 0x4e0811a1, 58);
	set_val(k, 0xf7537e82, 0xbd3af235, 60);
	set_val(k, 0x2ad7d2bb, 0xeb86d391, 62);
}

/*
**	set_val(k, , , );
*/

void	init_k_md5_part_1(uint32_t *k)
{
	set_val(k, 0xd76aa478, 0xe8c7b756, 0);
	set_val(k, 0x242070db, 0xc1bdceee, 2);
	set_val(k, 0xf57c0faf, 0x4787c62a, 4);
	set_val(k, 0xa8304613, 0xfd469501, 6);
	set_val(k, 0x698098d8, 0x8b44f7af, 8);
	set_val(k, 0xffff5bb1, 0x895cd7be, 10);
	set_val(k, 0x6b901122, 0xfd987193, 12);
	set_val(k, 0xa679438e, 0x49b40821, 14);
	set_val(k, 0xf61e2562, 0xc040b340, 16);
	set_val(k, 0x265e5a51, 0xe9b6c7aa, 18);
	set_val(k, 0xd62f105d, 0x02441453, 20);
	set_val(k, 0xd8a1e681, 0xe7d3fbc8, 22);
	set_val(k, 0x21e1cde6, 0xc33707d6, 24);
	set_val(k, 0xf4d50d87, 0x455a14ed, 26);
	set_val(k, 0xa9e3e905, 0xfcefa3f8, 28);
	set_val(k, 0x676f02d9, 0x8d2a4c8a, 30);
}

void	init_k_md5(uint32_t *k)
{
	init_k_md5_part_1(k);
	init_k_md5_part_2(k);
}

void	init_r_md5_part_2(uint32_t *k)
{
	set_val(k, 4, 11, 32);
	set_val(k, 16, 23, 34);
	set_val(k, 4, 11, 36);
	set_val(k, 16, 23, 38);
	set_val(k, 4, 11, 40);
	set_val(k, 16, 23, 42);
	set_val(k, 4, 11, 44);
	set_val(k, 16, 23, 46);
	set_val(k, 6, 10, 48);
	set_val(k, 15, 21, 50);
	set_val(k, 6, 10, 52);
	set_val(k, 15, 21, 54);
	set_val(k, 6, 10, 56);
	set_val(k, 15, 21, 58);
	set_val(k, 6, 10, 60);
	set_val(k, 15, 21, 62);
}

void	init_r_md5_part_1(uint32_t *k)
{
	set_val(k, 7, 12, 0);
	set_val(k, 17, 22, 2);
	set_val(k, 7, 12, 4);
	set_val(k, 17, 22, 6);
	set_val(k, 7, 12, 8);
	set_val(k, 17, 22, 10);
	set_val(k, 7, 12, 12);
	set_val(k, 17, 22, 14);
	set_val(k, 5, 9, 16);
	set_val(k, 14, 20, 18);
	set_val(k, 5, 9, 20);
	set_val(k, 14, 20, 22);
	set_val(k, 5, 9, 24);
	set_val(k, 14, 20, 26);
	set_val(k, 5, 9, 28);
	set_val(k, 14, 20, 30);
}

void	init_r_md5(uint32_t *k)
{
	init_r_md5_part_1(k);
	init_r_md5_part_2(k);
}

void	swap_byts(t_buffer_md5 *buf, size_t i, uint32_t f, uint32_t g)
{
	uint32_t k[64];
	uint32_t r[64];
	uint32_t temp;
	uint32_t t;

	init_k_md5(k);
	init_r_md5(r);
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

static  t_buffer_md5	norm_val(uint32_t h1, uint32_t h2, uint32_t h3, uint32_t h4)
{
	t_buffer_md5 ret;

	ret.a = h1;
	ret.b = h2;
	ret.c = h3;
	ret.d = h4;
	return (ret);
}

void	add_buffer_16byts(t_buffer_md5 *buf, t_buffer_md5 temp)
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
	else
		ft_printf("(stdin)= ", url_file);
	p = (uint8_t *)&buf.a;
	ft_printf("%2.2x%2.2x%2.2x%2.2x", p[0], p[1], p[2], p[3]);
	p = (uint8_t *)&buf.b;
	ft_printf("%2.2x%2.2x%2.2x%2.2x", p[0], p[1], p[2], p[3]);
	p = (uint8_t *)&buf.c;
	ft_printf("%2.2x%2.2x%2.2x%2.2x", p[0], p[1], p[2], p[3]);
	p = (uint8_t *)&buf.d;
	ft_printf("%2.2x%2.2x%2.2x%2.2x\n", p[0], p[1], p[2], p[3]);
}

static void	run(t_general *gen, t_buff *md5, char *url_file)
{
	t_buffer_md5	buf;
	t_buffer_md5	temp_val_buf;
	size_t			offset;

	offset = 0;
	ft_bzero(&buf, sizeof(buf));
	temp_val_buf = norm_val(MD5_H0, MD5_H1, MD5_H2, MD5_H3);
	add_buffer_16byts(&buf, temp_val_buf);
	while (offset < md5->total_size_msg)
	{
		temp_val_buf = norm_val(buf.a, buf.b, buf.c, buf.d);
		buf.pt = (uint32_t *)(md5->prepared_msg + offset);
		compress_block_md5(temp_val_buf, &buf);
		offset = offset + 64;
	}
	put_result_md5(gen, buf, url_file);
	free(md5->prepared_msg);
}

void	ft_md5(t_general *gen)
{
	t_buff	md5;
	char	*str;

	ft_bzero(&md5, sizeof(md5));
	if (ft_size_charlist(gen->url_file))
	{
		while (gen->url_file)
		{
			if (!(str = read_file(gen->url_file->data)))
				ft_error(ERROR_CAN_NOT_OPEN_FILE, gen->url_file->data);
			serialization_512(gen, &md5, str);
			run(gen, &md5, gen->url_file->data);
			ft_strdel(&str);
			gen->url_file = gen->url_file->next;
		}
	}
	else
	{
		str = read_stdin();
		if (!str)
			ft_error_exe(ERROR_NOT_ENOUGH_MEM);
		serialization_512(gen, &md5, str);
		run(gen, &md5, NULL);
		ft_strdel(&str);
	}
}
