# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/10/14 15:21:40 by lvergero          #+#    #+#              #
#    Updated: 2014/11/06 21:06:01 by lvergero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name
NAME 		=	test

# General Options
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
IFLAGS		=	-I $(P_LIB)includes
CLIBFLAGS	=	-L $(P_LIB) -lft
RM			=	/bin/rm

# Directories
P_SRC	=	./
P_OBJ	=	./
P_LIB	=	./../../

# Files
SRCS 	+=	$(P_SRC)main.c
OBJS 	+=	$(subst .c,.o,$(subst $(P_SRC),$(P_OBJ),$(SRCS)))
LIB		=	$(P_LIB)libft.a

# Display
MSG_GREEN	=	\033[1;33;32m
MSG_YELLOW	=	\033[1;33;33m
MSG_BOLD	=	\033[1m
MSG_STD 	=	\033[0m
CLEAR		=	\033[2K
UP 			=	\033[A

#Rules
all:			$(NAME)

$(NAME):		$(OBJS) $(LIB)
	@echo "$(MSG_BOLD)\nLinking to binary$(MSG_STD)"
	@$(CC) -o $@ $< $(CLIBFLAGS)
	@echo "$(MSG_BOLD)SUCCESS$(MSG_STD)"

$(P_OBJ)%.o:	$(P_SRC)%.c
	@echo "$(CLEAR)Currently pre-processing, compiling and assembling $(MSG_YELLOW)$<$(MSG_STD) to $(MSG_GREEN)$@$(MSG_STD)$(UP)"
	@$(CC) -o $@ -c $< $(IFLAGS)

clean:
	@echo "$(MSG_BOLD)Removing .o$(MSG_STD)"
	@$(RM) -f $(OBJS)

fclean:			clean
	@echo "$(MSG_BOLD)Removing all$(MSG_STD)"
	@$(RM) -f $(NAME)

$(LIB):
	make -C $(P_LIB)

re: 			fclean all
