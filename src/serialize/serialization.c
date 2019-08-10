/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 17:55:12 by mbelalou          #+#    #+#             */
/*   Updated: 2019/08/10 17:59:27 by mbelalou         ###   ########.fr       */
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

void	get_new_message_md5(t_general *gen, t_md5 *md5)
{
	int bits_size_src_msg;

	if (gen->v)
		ft_printf("Transforme the input to get prossessed\n");
	if (!(md5->prepared_msg = ft_memalloc(md5->total_size_msg)))
		ft_error(ERROR_NOT_ENOUGH_MEM, NULL);
	ft_memcpy(md5->prepared_msg, md5->input_msg, md5->size_input_msg);
	md5->prepared_msg[md5->size_input_msg] = 128;
	bits_size_src_msg = md5->size_input_msg * 8;
	ft_memcpy(md5->prepared_msg + md5->size_prepared_msg,
	&bits_size_src_msg, 4);
}

void	serialization_md5(t_general *gen, t_md5 *md5, char *input)
{
	if (gen->v)
		ft_printf("Calcule nbr bits to add to get ==> [(len string)"
		"% 512 = 0]\n");
	md5->input_msg = (uint8_t *)input;
	md5->size_input_msg = ft_strlen((char *)md5->input_msg);
	md5->size_prepared_msg = get_size_message_512(md5->size_input_msg);
	md5->total_size_msg = md5->size_prepared_msg + 8;
	if (gen->v)
		ft_printf("Initial message len %lld bits\tFinal size = %lld bits \n",
		md5->size_input_msg * 8, md5->total_size_msg * 8);
	get_new_message_md5(gen, md5);
	if (!md5->prepared_msg)
		ft_error_exe(ERROR_NOT_ENOUGH_MEM);
}
