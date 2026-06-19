# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/16 09:04:21 by trakotoz          #+#    #+#              #
#    Updated: 2026/02/26 11:47:32 by trakotoz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= push_swap
NAME_BONUS	= checker

C_RESET		= \033[0m
C_GREEN		= \033[032m
C_BLUE		= \033[034m
C_MAGNETA	= \033[035m

DIR_LIB			= ft_printf
LIBFTPRINTF		= $(DIR_LIB)/libftprint.a

UTILS		= command_push_swap command_rotate command_reverse \
			compute_disorder utils managements \

MANDATORY	= $(UTILS) main push_swap \
			parsing take_command \
			adaptive_sort minmax_sort \
			chunk_based_sort radix_lsd_sort chunk_based_sort_utils \
			benchmark benchmark_utils strategy_management \
			other

BONUS		= $(UTILS) main_bonus parsing_bonus \
			  get_next_line_bonus get_next_line_utils_bonus \
			  checker_bonus utils_bonus

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

RM = rm -rf

OBJ_DIR = obj

OBJECTS			= $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(MANDATORY)))
OBJECTS_BONUS	= $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(BONUS)))

all : $(NAME)

$(NAME) : $(OBJECTS) $(LIBFTPRINTF)
	$(CC) $(CFLAGS) $(OBJECTS) -L$(DIR_LIB) -lftprintf -o $(NAME) 
	@echo "${C_GREEN}Build Push_swap${C_RESET}"

$(OBJ_DIR)/%.o : %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $@

$(LIBFTPRINTF):
	$(MAKE) -C $(DIR_LIB)

clean :
	@$(MAKE) clean -sC $(DIR_LIB)
	@$(RM) $(OBJ_DIR)
	@echo "${C_BLUE}Clean objects files${C_RESET}"

fclean : clean
	@$(MAKE) fclean -sC $(DIR_LIB)
	@$(RM) $(NAME) $(NAME_BONUS)
	@echo "${C_MAGNETA}Clean all generated files${C_RESET}"

re : fclean all

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(OBJECTS_BONUS) $(LIBFTPRINTF)
	$(CC) $(CFLAGS) $(OBJECTS_BONUS) -L$(DIR_LIB) -lftprintf -o $(NAME_BONUS) 
	@echo "${C_GREEN}Build Checker (bonus part)${C_RESET}"

.PHONY : all clean fclean re
