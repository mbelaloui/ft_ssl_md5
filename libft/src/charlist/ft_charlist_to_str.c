/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charlist_to_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 11:22:35 by mbelalou          #+#    #+#             */
/*   Updated: 2018/07/18 11:27:56 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/charlist.h"

/*
** input        list of sring
** output       sting
**
** cette fonction prend les elements de la list et les concataine dans une
** string en les separent avec le caractere definit
*/

char	*ft_charlist_to_str(t_charlist *list, char c)
{
	char *ret;
	char *temp;

	ret = NULL;
	if (list)
	{
		ret = ft_strdup(list->data);
		list = list->next;
		while (list)
		{
			temp = ret;
			ret = ft_strjoin_sep(ret, list->data, c);
			ft_strdel(&temp);
			list = list->next;
		}
	}
	return (ret);
}
