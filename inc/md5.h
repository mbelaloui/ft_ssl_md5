/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 15:56:23 by mbelalou          #+#    #+#             */
/*   Updated: 2019/08/10 18:02:05 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/inc/libft.h"

#define H0 0x67452301
#define H1 0xefcdab89
#define H2 0x98badcfe
#define H3 0x10325476

typedef struct		s_md5
{
	uint64_t	size_input_msg;
	uint64_t	size_prepared_msg;
	uint64_t	total_size_msg;
	uint8_t		*input_msg;
	uint8_t		*prepared_msg;
}			t_md5;

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

void	ft_f(t_buffer_md5 *buf, int i);
void	ft_g(t_buffer_md5 *buf, int i);
void	ft_h(t_buffer_md5 *buf, int i);
void	ft_i(t_buffer_md5 *buf, int i);
void	print_register(t_buffer_md5 buf, int round);
void	add_buffer(t_buffer_md5 *buf, t_buffer_md5 temp);
void	swap_byts(t_buffer_md5 *buf, size_t i, uint32_t f, uint32_t g );
void	print_block_64(uint8_t* msg);
void	md5(t_general *gen);
void	parss_args(t_general *gen, char **arg);

char	*read_file(char *url_file);
char	*read_stdin();
void	ft_error(int error, char *str);
void	serialization_md5(t_general *gen, t_md5 *md5, char *input);