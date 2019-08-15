/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 17:47:58 by mbelalou          #+#    #+#             */
/*   Updated: 2019/08/15 13:49:54 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

char	*read_stdin(void)
{
	char	*file;
	char	buf[BUFF_SIZE + 1];
	int		ret;
	char	*temp;

	file = NULL;
	ft_bzero(buf, BUFF_SIZE + 1);
	while (((ret = read(STD_IN, buf, BUFF_SIZE)) > 0))
	{
		temp = file;
		file = ft_strjoin(file, buf);
		ft_strdel(&temp);
		ft_bzero(buf, BUFF_SIZE + 1);
	}
	return (file);
}

char	*read_file(char *url_file)
{
	char	*file;
	char	buf[BUFF_SIZE + 1];
	char	*temp;
	int		ret;
	int		fd;

	file = NULL;
	if ((fd = ft_open_r_file(url_file)) > 0)
	{
		ft_bzero(buf, BUFF_SIZE);
		while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
		{
			temp = file;
			file = ft_strjoin(file, buf);
			ft_strdel(&temp);
			ft_bzero(buf, BUFF_SIZE + 1);
		}
	}
	return (file);
}
/*

void	*ft_memjoin(char *dest, size_t start, const char *src, size_t size)
{
	size_t			pt;
	unsigned char	*temp_dest;
	unsigned char	*temp_src;

	temp_dest = (unsigned char *)dest;
	temp_src = (unsigned char *)src;
	pt = 0;
	while (pt < size)
	{
		temp_dest[pt + start] = temp_src[pt];
		pt++;
	}
	return (dest);

	char	*result;
	size_t			pt;

	result = NULL;
	if (src)
	{
		result = ft_strnew(start + size);
		if (result == NULL)
			return (NULL);
		pt = 0;
		if (start)
		while (pt < start)
		{
			result[pt] = dest[pt];
			pt++;
		}
		while (pt < size)
		{
			result[pt] = src[pt];
			pt++;
		}
		return (result);
	}
	return (result);
}


*/