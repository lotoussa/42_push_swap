# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/01/15 14:07:08 by lotoussa     #+#   ##    ##    #+#        #
#    Updated: 2018/01/31 07:26:47 by lotoussa    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME_1 = checker

NAME_2 = push_swap

CC = gcc

CFLAGS = -Werror -Wextra -Wall

D_SRC = src/

D_LIBFT = libft/

HEADER = header.h

SRC1_1 = checker.c ft_atol.c ft_check_sort.c ft_exec_ins.c ft_fill_a.c       \
		 ft_read_stdin.c ft_recreate_elem_r.c ft_sort_pa_r.c ft_sort_pb_r.c  \
		 ft_sort_ra_r.c ft_sort_rb_r.c ft_sort_rr_r.c ft_sort_rra_r.c        \
		 ft_sort_rrb_r.c ft_sort_rrr_r.c ft_sort_sa_r.c ft_sort_sb_r.c       \
		 ft_sort_ss_r.c ft_max.c ft_sort_rrb.c ft_sort_rb.c ft_sort_sb.c     \
		 ft_recreate_elem.c

SRC1_2 = push_swap.c ft_check_sort.c ft_fill_a.c ft_atol.c ft_recreate_elem.c\
		 ft_recreate_elem_r.c ft_try_sort.c ft_max.c ft_little_sort.c        \
		 ft_convert_tab.c ft_fill_index.c ft_reset_conv.c ft_sort_pa.c       \
		 ft_sort_pb.c ft_sort_ra.c ft_sort_rb.c ft_sort_rr.c ft_sort_rra.c   \
		 ft_sort_rrb.c ft_sort_rrr.c ft_sort_sa.c ft_sort_sb.c ft_sort_ss.c  \
		 ft_read_stdin.c ft_another_sort.c ft_check_resort.c ft_sort_pile.c  \
		 ft_recursive.c ft_util_recursive.c ft_print.c

SRC2 =	 ft_isdigit.c ft_memalloc.c ft_printf.c ft_putendl_fd.c              \
		 ft_strcmp.c ft_strdel.c ft_strdup.c ft_strjoin.c ft_strlen.c        \
		 ft_strsub.c get_next_line.c ft_bzero.c ft_putchar_fd.c              \
		 ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strcpy.c      \
		 ft_strnew.c pf_special.c pf_strsub.c ft_putchar.c pf_flags.c        \
		 pf_modif.c pf_multi.c pf_type.c ft_atoi.c pf_c.c pf_d.c pf_i.c      \
		 pf_invalid_type.c pf_o.c pf_p.c pf_percent.c pf_s.c pf_u.c          \
		 pf_upper_c.c pf_upper_d.c pf_upper_o.c pf_upper_s.c                 \
		 pf_upper_u.c pf_upper_x.c pf_x.c pf_litoa_base.c ft_strsplit.c      \
		 pf_luitoa_base.c pf_number.c pf_string_prec.c                       \
		 pf_string_width.c pf_unicode.c pf_hashtag.c

SRC_PRE = $(addprefix $(D_SRC), $(SRC1_1))

SRC2_PRE = $(addprefix $(D_SRC), $(SRC1_2))

SRC_LIB = $(addprefix $(D_LIBFT), $(SRC2))

OBJ = $(SRC_PRE:.c=.o) $(SRC_LIB:.c=.o)

OBJ_2 = $(SRC2_PRE:.c=.o) $(SRC_LIB:.c=.o)

all: $(NAME_1) $(NAME_2)

$(NAME_1): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME_1)

$(NAME_2): $(OBJ_2)
	@$(CC) $(CFLAGS) $(OBJ_2) -o $(NAME_2)

./%.o: ./%.c $(HEADER)
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@/bin/rm -f $(OBJ) $(OBJ_2)
	@cd libft && $(MAKE) clean

fclean: clean
	@/bin/rm -f $(NAME_1) $(NAME_2)
	@cd libft && $(MAKE) fclean

re: fclean all
