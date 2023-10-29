
CC = gcc
CFLAG = -Wall -Wextra -Werror
LFT_FLAG = -Llibft -lft

NAME = libsyildiri.a


LFT_DIR = ./libft/
PRINTF_DIR = ./printf/

LIBFT = $(LFT_DIR)libft.a
GNL = $(GNL_DIR)libgnl.a
PRINTF = $(PRINTF_DIR)libftprintf.a

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@

$(NAME) :
	libtool -static -o $@ $^
	echo "Now you can use libsyildiri.a !!"

$(LIBFT) : 
	@echo "Making libft ..."
	@make -s -C ./libft bonus
	@echo "Making libft done !"


clean :
	@make -C $(LFT_DIR) clean
	@rm -f $(GNL_OBJ)

fclean : clean
	@make -C $(LFT_DIR) fclean
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
