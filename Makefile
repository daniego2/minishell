#############
# VARIABLES #
#############

NAME := minishell
CC := gcc
FLAGS := -g -lreadline -Wall -Wextra -Werror 
RM := rm -f

INCLUDES = -I libft -I headers/exec -I headers/parser -I headers/built-ins

SRCS := \
	src/parser/DO_NOT_PRESENT_testing.c \
	src/main.c \
	src/main_helper.c \
	\
	src/exec/get_env.c \
	src/exec/memory_cleaner.c \
	src/exec/list_manager.c \
	src/exec/assemble_env.c \
	src/exec/exec.c \
	src/exec/exec_utils.c \
	src/exec/exec_fork.c \
	src/exec/redirections.c \
	src/exec/signal.c \
	src/exec/signal_hd.c \
	src/exec/ascii.c \
	src/exec/here_doc.c \
	\
	src/built-ins/builtins_utils.c \
	src/built-ins/pwd.c \
	src/built-ins/echo.c \
	src/built-ins/env.c \
	src/built-ins/export.c \
	src/built-ins/export_utils.c \
	src/built-ins/unset.c \
	src/built-ins/cd.c \
	src/built-ins/exit.c \
	\
	src/parser/exit.c \
	src/parser/free.c \
	src/parser/parser.c \
	src/parser/parser_helper.c \
	src/parser/prompt.c \
	src/parser/quotes_and_expansion.c \
	src/parser/quotes_and_expansion_helper.c \
	src/parser/redirs.c \
	src/parser/tokenizer.c \
	src/parser/tokenizer_helper.c \
	src/parser/utils1.c \
	src/parser/utils2.c \
	src/parser/utils_strings.c \
	src/parser/variable_expansion.c \
	\
	libft/ft_atoi.c \
	libft/ft_bzero.c \
	libft/ft_calloc.c \
	libft/ft_isalnum.c \
	libft/ft_isalpha.c \
	libft/ft_isascii.c \
	libft/ft_isdigit.c \
	libft/ft_isprint.c \
	libft/ft_itoa.c \
	libft/ft_lstadd_back_bonus.c \
	libft/ft_lstadd_front_bonus.c \
	libft/ft_lstclear_bonus.c \
	libft/ft_lstdelone_bonus.c \
	libft/ft_lstiter_bonus.c \
	libft/ft_lstlast_bonus.c \
	libft/ft_lstmap_bonus.c \
	libft/ft_lstnew_bonus.c \
	libft/ft_lstsize_bonus.c \
	libft/ft_memchr.c \
	libft/ft_memcmp.c \
	libft/ft_memcpy.c \
	libft/ft_memmove.c \
	libft/ft_memset.c \
	libft/ft_putchar_fd.c \
	libft/ft_putendl_fd.c \
	libft/ft_putnbr_fd.c \
	libft/ft_putstr_fd.c \
	libft/ft_split.c \
	libft/ft_strchr.c \
	libft/ft_strdup.c \
	libft/ft_striteri.c \
	libft/ft_strjoin.c \
	libft/ft_strlcat.c \
	libft/ft_strlcpy.c \
	libft/ft_strlen.c \
	libft/ft_strmapi.c \
	libft/ft_strncmp.c \
	libft/ft_strcmp.c \
	libft/ft_strnstr.c \
	libft/ft_strrchr.c \
	libft/ft_strtrim.c \
	libft/ft_substr.c \
	libft/ft_tolower.c \
	libft/ft_toupper.c \
	libft/ft_isspace.c \
	libft/ft_strmatch.c \
	libft/ft_strncpy.c

OBJS := $(SRCS:.c=.o)

ESC         := $(shell printf '\033')
RED		    := $(ESC)[1;31m
GREEN		:= $(ESC)[1;32m
YELLOW		:= $(ESC)[1;33m
BLUE		:= $(ESC)[1;34m
CYAN 		:= $(ESC)[1;36m
CLR_RMV		:= $(ESC)[0m

#########
# RULES #
#########

.c.o:
	@${CC} ${FLAGS} $(INCLUDES) -c $< -o ${<:.c=.o}
	@echo "${BLUE}$@ ${GREEN}compiled.${CLR_RMV}"

${NAME}: ${OBJS}
	@${CC} ${FLAGS} -o ${NAME} ${OBJS} -lreadline
	@echo "${CYAN}$(NAME) ${GREEN}linked ✔️${CLR_RMV}"

compilation_start_message:
	@echo "$(GREEN)Compiling ${CYAN}$(NAME)...${CLR_RMV}"

all: compilation_start_message ${NAME}

bonus: all

clean:
	@ ${RM} $(SRCS:.c=.o)
	@ echo "$(CYAN)$(NAME) $(BLUE)object files $(RED)deleted ✔️"

fclean: clean
	@ ${RM} ${NAME}
	@ echo "$(CYAN)$(NAME) $(BLUE)binary $(RED)deleted ✔️"

re: fclean all

.PHONY:	all bonus clean fclean re
