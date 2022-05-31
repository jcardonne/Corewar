##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC	=	src/main.c \
		src/process.c \
		src/labels/getter.c \
		src/labels/replacer.c \
		src/labels/list.c \
		src/labels/runner.c \
		src/writer/buffer.c \
		src/writer/write.c \
		src/parser/checker.c \
		src/parser/commands.c \
		src/parser/commands_two.c \
		src/parser/commands_three.c \
		src/parser/commands_labels.c \
		src/parser/commands_args.c \
		src/parser/tools.c \
		src/parser/metadata_keys.c \
		src/parser/metadata.c \
		src/init/data.c \
		src/utils/reader.c \
		src/utils/strings.c \

TEST_FILES = tests/file_diff.c \

OBJ    =    $(SRC:.c=.o)

NAME =     asm

INCDIR = include

LIB = lib/my

CFLAGS = -I $(INCDIR)

all: $(NAME)

$(NAME):    $(OBJ)
		make -C lib/my
		gcc -o $(NAME) $(OBJ) $(CFLAGS) -L"lib/" -lmy

make_lib:
		make -C lib/my

clean:
		make clean -C lib/my
		rm -rf $(OBJ)

fclean:        clean
		make clean -C lib/my
		rm -rf $(NAME)

tests_run: fclean make_lib
			gcc -I$(INCDIR) -I/opt/homebrew/include -o unit_tests $(TEST_FILES) -L$(LIB) -lmy\
			--coverage -L/opt/homebrew/lib -lcriterion
			./unit_tests

re:		fclean all

.PHONY:		all clean fclean re make_lib
