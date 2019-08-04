//#include "./../inc/md5.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>


#define H0 0x67452301
#define H1 0xefcdab89
#define H2 0x98badcfe
#define H3 0x10325476

typedef struct		s_md5
{
	uint64_t	size_input_msg;
	uint64_t	size_prepared_msg;
	uint64_t	total_size_msg;
	uint8_t		*input_msg;
	uint8_t		*prepared_msg;
}			t_md5;


typedef struct		s_buffer_md5
{
	uint32_t	a;
	uint32_t	b;
	uint32_t	c;
	uint32_t	d;
	uint32_t	*pt;
	uint32_t	f;
	uint32_t	g;
	uint32_t	r[64];
	uint32_t	k[64];

}			t_buffer_md5;

typedef struct		s_general
{
	char		p;
	char		q;
	char		r;
	char		s;
	char		*cmd;
	char		**url_file;  // a revoir ce type
}			t_general;



int		ft_strcmp(const char *str1, const char *str2)
{
/*	uint64_t *a;
	uint64_t *b;

	a = (uint64_t)str1;
	b = (uint64_t)str2;*/
	while (*str1 || *str2)
	{
		if (str1 != str2)
			return (str1 - str2);
		str1++;
		str2++;
	}
	return (0);
}



/*

typedef struct s_option
{
	int	p;
}		t_opt;
*/
void	ft_F(t_buffer_md5 *buf, int i)
{
	buf->f =((buf->b & buf->c) | ((~buf->b) & buf->d));
	buf->g = i;
}

/**************************************************************************88*/
void	ft_G(t_buffer_md5 *buf, int i)
{
	buf->f =  (  (buf->d & buf->b) | (buf->c & (~buf->d)) );
	buf->g = ((5 * i + 1) % 16 );
}

/**************************************************************************88*/
void	ft_H(t_buffer_md5 *buf, int i)
{
	buf->f = (buf->b ^ buf->c ^ buf->d);
	buf->g = ((3 * i + 5) % 16);
}

/**************************************************************************88*/
void	ft_I(t_buffer_md5 *buf, int i)
{
	buf->f = (buf->c ^ (buf->b | (~buf->d)));
	buf->g = ((7 * i) % 16);
}
/**************************************************************************88*/
size_t ft_strlen(uint8_t *str)
{
	size_t ret;

	ret = 0;
	if (str)
		while (str[ret])
			ret ++;
	return (ret);
}

//void	print_block_64(unsigned char* msg)
void	print_block_64(uint8_t* msg)
{

	// ajouter une boucle pour aficher tout les bloque de message taill du bloc == 64;
	int i = 0; 
	while (i < 64)
	{
		printf("%x ", msg[i]);
		i++;
	}
	printf("\n");
}

//void	print_abcd(unsigned int h0, unsigned int h1, unsigned int h2, unsigned int h3)
void	print_register(t_buffer_md5 buf, int round)
{

	printf("Round %d\n", round);
	/* ********************************************** */
	uint8_t *p;
	p = (uint8_t *)&buf.a;
	printf("A [%2.2x %2.2x %2.2x %2.2x]\n", p[0], p[1], p[2], p[3]);

	p = (uint8_t *)&buf.b;
	printf("B [%2.2x %2.2x %2.2x %2.2x]\n", p[0], p[1], p[2], p[3]);

	p = (uint8_t *)&buf.c;
	printf("C [%2.2x %2.2x %2.2x %2.2x]\n", p[0], p[1], p[2], p[3]);

	p = (uint8_t *)&buf.d;
	printf("D [%2.2x %2.2x %2.2x %2.2x]\n", p[0], p[1], p[2], p[3]);

	printf("\t\t\t----------------------\n");
}




void	*ft_memset(void *mem, int c, size_t size)
{
	size_t			pt;
	unsigned char	*temp;

	temp = (unsigned char *)mem;
	pt = 0;
	while (pt < size)
	{
		temp[pt] = (unsigned char)c;
		pt++;
	}
	return ((void *)mem);
}

void	ft_bzero(void *str, const size_t size)
{
	ft_memset(str, '\0', size);
}

void	*ft_memalloc(const size_t size)
{
	char	*result;

	if (size > 2147483647)
		return (NULL);
	if (!(result = malloc((size + 1) * sizeof(*result))))
		exit(0);//ft_error_exe(ERROR_NOT_ENOUGH_MEM);
	ft_bzero(result, size + 1);
	return ((void *)result);
}


void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	size_t			pt;
	unsigned char	*temp_dest;
	unsigned char	*temp_src;

	temp_dest = (unsigned char *)dest;
	temp_src = (unsigned char *)src;
	pt = 0;
	while (pt < size)
	{
		temp_dest[pt] = temp_src[pt];
		pt++;
	}
	return (dest);
}

void	get_new_message(t_md5 *md5)
{
	int bits_size_src_msg;

	if (1 == 1)
		printf("Transforme the input to get prossessed\n");
		//exit(eoorue malloc);
	if (! (md5->prepared_msg = ft_memalloc(md5->total_size_msg)))
		return ;
	// copy the msg
	ft_memcpy(md5->prepared_msg, md5->input_msg, md5->size_input_msg);
	// add the 1 to the end of the message
	md5->prepared_msg[md5->size_input_msg] = 128;
	//add the size
	bits_size_src_msg = md5->size_input_msg * 8;
	ft_memcpy(md5->prepared_msg + md5->size_prepared_msg, &bits_size_src_msg, 4);
}

int     get_size_message_512(size_t initial_len)
{
	size_t ret;

	ret = (initial_len * 8);
	ret += 1;
	while ((ret % 512) != 448)
		ret++;
	return (ret / 8);
}

void	init_md5(t_md5 *md5, char *input)
{
	/*
		calcule la tail qu'il faut pour que ca soit a la norme len % 512= 0
		genere le format qi sera utiliser pour faire la compression
	*/
	if (1 == 1)
		printf("Calcule nbr bits to add to get ==> [(len string) %% 512 = 0]\n");
	md5->input_msg = (uint8_t *) input;
	md5->size_input_msg = ft_strlen(md5->input_msg);
	md5->size_prepared_msg = get_size_message_512(md5->size_input_msg);
	md5->total_size_msg = md5->size_prepared_msg + 8;
	if (1 == 1)
		printf("Initial message len %ld bits\tFinal size = %ld bits \n",
			       md5->size_input_msg * 8, md5->total_size_msg * 8);
	get_new_message(md5);
	if (!md5->prepared_msg)
	{
		printf("erreur malloc");
		exit(0);
	}
}

void	swap_byts(t_buffer_md5 *buf, size_t i, uint32_t f, uint32_t g )
{
	uint32_t r[] = {7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
		5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20,
		4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
		6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21};
	uint32_t k[] = {
		0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
		0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
		0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
		0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
		0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
		0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
		0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
		0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
		0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
		0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
		0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
		0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
		0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
		0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
		0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
		0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391};
	unsigned int temp;
	unsigned int t;
	
	temp = buf->d;	
	t = buf->a + f + k[i] + buf->pt[g];
	buf->d = buf->c;
	buf->c = buf->b;
	t = (t << r[i]) | (t >> (32 - r[i]));
	buf->b = buf->b + t;
	buf->a = temp;
}

void	init_buffer(t_buffer_md5 *buf)
{
	buf->a = 0x67452301;
	buf->b = 0xefcdab89;
	buf->c = 0x98badcfe;
	buf->d = 0x10325476;
}

t_buffer_md5	norm_val(uint32_t h1, uint32_t h2, uint32_t h3, uint32_t h4)
{
	t_buffer_md5 ret;

	ret.a = h1;
	ret.b = h2;
	ret.c = h3;
	ret.d = h4;
	return (ret);
}

void	add_buffer(t_buffer_md5 *buf, t_buffer_md5 temp)
{
	buf->a += temp.a;
	buf->b += temp.b;
	buf->c += temp.c;
	buf->d += temp.d;
}

void	compress_block(t_buffer_md5 temp_val_buf, t_buffer_md5 *buf, int round)
{
	int bit;

	bit = 0;	
	print_block_64( (uint8_t*) buf->pt);
	while (bit < 64)
	{
		if (bit < 16)
			ft_F(buf, bit);
		else if (bit < 32)
			ft_G(buf, bit);
		else if (bit < 48)
			ft_H(buf, bit);
		else
			ft_I(buf, bit);
		swap_byts(buf, bit, buf->f, buf->g);
		bit++;
	}
	add_buffer(buf, temp_val_buf);
	print_register(*buf, round);
}

void	ft_md5(t_md5	*md5)
{
	size_t offset;
	t_buffer_md5 buf;
	t_buffer_md5 temp_val_buf;

	ft_memset(&buf, 0 , sizeof(buf));
	offset = 0;
	temp_val_buf =  norm_val(H0, H1, H2, H3);
	print_register(temp_val_buf, (offset / 64) - 1);
	print_register(buf, (offset / 64) - 1);
	
	add_buffer(&buf, temp_val_buf);
	print_register(buf, (offset / 64) - 1);
	while (offset < md5->total_size_msg)
	{
		temp_val_buf =  norm_val(buf.a, buf.b, buf.c, buf.d);
		buf.pt = (uint32_t *)(md5->prepared_msg + offset);
		compress_block(temp_val_buf, &buf, offset % 64);
		offset = offset + 64;
		printf("\n---------------------------------------------------------\n\n");
	}
	print_register(buf, (offset / 64) - 1);
	free (md5->prepared_msg);
}

void	run_md5(char *str)
{
	printf("message to hash [%s] \n", str);
	t_md5	md5;
	init_md5(&md5, str);
	ft_md5(&md5);	

}


void	ft_invalide(char *input)
{
	printf("ft_ssl: Error: '%s' is an invalid command.\n\n", input);
	printf("\n - Standard commands:\n");
	printf("\n - Message Digest commands:\n");
	printf("\tmd5\n");
	printf("\tsha256\n");
	printf("\n - Cipher commands:\n");
	exit(0);
}

void	usage()
{
	printf("usage: ft_ssl command [command opts] [command args]\n");
}



/*
 *
 * faire une option pour diferencier la source <file/stdin>
 *
 * pour stocker les options
 *
 * */

/**********************************************************************************/
/*
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>



int		ft_open_file(char *url_file)
{	
	int fd;

	if (url_file == NULL)
		return (-1);
	fd = open(url_file, O_RDONLY);
	if (fd < 0)
		return (-1);
	return (fd);
}
i
int	is_option(char *str)
{

	(void) str;
	return (0);
}

void	set_option(char *str)
{
	(void) str;
}
void	parss_args(char **argv)
{
	int i = 0;

	while (argv[i])
	{
		if (is_option(argv[i]))
			set_option(argv[i]);
		else if (ft_open_file(argv[i]) > 2)
			printf("%s    ok \n", argv[i++]);
		else
		{
			printf("%s: No such file or directory\n", argv[i++]);
			exit(0);
		}
	}
}
*/
/**********************************************************************************/
int	is_standard_commande(char *cmd)
{
	if (!strcmp(cmd, "rsa"))
		return (0);
	return (0);
}

int	is_cipher_commande(char *cmd)
{
	if (!strcmp(cmd, "des"))
		return (0);
	return (0);
}

int	is_md_commande(char *cmd)
{
	if (!strcmp(cmd, "md5") || !strcmp(cmd, "sha256"))
		return (1);
	return (0);
}
/*
int	is_commande(char *cmd)
{
	if (is_md_commande(cmd))
	
}
*/

size_t	ft_matlen(char **mat)
{
	size_t length;

	length = 0;
	if (mat)
		while (*mat++)
			length++;
	return (length);
}

void	md(t_general *gen)//har *cmd, char **argv)
{
	int i = 0;
	// while is there a file read it and process it 
	printf("cmd = %s \n", gen->cmd);
	if (!ft_matlen(gen->url_file))
	{
		printf("read from STDIN\n");
		printf("not finished yet ....read from io\n");
		if (!strcmp("md5", gen->cmd))
			run_md5("a");
		else if (!strcmp("sha256", gen->cmd))
			printf("not finished yet ....read from io\n");		
	}else
	{
		while (gen->url_file[i])
		{
			if (!strcmp("md5", gen->cmd))
			{	printf("not finished yet ....read from io\n");
				run_md5("a");
			}else if (!strcmp("sha256", gen->cmd))
			{	printf("not finished yet ....read from io\n");
			}		// read the argv 1
			// open file			if error -> 
			// read the file		if error ->
			// send the text to md5
		//	printf("[%s]\n", argv[i]);
			i++;
		}
	}
}


void	get_input_param(t_general *gen, char **arg)
{
//	parsing option    [option ]  files
	(void) arg;
	(void) gen;
	gen->cmd = arg[0];
}

int	run(char **argv)
{
	t_general gen;
	if (is_md_commande(argv[0]))
	{
		get_input_param(&gen, argv );
		printf("run md commande\n");
		// check options 
		// get files / input
		md(&gen);
		return (1);
	}else if(is_cipher_commande(argv[0]))
	{
		//get_input_param(&general, argv + 1);
		// check options 
		// get files / input
		printf("run cipher commande\n");
		return (1);
	}else if(is_standard_commande(argv[0]))
	{
		//get_input_param(&general, argv + 1);
		// check options 
		// get files / input
		printf("run standard commande\n");
		return (1);
	}else
		return (0);
}

int main (int argc, char ** argv)
{
	if (argc < 2)
	{
		usage();
		return (0);
	}
	if (!run(argv + 1))
		ft_invalide(argv[1]);
	return (0);
	/*
	if (!(id_cmd = is_commande(argv[1])))
	if ()
	printf("its a message digest commande\n");


//	parss_args(argv);
*/	/*
	char *line = NULL;
	get_next_line(0, &line);
	printf(line);
	printf("%s\n", argv[1]);

*/
	/*
	*/
}












/*
 *
 * faire le toure de toutes les variables pour voir si je les initialisent toutes ou pas
 *
 * */
