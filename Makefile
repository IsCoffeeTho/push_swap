# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amenadue <amenadue@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/26 10:21:04 by amenadue          #+#    #+#              #
#    Updated: 2022/08/26 12:23:58 by amenadue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

SRCDIR	=	src/

SRC		=	main.c \
			ps_stack_utils.c \
			ps_stack_debug.c \
			ps_sort.c

LIBS	=	libft

LIBINC	=	$(foreach lib,$(LIBS),-I$(lib) -L$(lib) -l$(subst lib,,$(lib)))

init: re

all:
	@$(foreach lib,$(LIBS),$(MAKE) all -s -C $(lib) || { printf "\e[91mError Compiling '$(lib)'\e[0m\n"; exit 1; };)
	@$(MAKE) $(NAME) -s || { printf "\e[91mError Compiling '$(NAME)'.\e[0m\n"; exit 1; }

$(NAME):
	$(CC) $(CCFLAGS) $(foreach file,$(SRC),$(SRCDIR)$(file)) $(LIBINC) -o $(NAME)

clean:
	$(foreach lib,$(LIBS),$(MAKE) clean -s -C $(lib);)

fclean:
	$(foreach lib,$(LIBS),$(MAKE) fclean -s -C $(lib);)
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re