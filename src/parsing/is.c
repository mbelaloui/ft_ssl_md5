/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 17:52:56 by mbelalou          #+#    #+#             */
/*   Updated: 2019/08/10 17:52:57 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

int	is_standard_funtions(char *cmd)
{
	if (!strcmp(cmd, "rsa"))
		return (0);
	return (0);
}

int	is_des_funtions(char *cmd)
{
	if (!strcmp(cmd, "des"))
		return (0);
	return (0);
}

int	is_hash_funtions(char *cmd)
{
	if (!strcmp(cmd, "md5") || !strcmp(cmd, "sha256"))
		return (1);
	return (0);
}
