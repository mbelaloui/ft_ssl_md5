/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_conversion_type.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 17:38:14 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/03 16:37:13 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/printf.h"

int		ft_is_convertion_type(char c)
{
	if (c == 's' || c == 'd' || c == 'c' || c == 'i' || c == 'o' || c == 'O'
	|| c == 'u' || c == 'U' || c == 'x' || c == 'X' || c == 'C' || c == 'S'
	|| c == 'p' || c == 'D' || c == 'n')
		return (1);
	return (0);
}