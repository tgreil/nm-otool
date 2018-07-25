# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgreil <tgreil@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/07 16:24:07 by tgreil            #+#    #+#              #
#    Updated: 2018/07/22 12:08:54 by tgreil           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_NM	=	nm.c

SRCS_OTOOL	= otool.c

SRCS_UTIL	= ft_error.c

OBJS_NM	= $(addprefix srcs/nm/, $(SRCS_NM:.c=.o))

OBJS_OTOOL	= $(addprefix srcs/otool/, $(SRCS_OTOOL:.c=.o))

OBJS_UTIL	= $(addprefix srcs/, $(SRCS_UTIL:.c=.o))

LIBS	= -Llibft/ -lft

PROJECT = Nm-otool_project

NM	= ft_nm

OTOOL	= ft_otool

RM	= rm -f

CC	= gcc

MAKELIB	= make -C libft/

LIB	= libft/libft.a

CFLAGS	= -W -Wall -Wextra -Werror
CFLAGS	+= -Iincludes/ -Ilibft/includes/

LDFLAGS	=  $(LIBS)

$(PROJECT):	$(LIB) $(NM) $(OTOOL)

$(NM):	$(OBJS_NM) $(OBJS_UTIL)
	$(CC) $(OBJS_NM) $(OBJS_UTIL) -o $(NM) $(LDFLAGS)

$(OTOOL):	$(OBJS_OTOOL)
	$(CC) $(OBJS_OTOOL) $(OBJS_UTIL) -o $(OTOOL) $(LDFLAGS)

$(LIB):
	$(MAKELIB)

all:	$(PROJECT)

clean:
	$(RM) $(OBJS)
	$(MAKELIB) clean

fclean:
	$(RM) $(OBJS)
	$(MAKELIB) fclean
	$(RM) $(NM) $(OTOOL)

re:	fclean all

.PHONY:	re fclean clean all $(PROJECT)
