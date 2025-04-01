CC = clang
NAME = parser
BUILD_DIR = build
SRC_DIR = src/parser
HEADERS_DIR = headers/parser
MODE ?= prod
CFLAGS_prod = -Wall -Wextra -Werror
CFLAGS_dev = -Wall -Wextra -Wunreachable-code -MMD -MP -g
CFLAGS = $(CFLAGS_$(MODE))
INCLUDES = -I$(HEADERS_DIR)
LDFLAGS = 

# WARNING: Make .c files explicit
SOURCES = $(wildcard $(SRC_DIR)/*.c)

OBJECTS = $(addprefix $(BUILD_DIR)/, $(notdir $(SOURCES:.c=.o)))

all: info $(NAME)
	@echo ------------------------

-include $(OBJECTS:.o=.d)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<
	@echo "Compiled: $@."

$(NAME): $(OBJECTS)
	@$(CC) $(OBJECTS) $(LDFLAGS) -o $(NAME)
	@echo "Linked: $@."

clean:
	@rm -rf $(BUILD_DIR)

fclean:
	@$(MAKE) clean
	@rm -rf $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all

info:
	@echo --INFO------------------
	@echo MODE=$(MODE)
	@echo CFLAGS= $(CFLAGS)
	@echo LDFLAGS= $(LDFLAGS)
	@echo ------------------------

.PHONY: all clean fclean re info