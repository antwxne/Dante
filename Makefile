##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

all:
	make -C generator/
	make -C solver/

clean:
	make clean -C generator/
	make clean -C solver/


fclean:	clean
	make fclean -C generator/
	make fclean -C solver/

debug:
	make debug -C generator/
	make debug -C solver/

re: fclean all

.PHONY: all fclean re clean debug
