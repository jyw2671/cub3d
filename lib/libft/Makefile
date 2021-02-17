# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/17 22:35:39 by yjung             #+#    #+#              #
#    Updated: 2021/02/17 22:35:42 by yjung            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

AR = ar
ARFLAGS = crs

CC = gcc
CFLAGS = -Wall -Wextra -Werror

RM = rm
RMFLAGS = -f

INC_DIR = include
SRC_DIR = src
OBJ_DIR = obj

HEADERS = $(addprefix $(INC_DIR)/, \
	libft.h	\
	ft_string.h	\
	ft_libft_type.h	\
	ft_math.h	\
	ft_memory.h	\
	get_next_line.h	\
)

SRC_MATH_DIR = $(SRC_DIR)/math
SRC_MATH = $(addprefix $(SRC_MATH_DIR)/, \
	ft_pow.c	\
	ft_max.c	\
)

SRC_MEMORY_DIR = $(SRC_DIR)/memory
SRC_MEMORY = $(addprefix $(SRC_MEMORY_DIR)/, \
	ft_memcpy.c	\
	ft_memmove.c	\
	ft_memset.c	\
)

SRC_STRING_DIR = $(SRC_DIR)/string
SRC_STRING = $(addprefix $(SRC_STRING_DIR)/, \
	ft_strchr.c	\
	ft_strjoin.c	\
	ft_strlen.c	\
	ft_strndup.c	\
	ft_split_cnt	\
	ft_strndup.c	\
)

SRC_GNL_DIR = $(SRC_DIR)/get_next_line
SRC_GNL = $(addprefix $(SRC_GNL_DIR)/, \
	get_next_line.c	\
)

SRCS = \
	$(SRC_MATH)	\
	$(SRC_MEMORY)	\
	$(SRC_STRING)	\
	$(SRC_GNL)

vpath %.c \
	$(SRC_DIR)	\
	$(SRC_MATH_DIR)	\
	$(SRC_MEMORY_DIR)	\
	$(SRC_STRING_DIR)	\
	$(SRC_GNL_DIR)

OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

all : $(NAME)

clean :
	@$(RM) $(RMFLAGS) $(OBJS) $(OBJS_BONUS)

fclean : clean
	@$(RM) $(RMFLAGS) $(NAME)

re : fclean all

$(OBJ_DIR)/%.o : %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CDEBUG) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(NAME) : $(HEADERS) $(OBJS)
	@$(AR) $(ARFLAGS) $@ $(OBJS)

.PHONY: all clean fclean re