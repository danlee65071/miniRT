# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/20 17:37:32 by hcharlsi          #+#    #+#              #
#    Updated: 2021/04/20 17:37:35 by hcharlsi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c \
					ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c \
					ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
					ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c \
					ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
					ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c \
					ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
					ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c \
					ft_putendl_fd.c ft_putnbr_fd.c

BONUS			= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
					ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
					ft_lstiter.c ft_lstmap.c

OBJS			= $(SRCS:.c=.o)
BONUS_OBJS		= $(BONUS:.c=.o)
HEADER			= libft.h

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= libft.a

GREEN = \033[0;32m
RESET = \033[0m

.c.o:
	gcc $(CFLAGS) -c $< -I ${HEADER} -o ${<:.c=.o}
	@echo "$(GREEN).$(RESER)\c"

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)
				@echo "$(GREEN)......$(RESER)\c"

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

bonus:			$(OBJS) $(BONUS_OBJS)
				ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY:			all clean fclean re bonus


