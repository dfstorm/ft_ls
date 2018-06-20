PROJECT = ft_ls
NAME = $(PROJECT)

C_FILES += src/main.c\
src/flags.c\
src/debug.c\
src/errors.c\
src/utils.c\
src/print_file.c\
src/print_dir.c

LIBFT = ./libft/libft.a
LIBFTC = libft/
CC = gcc
CFLAGS += -o


all:
	make -C $(LIBFTC)
	$(CC) $(CFLAGS) $(NAME) $(C_FILES) $(LIBFT);
test: all
	./$(NAME) .
clean:
	/bin/rm $(NAME)
re: clean all


