/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 15:56:23 by mbelalou          #+#    #+#             */
/*   Updated: 2019/08/15 15:18:21 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/inc/libft.h"

#define MD5_H0 0x67452301
#define MD5_H1 0xefcdab89
#define MD5_H2 0x98badcfe
#define MD5_H3 0x10325476

#define SHA256_H0 0x6A09E667
#define SHA256_H1 0xBB67AE85
#define SHA256_H2 0x3C6EF372
#define SHA256_H3 0xA54FF53a
#define SHA256_H4 0x510e527f
#define SHA256_H5 0x9b05688c
#define SHA256_H6 0x1f83d9ab
#define SHA256_H7 0x5be0cd19


typedef struct		s_buff
{
	uint64_t	size_input_msg;
	uint64_t	size_prepared_msg;
	uint64_t	total_size_msg;
	uint8_t		*input_msg;
	uint8_t		*prepared_msg;
}			t_buff;


typedef struct		s_sha256
{
	uint64_t	size_input_msg;
	uint64_t	size_prepared_msg;
	uint64_t	total_size_msg;
	uint8_t		*input_msg;
	uint8_t		*prepared_msg;
}			t_sha256;

typedef struct		s_buffer_md5
{
	uint32_t	a;
	uint32_t	b;
	uint32_t	c;
	uint32_t	d;
	uint32_t	*pt;
	uint32_t	f;
	uint32_t	g;
	uint32_t	r[64];
	uint32_t	k[64];

}			t_buffer_md5;

typedef struct		s_buffer_sha256
{
	uint32_t	a;
	uint32_t	b;
	uint32_t	c;
	uint32_t	d;
	uint32_t	e;
	uint32_t	f;
	uint32_t	g;
	uint32_t	h;
	uint32_t	*pt;
//	uint32_t	f;
//	uint32_t	g;
	uint32_t	r[64];
	uint32_t	k[64];

}			t_buffer_sha256;

typedef struct		s_general
{
	BOOL		p;
	BOOL		q;
	BOOL		r;
	BOOL		s;
	BOOL		v;
	char		*cmd;
	t_charlist	*url_file;  // a revoir ce type
}			t_general;


char	*read_std_in();

int		is_hash_funtions(char *cmd);
int		is_des_funtions(char *cmd);
int		is_standard_funtions(char *cmd);

void	ft_invalide_cmd(char *input);
void	usage();
void	compress_block_md5(t_buffer_md5 temp_val_buf, t_buffer_md5 *buf);

void	ft_invalide_option(char *input);

void	md5_f(t_buffer_md5 *buf, int i);
void	md5_g(t_buffer_md5 *buf, int i);
void	md5_h(t_buffer_md5 *buf, int i);
void	md5_i(t_buffer_md5 *buf, int i);
void	print_register(t_buffer_md5 buf, int round);
void	add_buffer_16byts(t_buffer_md5 *buf, t_buffer_md5 temp);
void	swap_byts(t_buffer_md5 *buf, size_t i, uint32_t f, uint32_t g );
void	print_block_64(uint8_t* msg);
void	ft_md5(t_general *gen);
void	parss_args(t_general *gen, char **arg);

char	*read_file(char *url_file);
char	*read_stdin();
void	ft_error(int error, char *str);
void	serialization_512(t_general *gen, t_buff *md5, char *input);

void	ft_sha256(t_general *gen);