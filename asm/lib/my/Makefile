##
## EPITECH PROJECT, 2021
## MAKEFILE
## File description:
## Makefile
##

SRC    =    my_char_isprintable.c \
		my_get_nbr_base.c \
		my_itoa.c \
		my_put_nbr.c \
		my_rev_str_list.c \
		my_strcat.c \
		my_str_islower.c \
		my_strlowcase.c \
		my_strupcase.c \
		my_compute_rec.c \
		my_getnbr.c \
		my_nbrlen.c \
		my_put_str_arr.c \
		my_showstr.c \
		my_strcmp.c \
		my_str_isnum.c \
		my_strncat.c \
		my_swap.c \
		my_compute_square_root.c \
		my_putchar.c \
		my_putstr.c \
		my_sort_int_array.c \
		my_strcpy.c \
		my_str_isprintable.c \
		my_strncmp.c \
		my_swap_char.c \
		my_arr_size.c \
		my_contain_str_arr.c \
		my_isneg.c \
		my_put_err.c \
		my_putstr_two.c \
		my_sort_str_array.c \
		my_strdup.c \
		my_str_isupper.c \
		my_strncpy.c \
		my_to_lowercase.c \
		my_char_is_nbr.c \
		my_find_prime_sup.c \
		my_is_prime.c \
		my_putnbr_base.c \
		my_revstr.c \
		my_strcapitalize.c \
		my_str_isalpha.c \
		my_strlen.c \
		my_strstr.c \

OBJ	=	$(SRC:.c=.o)

NAME = libmy.a

all: $(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)
		cp $(NAME) ../
		cp my.h ../../include

clean:
		rm -rf $(OBJ)

fclean:		clean
		rm -rf $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
