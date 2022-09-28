# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/26 10:21:04 by amenadue          #+#    #+#              #
#    Updated: 2022/09/28 18:38:06 by amenadue         ###   ########.fr        #
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

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	CHECKER = checker_linux
endif
ifeq ($(UNAME_S),Darwin)
	CHECKER = checker_Mac
endif

init: re

all:
	@$(foreach lib,$(LIBS),$(MAKE) all -s -C $(lib) || { printf "\e[91mError Compiling '$(lib)'\e[0m\n"; exit 1; };)
	@$(MAKE) $(NAME) -s || { printf "\e[91mError Compiling '$(NAME)'.\e[0m\n"; exit 1; }
	@printf "\n\e[1mUsage:\e[0m\n"
	@printf "./$(NAME) <int> ...   Input a list of integers to sort\n"

$(NAME):
	$(CC) $(CCFLAGS) $(foreach file,$(SRC),$(SRCDIR)$(file)) $(LIBINC) -o $(NAME)

clean:
	$(foreach lib,$(LIBS),$(MAKE) clean -s -C $(lib);)

fclean:
	$(foreach lib,$(LIBS),$(MAKE) fclean -s -C $(lib);)
	rm -f $(NAME)

re:	fclean all

TEST1=16 1 13 19 15 12 21 10 11 7 17 6 3 5 9 18 20 8 2 4 14
TEST2=-16 -1 -13 -19 -15 -12 -21 -10 -11 -7 -17 -6 -3 -5 -9 -18 -20 -8 -2 -4 -14
TEST3=3 6 -19 -5 8 -13 12 4 0 16 -20 -17 -16 19 18 -6 -3 2 -14 -7 -8 9 10 13 -10 5 -12 7 -1 20 -4 11 -9 17 14 -11 -18 -2 1 -15 15 -21 21
TEST5=2 4 3 1
TEST5=1 11 19 5 14 45 4 16 27 15 48 2 47 3 30 17 31 13 38 35 43 36 10 24 22 34 6 32 42 7 12 40 49 41 23 50 25 29 46 33 8 28 37 39 18 21 9 20 26 44
TEST6=38 86 93 58 2 82 85 44 97 6 37 33 56 29 55 79 62 71 61 18 46 15 9 43 77 98 50 53 39 25 69 78 87 100 8 19 13 67 81 10 74 27 3 35 17 66 31 89 26 75 48 54 49 5 1 52 32 96 41 83 64 47 68 91 92 42 12 88 23 84 30 22 80 21 90 63 94 20 11 73 99 76 72 59 28 14 65 70 60 51 57 34 40 36 24 95 45 16 4 7
TEST7=-3 4 -10 8 10 -17 -30 2 -7 11 3 9 -14 -9 6 -5 -21 7 -28 15 -8 -23 -19 -16 -4 16 -12 -18 -22 -32 -31 5 13 -11 -29 -24 -25 0 -27 1 -1 -26 -13 -2 12 14 -20 -6 -15
run:
	@printf "Running push_swap to checker:\n"
	@printf "POSITIVE: "
	@./${NAME} $(TEST1) | ./$(CHECKER) $(TEST1)
	@printf "NEGATIVE: "
	@./${NAME} $(TEST2) | ./$(CHECKER) $(TEST2)
	@printf "BOTH: "
	@./${NAME} $(TEST3) | ./$(CHECKER) $(TEST3)
	@printf "SMALL: "
	@./${NAME} $(TEST4) | ./$(CHECKER) $(TEST4)
	@printf "BIG 50: "
	@./${NAME} $(TEST5) | ./$(CHECKER) $(TEST5)
	@printf "BIG 100: "
	@./${NAME} $(TEST6) | ./$(CHECKER) $(TEST6)
	@printf "BIGGER NEG: "
	@./${NAME} $(TEST7) | ./$(CHECKER) $(TEST7)


.PHONY: all clean fclean re run