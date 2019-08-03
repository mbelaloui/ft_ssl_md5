/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_exe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 18:39:25 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/03 12:37:32 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/printf.h"

void	ft_error_exe(int error)
{
	ft_printf("{red}Error execution{eoc} : ");
	if (error == ERROR_NOT_ENOUGH_MEM)
		ft_printf("not enough memory for malloc\n");
	else if (error == ERROR_CAN_NOT_OPEN_FILE)
		ft_printf("can't open file\n");
	else if (error == ERROR_CAN_NOT_CEART_FILE)
		ft_printf("can't creat file\n");
	else
		ft_printf("error id %d\n", error);
	exit(error);
}
