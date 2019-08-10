/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_to_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 14:57:23 by mbelalou          #+#    #+#             */
/*   Updated: 2019/08/10 11:30:17 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/char.h"

char	*ft_char_to_str(char c)
{
	char *ret;

	if (!ft_isprint(c) || !(ret = ft_strnew(1)))
		return (NULL);
	ret[0] = c;
	return (ret);
}
