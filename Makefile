# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/26 10:21:04 by amenadue          #+#    #+#              #
#    Updated: 2022/09/28 08:15:48 by amenadue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

SRCDIR	=	src/

SRC		=	main.c \
			instruction/*.c \
			ps_stack_utils.c \
			ps_stack_utils_1.c \
			ps_stack_debug.c \
			ps_sort.c

LIBS	=	libft

LIBINC	=	$(foreach lib,$(LIBS),-I$(lib) -L$(lib) -l$(subst lib,,$(lib)))

################

CC		=	gcc

CCFLAGS	=	-Wall -Werror -Wextra -D DEBUG

init: re

all:
	@$(foreach lib,$(LIBS),$(MAKE) all -s -C $(lib) || { printf "\e[91mError Compiling '$(lib)'\e[0m\n"; exit 1; };)
	@$(MAKE) $(NAME) -s || { printf "\e[91mError Compiling '$(NAME)'.\e[0m\n"; exit 1; }
	@printf "\n\e[1mUsage:\e[0m\n"
	@printf "./$(NAME) <int> ...   Input a list of integers to sort\n"
	@printf "./$(NAME) -t          Runs all the different operations and dumps the stacks in terminal.\n"

$(NAME):
	$(CC) $(CCFLAGS) $(foreach file,$(SRC),$(SRCDIR)$(file)) $(LIBINC) -o $(NAME)

clean:
	$(foreach lib,$(LIBS),$(MAKE) clean -s -C $(lib);)

fclean:
	$(foreach lib,$(LIBS),$(MAKE) fclean -s -C $(lib);)
	rm -f $(NAME)

re:	fclean all

run:
	ARGS="16 1 13 19 15 12 21 10 11 7 17 6 3 5 9 18 20 8 2 4 14 -16 -1 -13 -19 -15 -12 -21 -10 -11 -7 -17 -6 -3 -5 -9 -18 -20 -8 -2 -4 -14"
	@./${NAME} $ARGS | ./checker_linux $ARGS


.PHONY: all clean fclean re run