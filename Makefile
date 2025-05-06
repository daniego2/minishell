#  |  |  ___ \    \  |         |
#  |  |     ) |  |\/ |   _  |  |  /   _ 
# ___ __|  __/   |   |  (   |    <    __/ 
#    _|  _____| _|  _| \__,_| _|\_\ \___|
#                              by jcluzet
################################################################################
#                                     CONFIG                                   #
################################################################################

NAME        := minishell
CC        := gcc
FLAGS    := -g -lreadline #-Wall -Wextra -Werror 
################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

INCLUDES = -I libft -I header/exec -I header/parser -I header/built-ins

SRCS        :=     src/exec/get_env.c \
					src/exec/memory_cleaner.c \
					src/exec/list_manager.c \
					src/exec/assemble_env.c \
					src/exec/exec.c \
					src/exec/exec_utils.c \
                    src/exec/exec_fork.c \
                    src/exec/redirections.c \
                    src/exec/signal.c \
					src/exec/ascii.c \
					src/exec/here_doc.c \
					src/built-ins/builtins_utils.c \
					src/built-ins/pwd.c \
					src/built-ins/echo.c \
					src/built-ins/env.c \
					src/built-ins/export.c \
                    src/built-ins/export_utils.c \
					src/built-ins/unset.c \
					src/built-ins/cd.c \
					src/built-ins/exit.c \
					src/parser/exit.c \
                    src/parser/free.c \
                    src/parser/parser.c \
                    src/parser/parser_helper.c \
                    src/parser/parser_main.c \
                    src/parser/prompt.c \
                    src/parser/quotes_and_expansion.c \
                    src/parser/quotes_and_expansion_helper.c \
                    src/parser/redirs.c \
                    src/parser/DO_NOT_PRESENT_testing.c \
                    src/parser/tokenizer.c \
                    src/parser/tokenizer_helper.c \
                    src/parser/utils1.c \
                    src/parser/utils2.c \
                    src/parser/utils_strings.c \
                    src/parser/variable_expansion.c \
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
						  libft/ft_strncpy.c \
                          
OBJS        := $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} $(INCLUDES) -c $< -o ${<:.c=.o}

################################################################################
#                                  Makefile  objs                              #
################################################################################


CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM		    := rm -f

${NAME}:	${OBJS}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			${CC} ${FLAGS} -o ${NAME} ${OBJS} -lreadline
			@echo "$(GREEN)$(NAME) created[0m ✔️"

all:		${NAME}

bonus:		all

clean:
			@ ${RM} *.o */*.o */*/*.o
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:		clean
			@ ${RM} ${NAME}
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:			fclean all

.PHONY:		all clean fclean re
