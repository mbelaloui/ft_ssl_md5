//#include "./../inc/md5.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>


typedef struct	s_md5
{
	uint32_t	size_input_msg;
	uint32_t	size_prepared_msg;
	uint32_t	total_size_msg;
	uint8_t	*input_msg;
	uint8_t	*prepared_msg;
}		t_md5;


typedef struct                  s_buffer_md5
{
	uint32_t a;
	uint32_t b;
	uint32_t c;
	uint32_t d;
	uint32_t r[64];
	uint32_t k[64];

}                               t_buffer_md5;


typedef struct s_option
{
	int	p;
}		t_opt;

unsigned int ft_F(t_buffer_md5 buf)
{
	return ((buf.b & buf.c) | ((~buf.b) & buf.d));
}


unsigned int ft_g_1(int i)
{
	return (i);
}
/**************************************************************************88*/
unsigned int ft_G(t_buffer_md5 buf)
{
	return (  (buf.d & buf.b) | (buf.c & (~buf.d)) );
}


unsigned int ft_g_2(int i)
{
	return ((5 * i + 1) % 16 );
}
/**************************************************************************88*/
unsigned int ft_H(t_buffer_md5 buf)
{
	return (buf.b ^ buf.c ^ buf.d);
}


unsigned int ft_g_3(int i)
{
	return ((3 * i + 5) % 16);
}
/**************************************************************************88*/
unsigned int ft_I(t_buffer_md5 buf)
{
	return (buf.c ^ (buf.b | (~buf.d)));
}


unsigned int ft_g_4(int i)
{
	return ((7 * i) % 16);
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

void	put_struct(t_md5 *md5)
{
	printf("msg [%s]    norm len = [%zd byts]\n", md5->input_msg, md5->size_prepared_msg);
	printf("add the 64 bits [ 8 byts ] to the len \n");


	printf("msg [%s] size_message [%zd byts]  size_information = [%zd byts]\n",
			md5->input_msg, md5->total_size_msg,  md5->size_prepared_msg /*new_len_msg*/);


	printf("%s\n", md5->input_msg);
}


int     get_norm_len_message(size_t initial_len)
{
	//add a description of this function

	size_t ret;

	ret = (initial_len * 8);
	printf("byts len [%zd]\n", initial_len);
	printf("bits len  [%zd] \n", ret);
	printf("add the bits at the end \n");
	ret += 1;
	printf("bits len  [%zd] \n", ret);

	while ((ret % 512) != 448)
		ret++;
	//ret += 64;
	printf("normalized bits len ==> [%zd]\n",  ret );
	//printf( "len in word = [%d]\n", (ret / 8));
	return (ret / 8);
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
void	print_register(t_buffer_md5 buf)
{
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
	printf("Initial message len %zd bits\t", ret);
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
		printf("Final size = %u bits \n", md5->total_size_msg * 8);
	get_new_message(md5);

	exit(0);
}


void	ft_md5(t_md5	*md5)
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

	/*

	   int i = 0; 
	   while (i < 64)
	   {
	   printf("%x ", (unsigned)msg[i]);
	   i++;
	   }
	   printf("\n");
	   */
	unsigned int h0;
	unsigned int h1;
	unsigned int h2;
	unsigned int h3;

	h0 = 0x67452301;
	h1 = 0xefcdab89;
	h2 = 0x98badcfe;
	h3 = 0x10325476;

	t_buffer_md5 buf;

	size_t z = 0;
	while (z < md5->total_size_msg/*len_message*/)
	{
		buf.a = h0; 
		buf.b = h1; 
		buf.c = h2; 
		buf.d = h3; 


		print_register(buf);

		//unsigned int *pt = (unsigned int *)msg + z;
		unsigned int *pt = (unsigned int *)(md5->prepared_msg /*msg*/ + z);

		//	pt = pt + z * 2;
		print_block_64(md5->prepared_msg /*msg*/ + z);

		int i = 0;
		//print_msg_new_format(pt);
		print_block_64( (uint8_t*) pt);

		while (i < 64)
		{
			unsigned int f, g;

			if (i < 16)
			{
				f = ft_F(buf);
				g = ft_g_1(i);
			}
			else if ( i < 32)
			{
				f = ft_G(buf);
				g = ft_g_2(i);
			}
			else if ( i < 48)
			{
				f = ft_H(buf);
				g = ft_g_3(i);
			}
			else
			{
				f = ft_I(buf);
				g = ft_g_4(i);
			}

			unsigned int temp = buf.d;
			buf.d = buf.c;
			buf.c = buf.b;
			unsigned int t = buf.a + f + k[i] + pt[g];
			//t = (t << r[i]) | (t >> 32 - r[i]);
			t = (t << r[i]) | (t >> (32 - r[i]));
			buf.b = buf.b + t;
			buf.a = temp;

			printf("%d f[%x]  g[%d]   msg = %x\n",i, f, g, (unsigned int)pt[g]);
			printf("f[%x]  k[%x] w[%x] r[%x]\n", f, k[i] , pt[g], r[i]);
			printf("a[%x]  b[%x] c[%x] d[%x]\n\n\n", buf.a, buf.b , buf.c, buf.d);

			i++;
		}

		h0 += buf.a;
		h1 += buf.b;
		h2 += buf.c;
		h3 += buf.d;

		printf("h0[%x]  h1[%x] h2[%x] h3[%x]\n\n\n", h0, h1 , h2, h3);
		z = z + 64;
		printf("\n---------------------------------------------------------\n\n");
	}

	buf.a = h0; 
	buf.b = h1; 
	buf.c = h2; 
	buf.d = h3; 


	print_register(buf);
	free (md5->prepared_msg);

}

void	ft_invalide(char *input)
{
	printf("ft_ssl: Error: '%s' is an invalid command.\n", input);
	printf("Standard commands:\n");
	printf("Message Digest commands:\n");
	printf("md5\n");
	printf("sha256\n");
	printf("Cipher commands:\n");
}

void	usage()
{
	printf("usage: ft_ssl command [command opts] [command args]\n");
}

int main (int argc, char ** argv)
{
/*	(void ) argv;
	(void) argc;

	char *line = NULL;

	get_next_line(0, &line);

	printf(line);

	printf("%s\n", argv[1]);

	*/
	t_md5	md5;

	if (argc != 2)
	{
		printf("Usage md5\n");
		return (0);
	}
	init_md5(&md5, argv[1]);
	ft_md5(&md5);	
	return (0);
}
