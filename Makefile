# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/11 20:52:36 by bwan-nan          #+#    #+#              #
#    Updated: 2019/03/01 15:30:43 by bwan-nan         ###   ########.fr        #
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
vpath %.c lib/

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
GREY=\033[0;37m

MKDIR = mkdir -p
CLEANUP = rm -rf

WFLAGS += -Wall
WFLAGS += -Werror
WFLAGS += -Wextra
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
SRCS += init_struct.c
SRCS += parsing.c
SRCS += output_handler.c
SRCS += diouxx_conv.c
SRCS += print_diouxx.c
SRCS += print_csp.c
SRCS += print_flags.c
SRCS += float_conv.c
SRCS += binary_conv.c
SRCS += colors.c
SRCS += float_operations.c
SRCS += init_floats.c
SRCS += date_conv.c
SRCS += print_float.c

#--------------------Memory--------------------#
SRCL += ft_bzero.c
SRCL += ft_memalloc.c
SRCL += ft_memmove.c
SRCL += ft_memchr.c
SRCL += ft_memcmp.c
SRCL += ft_memcpy.c
SRCL += ft_memdel.c
SRCL += ft_memset.c
SRCL += ft_realloc.c

#--------------------Strings---------------------#
SRCL += ft_islower.c
SRCL += ft_isalpha.c
SRCL += ft_isdigit.c
SRCL += ft_strcat.c
SRCL += ft_strchr.c
SRCL += ft_strcmp.c
SRCL += ft_strcpy.c
SRCL += ft_strdup.c
SRCL += ft_strlen.c
SRCL += ft_strncat.c
SRCL += ft_strncmp.c
SRCL += ft_strncpy.c
SRCL += ft_strnstr.c
SRCL += ft_strrchr.c
SRCL += ft_strstr.c
SRCL += ft_strdel.c
SRCL += ft_strequ.c
SRCL += ft_strjoin.c
SRCL += ft_strnequ.c
SRCL += ft_strnew.c
SRCL += ft_strsplit.c
SRCL += ft_strsub.c
SRCL += ft_tolower.c
SRCL += ft_toupper.c
SRCL += ft_strtoupper.c
SRCL += ft_strtolower.c
SRCL += ft_str_notchr.c
SRCL += ft_strchr_index.c
SRCL += ft_str_notchr_index.c
SRCL += ft_strr_notchr_index.c
SRCL += get_float_len.c

#--------------------Conversion------------------#
SRCL += ft_atoi.c
SRCL += ft_itoa.c
SRCL += ft_llitoa.c
SRCL += ft_llitoa_base.c
SRCL += ft_ullitoa.c
SRCL += ft_ullitoa_base.c
SRCL += get_bits.c
SRCL += ft_binatoi.c

#--------------------Lists-----------------------#
SRCL += ft_lstadd.c
SRCL += ft_lstdel.c
SRCL += ft_lstdelone.c
SRCL += ft_lstnew.c

#--------------------Output----------------------#
SRCL += ft_putchar.c
SRCL += ft_putendl.c
SRCL += ft_putnbr.c
SRCL += ft_putstr.c

#--------------------Maths-----------------------#
SRCL += ft_recursive_power.c
SRCL += ft_max.c

OBJS += $(patsubst %.c, $(OPATH)%.o, $(SRCS))
OBJS += $(patsubst %.c, $(OPATH)%.o, $(SRCL))

all: $(OPATH) $(NAME)

$(EXEC): $(NAME) $(SRCM)
	$(CC) $^ -I $(IPATH) -o $@

run: $(OPATH) $(EXEC)
	./$(EXEC)

$(NAME): $(OBJS)
	ar -rusc $@ $^ 
	ranlib $@
	printf "$(GREEN)$@ is ready.\n$(NC)"

$(OBJS): $(OPATH)%.o : %.c $(INCS)
	$(COMPILE) $(CFLAGS) $< -o $@
	printf "$(CYAN)Compiling $<\n$(NC)"

$(OPATH):
	$(MKDIR) $@

clean:
	$(CLEANUP) $(OBJS)
	$(CLEANUP) $(OPATH)
	$(CLEANUP) $(EXEC)
	printf "$(RED)All objects removed\n$(NC)"

fclean: clean
	$(CLEANUP) $(NAME)
	$(CLEANUP) $(EXEC)
	printf "$(RED)$(NAME) deleted\n$(NC)"

re: fclean all

.PHONY: all clean fclean re
.SILENT:
