C_FILES = main.c

PROJECT = ft_ls
NAME = $(PROJECT).a
CC = gcc
CLANGS = -g -Wall -Werror -Wextra

SRC_PATH = ./src/
INC_PATH = ./includes/
OBJ_PATH = ./obj/

OBJ_NAME = $(C_FILES:.c=.o)

SRC = $(addprefix $(SRC_PATH),$(C_FILES))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)/%.c
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(NAME): $(OBJ)
	@ar -rc $(NAME) $^
	@ranlib $(NAME)

clean:
	/bin/rm -rf $(OBJ_PATH)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all