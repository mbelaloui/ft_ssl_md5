/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_format_charlist.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 16:13:21 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/14 16:13:25 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/charlist.h"

t_charlist	*ft_str_to_format_charlist(char *str, char sep)
{
	t_charlist	*ret;
	char		**temp;
	int			i;
	char		*data;

	i = 0;
	if (!ft_strlen(str))
		return (NULL);
	temp = ft_strsplit(str, sep);
	ret = NULL;
	while (temp[i])
	{
		data = ft_format_str(temp[i]);
		ft_add_charlist(data, &ret);
		i++;
		ft_strdel(&data);
	}
	ft_free_mat(&temp);
	return (ret);
}
