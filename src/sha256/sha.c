/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 14:26:36 by mbelalou          #+#    #+#             */
/*   Updated: 2019/08/15 16:54:44 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

void    norm_val_part1(t_buffer_sha256	*buf, uint32_t h1, uint32_t h2, uint32_t h3)
{
	buf->a = h1;
	buf->b = h2;
	buf->c = h3;
}

void    norm_val_part2(t_buffer_sha256	*buf, uint32_t h1, uint32_t h2, uint32_t h3)
{
	buf->d = h1;
	buf->e = h2;
	buf->f = h3;
}

void    norm_val_part3(t_buffer_sha256	*buf, uint32_t h1, uint32_t h2)
{
	buf->g = h1;
	buf->h = h2;
}

static  void    norm_val(t_buffer_sha256	*buf)
{
    //buf = NULL;
    norm_val_part1(buf, SHA256_H0, SHA256_H1, SHA256_H2);
    norm_val_part2(buf, SHA256_H3, SHA256_H4, SHA256_H5);
    norm_val_part3(buf, SHA256_H6, SHA256_H7);
}

void	add_buffer_32byts(t_buffer_sha256 *buf, t_buffer_sha256 temp)
{
	buf->a += temp.a;
	buf->b += temp.b;
	buf->c += temp.c;
	buf->d += temp.d;
	buf->e += temp.e;
	buf->f += temp.f;
	buf->g += temp.g;
	buf->h += temp.h;
}

void	set_buffer_32byts(t_buffer_sha256 *buf, t_buffer_sha256 temp)
{
	buf->a = temp.a;
	buf->b = temp.b;
	buf->c = temp.c;
	buf->d = temp.d;
	buf->e = temp.e;
	buf->f = temp.f;
	buf->g = temp.g;
	buf->h = temp.h;

}

uint32_t right_rot(uint32_t a, int b)
{
    return ((a >> b) | (a << (32-b)));
}
/*
uint32_t left_rot(uint32_t a, int b)
{
    return (((a) << (b)) | ((a) >> (32-(b))));
}
*/

uint32_t	sha256_ch(uint32_t x, uint32_t y, uint32_t z)
{
	return ((x & y) ^ (~x & z));
}

uint32_t	sha256_maj(uint32_t x, uint32_t y, uint32_t z)
{
	return ((x & y) ^ (x & z) ^ (y & z));
}

uint32_t	sha256_e0(uint32_t x)
{
    return(right_rot(x,2) ^ right_rot(x,13) ^ right_rot(x,22));
}

uint32_t	sha256_e1(uint32_t x)
{
    return(right_rot(x,6) ^ right_rot(x,11) ^ right_rot(x,25));
	
}

uint32_t	sha256_s0(uint32_t x)
{
	return (right_rot(x,7) ^ right_rot(x,18) ^ ((x) >> 3));
}

uint32_t	sha256_s1(uint32_t x)
{
    return(right_rot(x,17) ^ right_rot(x,19) ^  (x >> 10));
}



void	put_result_sha256( t_buffer_sha256 buf, char *url_file)
{
//	uint8_t *p;
	(void) url_file;
//	(void)gen;


	ft_printf("%.8x\t%.8x\t%.8x\t%.8x\t%.8x\t%.8x\t%.8x\t%.8x\n", buf.a, buf.b, buf.c, buf.d, buf.e, buf.f, buf.g, buf.h);
/*
	if (url_file)
		ft_printf("SHA256(%s)= ", url_file);
	else
		ft_printf("(stdin)= ", url_file);
	p = (uint8_t *)&buf.a;
	ft_printf("%2.2x%2.2x%2.2x%2.2x", p[0], p[1], p[2], p[3]);
	p = (uint8_t *)&buf.b;
	ft_printf("%2.2x%2.2x%2.2x%2.2x", p[0], p[1], p[2], p[3]);
	p = (uint8_t *)&buf.c;
	ft_printf("%2.2x%2.2x%2.2x%2.2x", p[0], p[1], p[2], p[3]);
	p = (uint8_t *)&buf.d;
	ft_printf("%2.2x%2.2x%2.2x%2.2x", p[0], p[1], p[2], p[3]);
	p = (uint8_t *)&buf.e;
	ft_printf("%2.2x%2.2x%2.2x%2.2x", p[0], p[1], p[2], p[3]);
	p = (uint8_t *)&buf.f;
	ft_printf("%2.2x%2.2x%2.2x%2.2x", p[0], p[1], p[2], p[3]);
	p = (uint8_t *)&buf.g;
	ft_printf("%2.2x%2.2x%2.2x%2.2x", p[0], p[1], p[2], p[3]);
	p = (uint8_t *)&buf.h;
	ft_printf("%2.2x%2.2x%2.2x%2.2x\n", p[0], p[1], p[2], p[3]);*/
}

/*
void	swap_byts_sha256(t_buffer_sha256 *buf, size_t i, uint32_t f, uint32_t g)
{
	uint32_t k[64];
	uint32_t r[64];
	uint32_t temp;
	uint32_t t;

    (void) buf;
//	init_k_md5(k);
//	init_r_md5(r);
	temp = buf->d;
	t = buf->a + f + k[i] + buf->pt[g];
	buf->d = buf->c;
	buf->c = buf->b;
	t = (t << r[i]) | (t >> (32 - r[i]));
	buf->b = buf->b + t;
	buf->a = temp;
}*/
/*
static void	init_r_md5(uint32_t *k)
{
    
}
*/

void	compress_block_sha256(t_buffer_sha256 *temp_val_buf, uint8_t *msg)// t_buffer_sha256 *buf)
{
	int bit;
uint32_t k[64] = {
	0x428a2f98,0x71374491,0xb5c0fbcf,0xe9b5dba5,0x3956c25b,0x59f111f1,0x923f82a4,0xab1c5ed5,
	0xd807aa98,0x12835b01,0x243185be,0x550c7dc3,0x72be5d74,0x80deb1fe,0x9bdc06a7,0xc19bf174,
	0xe49b69c1,0xefbe4786,0x0fc19dc6,0x240ca1cc,0x2de92c6f,0x4a7484aa,0x5cb0a9dc,0x76f988da,
	0x983e5152,0xa831c66d,0xb00327c8,0xbf597fc7,0xc6e00bf3,0xd5a79147,0x06ca6351,0x14292967,
	0x27b70a85,0x2e1b2138,0x4d2c6dfc,0x53380d13,0x650a7354,0x766a0abb,0x81c2c92e,0x92722c85,
	0xa2bfe8a1,0xa81a664b,0xc24b8b70,0xc76c51a3,0xd192e819,0xd6990624,0xf40e3585,0x106aa070,
	0x19a4c116,0x1e376c08,0x2748774c,0x34b0bcb5,0x391c0cb3,0x4ed8aa4a,0x5b9cca4f,0x682e6ff3,
	0x748f82ee,0x78a5636f,0x84c87814,0x8cc70208,0x90befffa,0xa4506ceb,0xbef9a3f7,0xc67178f2
};

    int i = 0; //int j = 0;
	uint32_t m[64];

    while(i < 64)
    {
        if (i < 16)
		{
			m [i] = msg[i];
			//m[i] = (buf->pt[i] << 24) | (buf->pt[i + 1] << 16) | (buf->pt[i + 2] << 8) | (buf->pt[i + 3]);/
		}
        else
		{
			m[i] = sha256_s1(m[i - 2]) + m[i - 7] + sha256_s0(m[i - 15]) + m[i - 16];
		}
		i++;
	}
/*		
    for (i = 0, j = 0; i < 16; ++i, j += 4)
		m[i] = (buf->pt[j] << 24) | (buf->pt[j + 1] << 16) | (buf->pt[j + 2] << 8) | (buf->pt[j + 3]);
	for ( ; i < 64; ++i)
		m[i] = SIG1(m[i - 2]) + m[i - 7] + SIG0(m[i - 15]) + m[i - 16];
*/

//	init_r_md5(r);

	bit = 0;
//    (void) temp_val_buf;
//    (void) buf;
	while (bit < 64)
	{
        uint32_t t1 = temp_val_buf->h + sha256_e1(temp_val_buf->e) + sha256_ch(temp_val_buf->e, temp_val_buf->f, temp_val_buf->g) + k[bit] + m[bit];
        uint32_t t2 = sha256_e0(temp_val_buf->a) + sha256_maj(temp_val_buf->a, temp_val_buf->b, temp_val_buf->c);
        temp_val_buf->h = temp_val_buf->g;
        temp_val_buf->g = temp_val_buf->f;
        temp_val_buf->f = temp_val_buf->e;
        temp_val_buf->e = temp_val_buf->d + t1;
        temp_val_buf->d = temp_val_buf->c;
        temp_val_buf->c = temp_val_buf->b;
        temp_val_buf->b = temp_val_buf-> a;
        temp_val_buf->a = t1 + t2;
		//swap_byts_sha256(buf, bit, buf->f, buf->g);
	put_result_sha256(*temp_val_buf, "url_file");
		bit++;
	}
//	put_result_sha256(NULL, *buf, "url_file");
//	put_result_sha256(NULL, *temp_val_buf, "url_file");
	
//	put_result_sha256(gen, temp_val_buf, "url_file");

//	add_buffer_32byts(&temp_val_but, *buf);
//	add_buffer_32byts(buf, *temp_val_buf);
}
/*
static	void	put_msg(uint8_t *msg)
{
	int i = 0;

//	pt = (uint32_t *)msg
	while (i < 64)
	{
		ft_printf("[%x]\t", (uint32_t)msg[i]);
		i+= 4;
	}
}
*/
static  void	run(t_general *gen, t_buff *sha, char *url_file)
{
	t_buffer_sha256	process_buf;
	t_buffer_sha256	first_val_buf;
	size_t			offset;

//	put_msg(sha->prepared_msg);
	offset = 0;
	ft_bzero(&process_buf, sizeof(process_buf));
	ft_bzero(&first_val_buf, sizeof(first_val_buf));

	norm_val(&first_val_buf);

//	put_result_sha256(gen, temp_val_buf, url_file);
//	put_result_sha256(gen, buf, url_file);

//	put_result_sha256(gen, buf, url_file);
ft_printf("\n------------------------start loop---------------------------\n");
	set_buffer_32byts(&process_buf, first_val_buf);
ft_printf("\n\t\t----------- message---------------------------\n");
	print_block_64(sha->prepared_msg);
	//set_buffer_32byts(&temp_val_buf, buf);

//	put_result_sha256(gen, temp_val_buf, url_file);
	process_buf.pt = (uint32_t *)(sha->prepared_msg + offset);
ft_printf("\n\t\t----------- message to parss ---------------------------\n");
ft_printf("\n\t\t[%s]\n", (uint8_t *)process_buf.pt);
	
ft_printf("\n\t\t----------- hash variable defore ---------------------------\n");
ft_printf("%8.8s\t%8.8s\t%8.8s\t%8.8s\t%8.8s\t%8.8s\t%8.8s\t%8.8s\t\n", "A", "B", "C", "D", "E", "F", "G", "H");
	put_result_sha256(first_val_buf, url_file);
//	compress_block_sha256(&temp_val_buf, &buf);
	compress_block_sha256(&first_val_buf,(uint8_t *) process_buf.pt);

ft_printf("\n\t\t----------- hash variable after ---------------------------\n");
	put_result_sha256(first_val_buf, url_file);
	add_buffer_32byts(&process_buf, first_val_buf);
ft_printf("\n\t\t----------- process buf variable after ---------------------------\n");
	put_result_sha256(process_buf, url_file);
//	add_buffer_32byts(&process_buf, first_val_buf);
//	put_result_sha256(gen, process_buf, url_file);
	
//	put_result_sha256(gen, temp_val_buf, url_file);
//	put_result_sha256(gen, temp_val_buf, url_file);
	//exit(0);
	//while (offset < sha->total_size_msg)
	{
//        add_buffer_32byts(&temp_val_buf, buf);

//		put_result_sha256(gen, temp_val_buf, url_file);

//		 = norm_val(buf.a, buf.b, buf.c, buf.d);
/*		buf.pt = (uint32_t *)(sha->prepared_msg + offset);
		
		offset = offset + 64;
*/	}
//	put_result_sha256(gen, temp_val_buf, url_file);

		
exit(0);
(void) url_file;
(void) gen;
	free(sha->prepared_msg);
}

void	ft_sha256(t_general *gen)
{
	t_buff    sha;
	char	    *str;

	ft_bzero(&sha, sizeof(sha));
	if (ft_size_charlist(gen->url_file))
	{
		while (gen->url_file)
		{
			if (!(str = read_file(gen->url_file->data)))
				ft_error(ERROR_CAN_NOT_OPEN_FILE, gen->url_file->data);
			serialization_512(gen, &sha, str);
			run(gen, &sha, gen->url_file->data);
			ft_strdel(&str);
			gen->url_file = gen->url_file->next;
		}
	}
	else
	{
		str = read_stdin();
		if (!str)
			ft_error_exe(ERROR_NOT_ENOUGH_MEM);
		serialization_512(gen, &sha, str);
		run(gen, &sha, NULL);
		ft_strdel(&str);
	}
}
