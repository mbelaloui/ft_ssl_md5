
NAME			= ft_ssl

FLAGES			=  -Wall -Wextra -Werror -c
					  
#					  -O1 -g -fsanitize-address-use-after-scope \
#					  -fno-omit-frame-pointer\

DIR_MD5			= md5
SRC_MD5			= md5.c compress_block_md5.c compression_fonction.c
SRCS_MD5		= $(addprefix $(DIR_MD5)/, $(SRC_MD5))

DIR_INPUT		= input
SRC_INPUT		= read_data.c
SRCS_INPUT		= $(addprefix $(DIR_INPUT)/, $(SRC_INPUT))

DIR_PARS		= parsing
SRC_PARS		= is.c  ft_error.c manage_args.c
SRCS_PARS		= $(addprefix $(DIR_PARS)/, $(SRC_PARS))

DIR_OUTPUT		= output
SRC_OUTPUT		= print_block_64.c
SRCS_OUTPUT		= $(addprefix $(DIR_OUTPUT)/, $(SRC_OUTPUT))


DIR_SERIALIZE		= serialize
SRC_SERIALIZE		= serialization.c
SRCS_SERIALIZE		= $(addprefix $(DIR_SERIALIZE)/, $(SRC_SERIALIZE))


INC_DIR			= ./inc/

OBJS_DIR		= ./bin/

LIBFT_DIR		= libft

LIBFT			= libft.a

SRCS			= main.c $(SRCS_MD5)  $(SRCS_PARS) $(SRCS_OUTPUT) $(SRCS_SERIALIZE)\
				$(SRCS_INPUT)#		$(SRCS_PARSING) $(SRCS_ANT)

RED				= \033[31m
GREEN			= \033[32m
YELLO			= \033[33m
WHITE			= \033[37m
BIP				= \a

OBJS			= $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

all				: $(NAME)

$(NAME)			: $(LIBFT) $(OBJS_DIR) $(OBJS)
	@gcc $(OBJS) -L $(LIBFT_DIR) -lft -o $(NAME) -I $(INC_DIR)
	@echo "$(GREEN)$(NAME) has been successfully created !$(WHITE)."
	@#@@say "$(NAME) has been successfully created !"

$(OBJS_DIR)%.o	: src/%.c 
	@echo "$< $(GREEN) compiled $(WHITE)"
	#@echo "\033[1A \033[2K \033[A"
	@gcc $(FLAGES) $< -o $@ -I $(INC_DIR)

$(LIBFT)		:
	@echo "$< $(GREEN) start libft $(WHITE)"
	@make -C $(LIBFT_DIR)
	@echo "$< $(GREEN) end libft $(WHITE)"

$(OBJS_DIR)		:
	@mkdir -p $(OBJS_DIR);
	@mkdir -p $(OBJS_DIR)$(DIR_MD5);
	@mkdir -p $(OBJS_DIR)$(DIR_INPUT);
	@mkdir -p $(OBJS_DIR)$(DIR_PARS);
	@mkdir -p $(OBJS_DIR)$(DIR_OUTPUT);
	@mkdir -p $(OBJS_DIR)$(DIR_SERIALIZE);

clean			:
	@make -C $(LIBFT_DIR) clean
	@rm -fr $(OBJS_DIR)
	@echo "$(RED)cleaned the checker binary files$(WHITE)."
	@#say "cleaned the $(NAME) binary files."

fclean			:
	@make -C $(LIBFT_DIR) fclean
	@rm -fr $(OBJS_DIR)
	@echo "$(RED)cleaned the $(NAME) file$(WHITE)."
	@rm -f $(NAME)
	@echo "$(GREEN)the $(NAME) directory is totaly cleaned !!$(WHITE)."
	@#say "the $(NAME) directory is totaly cleaned !"

re				: fclean all

norm 			:
	@norminette | grep -B 1 "Error"

.PHONY : all clean fclean re