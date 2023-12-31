
NAME = minishell

COLOR_RED = "\x1b[31m" 
COLOR_GREEN = "\x1b[32m"
COLOR_YELLOW = "\x1b[33m"
COLOR_BLUE = "\x1b[34m"
COLOR_WHITE = "\x1b[37m"
COLOR_CYAN = "\x1b[36m"
COLOR_RESET = "\x1b[0m"
LINE_CLEAR = "\x1b[1A\x1b[M"

CC = gcc
CFLAG = -Wall -Werror -Wextra
SANITIZER = -g -fsanitize=address
LIBFT_DIR = ./lib/libft/
LIBFT = $(LIBFT_DIR)libft.a
INC_DIR = ./includes/
CLUSTER_RL_DIR = $(HOME)/.brew/opt/readline
LIB = ./readline/.minishell

syildiri_LOCAL_RL_DIR = /opt/homebrew/opt/readline
syildiri_LIB_FLAG = -L$(syildiri_LOCAL_RL_DIR)/lib -L$(LIBFT_DIR)
syildiri_INC_FLAG = -I$(syildiri_LOCAL_RL_DIR)/include -I$(LIBFT_DIR) -I$(INC_DIR)

LIBRARIES= -L$(LIBFT_DIR) -L$(CLUSTER_RL_DIR)/lib
INCLUDES = -I$(LIBFT_DIR) -I$(INC_DIR) -I$(CLUSTER_RL_DIR)/include

SRC_DIR = ./srcs/
LEXER_DIR = $(SRC_DIR)lexer/
SCANNER_DIR = $(SRC_DIR)scanner/
PARSER_DIR = $(SRC_DIR)parser/
UTILFREE_DIR = $(SRC_DIR)util_free/
EXECUTOR_DIR = $(SRC_DIR)executor/
BUILTIN_DIR = $(SRC_DIR)builtin/

MAIN_SRCS =	init_prompt.c \
			init_struct.c \
			prompt.c \
			signal_handler.c \
			terminate_error.c \
			minishell.c \

LEXER_SRCS =	create_token_list.c \
				tokenizer.c \
				tokenizing_util.c \
				validate_token_list.c \
				lexer.c \

SCANNER_SRCS =	expand_envvars.c \
				expand_tokens.c \
				expand_util.c \
				get_token_env.c \
				init_token_util.c \
				scanner.c \

PARSER_SRCS =	build_parse_tree.c \
				init_parser.c \
				parser_add_tree_node.c \
				parser.c \

UTILFREE_SRCS =	safety_free.c \
				terminate_free.c \

EXECUTOR_SRCS = check_cmd.c \
				execute_cmd.c \
				execute_redirection.c \
				get_cmd_path.c \
				heredoc_process.c \
				heredoc_util.c \
				join_cmd_optarg.c \
				preorder_tree.c \
				print_execute_error.c \
				check_exit_status.c \
				fork_cmd.c \
				split_optarg.c \
				executor.c \

BUILTIN_SRCS =	builtin_cd.c \
				builtin_echo.c \
				builtin_env.c \
				builtin_error.c \
				builtin_exit.c \
				builtin_export.c \
				builtin_pwd.c \
				builtin_unset.c \
				builtin_utils.c \

MAIN_SRCDIR = $(addprefix $(SRC_DIR), $(MAIN_SRCS))
LEXER_SRCDIR = $(addprefix $(LEXER_DIR), $(LEXER_SRCS))
SCANNER_SRCDIR = $(addprefix $(SCANNER_DIR), $(SCANNER_SRCS))
PARSER_SRCDIR = $(addprefix $(PARSER_DIR), $(PARSER_SRCS))
UTILFREE_SRCDIR = $(addprefix $(UTILFREE_DIR), $(UTILFREE_SRCS))
EXECUTOR_SRCDIR = $(addprefix $(EXECUTOR_DIR), $(EXECUTOR_SRCS))
BUILTIN_SRCDIR = $(addprefix $(BUILTIN_DIR), $(BUILTIN_SRCS))

SRCS = $(MAIN_SRCDIR) $(LEXER_SRCDIR) $(SCANNER_SRCDIR) $(PARSER_SRCDIR) $(UTILFREE_SRCDIR) $(EXECUTOR_SRCDIR) $(BUILTIN_SRCDIR)
OBJS = $(SRCS:.c=.o)

all: $(LIB) $(NAME)

$(LIB):
	make -C readline

$(NAME): $(LIBFT) $(OBJS)
	@echo $(COLOR_GREEN) "Compile object files completed!" $(COLOR_RESET)
	@$(CC) $(CFLAG) $(LIBRARIES) $(INCLUDES) $(OBJS) -o $(NAME) -lft -lreadline -L./readline/readline/lib 
	@echo $(COLOR_GREEN) "Compile $(NAME) completed!" $(COLOR_RESET)

%.o: %.c
	@echo $(COLOR_GREEN) "Compiling...\t" $(COLOR_RESET) $(COLOR_YELLOW) $< $(COLOR_BLUE) $(LINE_CLEAR)
	@$(CC) $(CFLAG) -c $(INCLUDES) $< -o $@ -I./readline/readline/include

$(LIBFT):
	@$(MAKE) -s -C $(LIBFT_DIR) all
	@echo $(COLOR_GREEN) "Compile 'libft.a' completed!" $(COLOR_RESET)

clean:
	@$(MAKE) -s -C $(LIBFT_DIR) clean
	@rm -rf $(OBJS)
	@echo $(COLOR_RED) "'$(NAME)'s objective files are removed!" $(COLOR_RESET)

fclean:
	@$(MAKE) -s -C $(LIBFT_DIR) fclean
	@rm -rf $(OBJS)
	@rm -rf $(NAME)
	@rm -rf $(LIB) ./readline/readline
	@echo $(COLOR_RED) "Program '$(NAME)' has removed!" $(COLOR_RESET)

re : fclean all

syildiri: $(LIBFT)
	$(CC) $(SANITIZER) $(CFLAG) $(syildiri_LIB_FLAG) $(syildiri_INC_FLAG) $(SRCS) -o $@ -lft -lreadline

jclean : fclean
	@rm -rf syildiri.dSYM
	@rm -rf syildiri

debug: $(LIBFT)
	$(CC) $(CFLAG) $(LIBRARIES) $(SANITIZER) $(INCLUDES) $(SRCS) -o $@ -lft -lreadline

dclean:
	@$(MAKE) -s -C $(LIBFT_DIR) fclean
	@rm -rf debug
	@rm -rf debug.dSYM

.PHONY: all clean fclean re debug syildiri
