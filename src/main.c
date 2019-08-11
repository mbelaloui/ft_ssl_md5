/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 17:22:29 by mbelalou          #+#    #+#             */
/*   Updated: 2019/08/10 18:00:21 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

void	print_gen(t_general *gen)
{
	ft_printf("\n - Algorithm\t[%s]\n\t-q [%s]\n\t-p [%s]\n\t-r [%s]\n\t-s [%s]\n"
	"\n\t-v [%s]\n\n - Liste file to read :\n",
	gen->cmd, (gen->q) ? "On" : "Off", (gen->p) ? "On" : "Off",
	(gen->p) ? "On" : "Off", (gen->p) ? "On" : "Off", (gen->p) ? "On" : "Off");
	if (ft_size_charlist(gen->url_file))
		while (gen->url_file)
		{
			ft_printf("\turl : [%s]\n", gen->url_file->data);
			gen->url_file = gen->url_file->next;
		}
	else
		ft_printf("\tNo File Url found, Reading from STDIN\n");
}

void	hash(t_general *gen)
{
	if (!strcmp("md5", gen->cmd))
		md5(gen);
	else if (!strcmp("sha256", gen->cmd))
		md5(gen);
	else
		ft_printf("Not yet Implemented");
}

int		run(t_general *gen, char **argv)
{
	if (is_hash_funtions(argv[0]))
	{
		if (gen->v)
			ft_printf("Cryptographic hash functions\n");
		hash(gen);
		return (1);
	}
	else if (is_des_funtions(argv[0]))
	{
		if (gen->v)
			ft_printf("Data Encryption Standard\n");
		return (1);
	}
	else if (is_standard_funtions(argv[0]))
	{
		if (gen->v)
			ft_printf("run standard commande\n");
		return (1);
	}
	else
		return (0);
}

void		free_gen(t_general *gen)
{
	t_charlist *pt;

	pt = gen->url_file;
	ft_put_list_charlist(pt);
	ft_printf("pass par la \n");

}

int		main(int argc, char **argv)
{
	t_general	gen;
	t_charlist	*pt_temp;

	if (argc < 2)
	{
		usage();
		return (0);
	}
	ft_bzero(&gen, sizeof(gen));
	parss_args(&gen, argv + 1);
	pt_temp = (gen.url_file);
	if (!run(&gen, argv + 1))
		ft_invalide_cmd(argv[1]);
	ft_dell_list_charlist(&pt_temp);
	return (0);
}
