/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_i_cyan.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 14:24:41 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/10 15:12:42 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/color.h"

void	ft_set_i_cyan(void)
{
	char	*str;
	int		pt;

	pt = -1;
	str = "\033[30;46m";
	while (str[++pt])
		ft_put_buf(str[pt], ING);
}
