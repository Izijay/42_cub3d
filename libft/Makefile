# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: raph <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/14 15:30:50 by raph              #+#    #+#              #
#    Updated: 2021/12/07 14:21:34 by ranuytte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libft.a
SRCS = ft_isalpha.c \
	   ft_isdigit.c \
	   ft_isalnum.c \
	   ft_isascii.c \
	   ft_isprint.c \
	   ft_strlen.c \
	   ft_memset.c \
	   ft_bzero.c \
	   ft_memcpy.c \
	   ft_memmove.c \
	   ft_strlcpy.c \
	   ft_strlcat.c \
	   ft_toupper.c \
	   ft_tolower.c \
	   ft_strchr.c \
	   ft_strrchr.c \
	   ft_strncmp.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   ft_strnstr.c \
	   ft_atoi.c \
	   ft_calloc.c \
	   ft_strdup.c \
	   ft_substr.c \
	   ft_strjoin.c \
	   ft_strtrim.c \
	   ft_split.c \
	   ft_itoa.c \
	   ft_strmapi.c \
	   ft_striteri.c \
	   ft_putchar_fd.c \
	   ft_putstr_fd.c \
	   ft_putendl_fd.c \
	   ft_putnbr_fd.c \
	   ft_strnew.c \
	   ft_memalloc.c \
	   ft_strdel.c \
	   get_next_line.c

SRCS_BONUS = ft_lstnew.c \
			 ft_lstadd_front.c \
			 ft_lstsize.c \
			 ft_lstlast.c \
			 ft_lstadd_back.c \
			 ft_lstdelone.c \
			 ft_lstclear.c \
			 ft_lstiter.c \
			 ft_lstmap.c \
			 ft_print_list \
			 ft_print_reverse_list

CC = gcc

CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRCS:.c=.o)

OBJ_BONUS = $(SRCS_BONUS:.c=.o)

INCLUDE = libft.h

ifdef WITH_BONUS
	OBJ_FILES = $(OBJ) $(OBJ_BONUS)
else
	OBJ_FILES = $(OBJ)
endif

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar rc $(NAME) $(OBJ_FILES)

bonus: 
	$(MAKE) WITH_BONUS=1 all

clean:
	rm -rf $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
