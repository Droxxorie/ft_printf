# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eraad <eraad@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/06 14:33:34 by eraad             #+#    #+#              #
#    Updated: 2025/01/07 16:03:08 by eraad            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables

NAME		= libftprintf.a
INCLUDES	= include
SRCS_DIR	= sources/
CC			= cc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror -I$(INCLUDES)
AR			= ar rcs

#Colors
DEF = \033[0m
Y = \033[0;93m
G = \033[0;92m
R = \033[0;91m

#Sources

SRC_FILES	= ft_printf ft_putaddr ft_puthexa_tolower ft_puthexa_toupper ft_putunbr ft_putstr_fd ft_putnbr_fd ft_putchar_fd
SRCS		= $(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS		= $(SRCS:.c=.o)

TEST_SRC	= main.c
TEST_OBJ	= $(TEST_SRC:.c=.o)
TEST_EXEC	= test

#Rules

.c.o:
				@$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
				@echo "$(Y)- Creating $(NAME)...$(DEF)"
				@$(AR) $(NAME) $(OBJS)
				@echo "$(G)--- ft_printf compiled succesfully! ---$(DEF)"

clean:
				@echo "$(Y)- Cleaning object files...$(DEF)"
				@$(RM) $(OBJS)
				@echo "$(R)- Object files cleaned!$(DEF)"

fclean: clean
				@echo "$(Y)- Cleaning all build files...$(DEF)"
				@$(RM) $(NAME)
				@echo "$(R)- All build files cleaned!$(DEF)"

re: fclean $(NAME)

test: $(NAME) $(TEST_OBJ)
				@$(CC) $(CFLAGS) -o $(TEST_EXEC) $(TEST_OBJ) -L. -lftprintf
				@echo "$(Y)- Running test...$(DEF)"
				@./$(TEST_EXEC)
				@echo "$(G)--- Test done! ---$(DEF)"
				@echo "$(Y)- Cleaning test files...$(DEF)"
				@$(RM) $(TEST_OBJ) $(TEST_EXEC)
				@$(RM) $(OBJS)
				@$(RM) $(NAME)
				@echo "$(R)- Files cleaned !$(DEF)"

.PHONY: all clean fclean re test