# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/11 20:52:36 by bwan-nan          #+#    #+#              #
#    Updated: 2019/02/11 22:15:54 by bwan-nan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIB = $(LPATH)libft.a
LIBDB = $(LPATH)libftdb.a
EXEC = ft_printf

CC = Clang
COMPILE = $(CC) -c

vpath %.c src/
vpath %.h inc/

#Reset
NC=\033[0m

# Regular Colors
BLACK=\033[0;30m
RED=\033[0;31m
GREEN =\033[32m
YELLOW=\033[0;33m
BLUE=\033[0;34m
PURPLE=\033[0;35m
CYAN=\033[0;36m
WHITE=\033[0;37m

MKDIR = mkdir -p
CLEANUP = rm -rf

#WFLAGS += -Wall
#WFLAGS += -Werror
#WFLAGS += -Wextra
DFLAGS = -fsanitize=address
IFLAGS = -I $(IPATH)
CFLAGS = $(WFLAGS) $(IFLAGS)

OPATH = obj/
SPATH = src/
IPATH = inc/
LPATH = lib/

INCS = ft_printf.h

SRCM = main.c
SRCS += ft_printf.c
SRCS += ft_print_s.c
SRCS += ft_llitoa.c
SRCS += ft_llitoa_base.c
SRCS += ft_ullitoa.c
SRCS += ft_ullitoa_base.c
SRCS += ft_ftoa.c
SRCS += parsing.c
SRCS += ft_recursive_power.c


#--------------------Memory--------------------#
SRCS += ft_bzero.c
SRCS += ft_memalloc.c
SRCS += ft_memmove.c
SRCS += ft_memchr.c
SRCS += ft_memcmp.c
SRCS += ft_memcpy.c
SRCS += ft_memccpy.c
SRCS += ft_memdel.c
SRCS += ft_memset.c

#--------------------Strings---------------------#
SRCS += ft_isalnum.c
SRCS += ft_isalpha.c
SRCS += ft_isascii.c
SRCS += ft_isdigit.c
SRCS += ft_isprint.c
SRCS += ft_strcat.c
SRCS += ft_strchr.c
SRCS += ft_strcmp.c
SRCS += ft_strcpy.c
SRCS += ft_strdup.c
SRCS += ft_strlcat.c
SRCS += ft_strlen.c
SRCS += ft_strncat.c
SRCS += ft_strncmp.c
SRCS += ft_strncpy.c
SRCS += ft_strnstr.c
SRCS += ft_strrchr.c
SRCS += ft_strstr.c
SRCS += ft_strclr.c
SRCS += ft_strdel.c
SRCS += ft_strequ.c
SRCS += ft_striter.c
SRCS += ft_striteri.c
SRCS += ft_strjoin.c
SRCS += ft_strmap.c
SRCS += ft_strmapi.c
SRCS += ft_strnequ.c
SRCS += ft_strnew.c
SRCS += ft_strsplit.c
SRCS += ft_strsub.c
SRCS += ft_tolower.c
SRCS += ft_toupper.c

#--------------------Conversion------------------#
SRCS += ft_atoi.c
SRCS += ft_itoa.c

#----------------------Tab-----------------------#

#--------------------Lists-----------------------#
SRCS += ft_lstadd.c
SRCS += ft_lstdel.c
SRCS += ft_lstdelone.c
SRCS += ft_lstiter.c
SRCS += ft_lstmap.c
SRCS += ft_lstnew.c

#--------------------Output----------------------#
SRCS += ft_putchar.c
SRCS += ft_putchar_fd.c
SRCS += ft_putendl.c
SRCS += ft_putendl_fd.c
SRCS += ft_putnbr.c
SRCS += ft_putnbr_fd.c
SRCS += ft_putstr.c
SRCS += ft_putstr_fd.c

OBJS = $(patsubst %.c, $(OPATH)%.o, $(SRCS))

all: $(OPATH) $(NAME)

$(EXEC): $(NAME)
	$(CC) $(SRCM) $(NAME) -I $(IPATH) -o $(EXEC)

run: $(OPATH) $(EXEC)
	./$(EXEC)

$(NAME): $(OBJS)
	ar -rusc $@ $^ 
	printf "$(GREEN)$@ is ready.\n$(NC)"

$(OBJS): $(OPATH)%.o : %.c $(INCS)
	$(COMPILE) $(CFLAGS) $< -o $@
	printf "$(CYAN)Compiling $<\n$(NC)"

$(OPATH):
	$(MKDIR) $@

clean:
	$(CLEANUP) $(OBJS)
	$(CLEANUP) $(OPATH)
	printf "$(RED)All removed\n$(NC)"

fclean: clean
	$(CLEANUP) $(NAME)
	$(CLEANUP) $(EXEC)
	printf "$(RED)$(NAME) deleted\n$(NC)"

re: fclean all

.PHONY: all clean fclean re
.SILENT:
