# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/04 11:04:36 by trakotoz          #+#    #+#              #
#    Updated: 2026/02/25 11:47:45 by trakotoz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

# Color for output
C_RESET		= \033[0m
C_GREEN		= \033[032m
C_BLUE		= \033[034m
C_MAGNETA	= \033[035m

DIR_LIBFT	= ./libft
FILELIB		= libft.a
LIBFT		= $(DIR_LIBFT)/$(FILELIB)

AR		= ar rcs
CC		= cc
CFLAGS 	= -Wall -Wextra -Werror
RM		= rm -rf

# All sources divided into categories
UTILS		= ft_print_unsigned ft_print_hex ft_print_ptr ft_utils ft_other_utils
MANDATORY	= $(UTILS) ft_printf

OBJ_DIR 	= obj
SRC_DIR 	= src

OBJECTS			= $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(MANDATORY)))

all		: $(NAME)

clean	:
	@$(MAKE) clean -sC $(DIR_LIBFT)
	@$(RM) $(OBJ_DIR)
	@echo "${C_BLUE}Libft and Libftprintf clean${C_RESET}"

fclean	: clean
	@$(MAKE) fclean -sC $(DIR_LIBFT)
	@$(RM) $(NAME)
	@echo "${C_MAGNETA}Libft and Libftprintf fclean${C_RESET}"

re		: fclean all


$(NAME)			: $(OBJECTS) $(LIBFT)
	@cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJECTS)
	@echo "${C_GREEN}Build ft_printf${C_RESET}"

$(OBJ_DIR)/%.o	: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)		:
	@mkdir -p $(OBJ_DIR)

$(LIBFT) 		:
	$(MAKE) -C $(DIR_LIBFT)


.PHONY : all clean fclean re bonus
