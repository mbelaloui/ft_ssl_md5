/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 17:53:27 by mbelalou          #+#    #+#             */
/*   Updated: 2019/08/10 18:00:50 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

void	ft_error(int error, char *str)
{
	ft_printf("{red}Error execution{eoc} : ");
	if (error == ERROR_CAN_NOT_OPEN_FILE)
		ft_printf("can't open file [%s]\n", str);
	else if (error == ERROR_NOT_ENOUGH_MEM)
		ft_printf("not enough memory for malloc\n");
	else
		ft_printf("error id %d\n", error);
	exit(error);
}

void	ft_invalide_cmd(char *input)
{
	ft_printf("ft_ssl: Error: '%s' is an invalid command.\n\n", input);
	ft_printf("\n - Standard commands:\n");
	ft_printf("\n - Message Digest commands:\n");
	ft_printf("\tmd5\n");
	ft_printf("\tsha256\n");
	ft_printf("\n - Cipher commands:\n");
	exit(0);
}

void	ft_invalide_option(char *input)
{
	usage();
	ft_printf("ft_ssl: Error: '%s' is an invalid options.\n\n", input);
	ft_printf("\t -p :\n");
	ft_printf("\t -q :\n");
	ft_printf("\t -r :\n");
	ft_printf("\t -s :\n");
	exit(0);
}

void	usage(void)
{
	ft_printf("Usage: ft_ssl command [command opts] [command args]\n");
}
