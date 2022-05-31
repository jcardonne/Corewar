##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

all:
	make -C asm/
	make -C corewar/

clean:
	make clean -C asm/
	make clean -C corewar/

fclean:
	make fclean -C asm/
	make fclean -C corewar/

re:		fclean	all

.PHONY:		all clean fclean re
