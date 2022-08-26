# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amenadue <amenadue@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/26 10:21:04 by amenadue          #+#    #+#              #
#    Updated: 2022/08/26 10:34:34 by amenadue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

SRCDIR	=	src/

SRC		=	

LIBS	=	libft

LIBINC	=	$(foreach lib,$(LIBS),-I$(lib) -L$(lib) -l$(subst lib,,$(lib)))

all:
	@$(foreach lib,$(LIBS),$(MAKE) all -s -C $(lib) || { printf "\e[91mError Compiling '$(lib)'\e[0m\n"; exit 1; };)
	@$(MAKE) $(NAME) -s || { printf "\e[91mError Compiling '$(NAME)'.\e[0m\n"; exit 1; }

$(NAME):
	$(CC) $(CCFLAGS) $(foreach file,$(SRC),$(SRCDIR)$(SRC)) $(LIBINC) -o $(NAME)

clean:
	$(foreach lib,$(LIBS),$(MAKE) clean -s -C $(lib);)

fclean:
	$(foreach lib,$(LIBS),$(MAKE) fclean -s -C $(lib);)
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re