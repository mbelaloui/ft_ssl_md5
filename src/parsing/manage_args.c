/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 17:52:40 by mbelalou          #+#    #+#             */
/*   Updated: 2019/08/10 17:52:41 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

BOOL	is_option(char *arg)
{
	if (ft_strcmp(arg, "-p") && ft_strcmp(arg, "-q") && ft_strcmp(arg, "-r")
	&& ft_strcmp(arg, "-s") && ft_strcmp(arg, "-v"))
		return (F);
	return (T);
}

void	set_option(t_general *gen, char *ops)
{
	if (!ft_strcmp(ops, "-q"))
		gen->q = T;
	if (!ft_strcmp(ops, "-p"))
		gen->p = T;
	if (!ft_strcmp(ops, "-r"))
		gen->r = T;
	if (!ft_strcmp(ops, "-s"))
		gen->s = T;
	if (!ft_strcmp(ops, "-v"))
		gen->v = T;
}

void	add_namefile(t_general *gen, char *fine_url)
{
	if (!ft_add_charlist(fine_url, &(gen->url_file)))
		ft_error(ERROR_NOT_ENOUGH_MEM, NULL);
}

void	parss_args(t_general *gen, char **arg)
{
	int i;

	i = 1;
	gen->cmd = arg[0];
	while (arg[i])
	{
		if (arg[i][0] == '-' && is_option(arg[i]))
			set_option(gen, arg[i]);
		else if (arg[i][0] == '-')
			ft_invalide_option(arg[i]);
		else
			add_namefile(gen, arg[i]);
		i++;
	}
}
