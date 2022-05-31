##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC	=	src/main.c \
		src/commands/tools.c \
		src/commands/manager.c \
		src/cycle/loop.c \
		src/cycle/instructions.c \
		src/cycle/writer.c \
		src/cycle/mnemomic.c \
		src/cycle/mnemomic_two.c \
		src/cycle/mnemomic_three.c \
		src/cycle/mnemomic_four.c \
		src/cycle/mnemomic_tools.c \
		src/init/error_handling.c \
		src/init/init_data.c \
		src/init/init_data_two.c \
		src/handle_args/handle_load_adress.c \
		src/handle_args/handle_prog_number.c \
		src/champions/placer.c \
		src/champions/parser.c \
		src/champions/tools.c \
		src/champions/manager.c \
		src/decimals/tools.c \
		src/utils/hex_to_decimal.c \
		src/utils/strings.c \
		src/utils/numbers.c \
		src/utils/error_exit.c \

OBJ    =    $(SRC:.c=.o)

NAME =     corewar

INCDIR = include

CFLAGS = -I $(INCDIR) -g

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

re:		fclean all

.PHONY:		all clean fclean re make_lib
