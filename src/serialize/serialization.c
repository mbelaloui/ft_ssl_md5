/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 17:55:12 by mbelalou          #+#    #+#             */
/*   Updated: 2019/08/15 15:01:28 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

int		get_size_message_512(size_t initial_len)
{
	size_t ret;

	ret = (initial_len * 8);
	ret += 1;
	while ((ret % 512) != 448)
		ret++;
	return (ret / 8);
}



uint64_t swapE64(uint64_t val) {
	uint64_t x = val;
	x = (x & 0xffffffff00000000) >> 32 | (x & 0x00000000ffffffff) << 32;
	x = (x & 0xffff0000ffff0000) >> 16 | (x & 0x0000ffff0000ffff) << 16;
	x = (x & 0xff00ff00ff00ff00) >>  8 | (x & 0x00ff00ff00ff00ff) <<  8;
	return x;
}




void	set_size(t_buff *md5, uint32_t bits_size_src_msg)
{
	//	int shift;
	uint64_t size;


	size = swapE64(bits_size_src_msg);
	//	shift = 7;

	//	while (temp >= 256)
	//	{
	//		temp -= 256;
	//		shift -= 2;
	//	}
	//	ft_printf("len = [%d]  [size  %b]\n", shift, bits_size_src_msg);


	//ft_memcpy(md5->prepared_msg + md5->size_prepared_msg + shift, &bits_size_src_msg, 32);
	ft_memcpy(md5->prepared_msg + md5->total_size_msg - 8, &size, 8);

//	print_block_64(md5->prepared_msg);
//	print_block_64(md5->prepared_msg + 64);
//	exit(0);

}

void	get_new_message_512(t_general *gen, t_buff *md5)
{
	int bits_size_src_msg;

	if (gen->v)
		ft_printf("Transforme the input to get prossessed\n");
	if (!(md5->prepared_msg = ft_memalloc(md5->total_size_msg)))
		ft_error(ERROR_NOT_ENOUGH_MEM, NULL);
	ft_memcpy(md5->prepared_msg, md5->input_msg, md5->size_input_msg);
	md5->prepared_msg[md5->size_input_msg] = 128;
	bits_size_src_msg = md5->size_input_msg * 8;

	//sha256
	// i have to consider the bigedin format so i have to get the size of the representation of the len
	// then make the eauqtion to get the good number of bits shift to the right 
	//	ft_memcpy(md5->prepared_msg + md5->size_prepared_msg +7 , &bits_size_src_msg, 4);
	//ft_memcpy(md5->prepared_msg + md5->size_prepared_msg +7 , &bits_size_src_msg, 4);

	ft_printf("len [%d]/n", bits_size_src_msg);
	set_size(md5, bits_size_src_msg);

	// md5	ft_memcpy(md5->prepared_msg + md5->size_prepared_msg,	&bits_size_src_msg, 4);
}

void	serialization_512(t_general *gen, t_buff *md5, char *input)
{
	if (gen->v)
		ft_printf("Calcule nbr bits to add to get ==> [(len string)"
				"%% 512 = 0]\n");
	md5->input_msg = (uint8_t *)input;
	md5->size_input_msg = ft_strlen((char *)md5->input_msg);
	md5->size_prepared_msg = get_size_message_512(md5->size_input_msg);
	md5->total_size_msg = md5->size_prepared_msg + 8;
	if (gen->v)
		ft_printf("Initial message len %lld bits\tFinal size = %lld bits \n",
				md5->size_input_msg * 8, md5->total_size_msg * 8);
	get_new_message_512(gen, md5);
	if (!md5->prepared_msg)
		ft_error_exe(ERROR_NOT_ENOUGH_MEM);
}
