# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lguillau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/14 15:11:31 by lguillau          #+#    #+#              #
#    Updated: 2022/10/19 14:25:50 by lguillau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES	=	cub3d.c \
		CheckExit.c \
		parsing/ext_check.c \
		parsing/parsing.c \
		parsing/map_verif.c \
		game/movementCheck.c \
		game/movement.c \
		game/rayCalculator.c \
		game/rayCalculator_2.c \
		game/anim.c \
		tools/errors.c \
		tools/ft_atoi.c \
		tools/ft_itoa.c \
		tools/str_tools.c \
		tools/gnl/get_next_line.c \
		tools/gnl/get_next_line_utils.c \

S_PATH	=	srcs/
O_PATH	=	objs/
I_PATH	=	includes/
L_PATH	=	minilibx/

SRCS	=	${addprefix ${S_PATH}, ${FILES}}
OBJS	=	${addprefix ${O_PATH}, ${FILES:.c=.o}}

NAME	=	cub3d

CC	=	cc

RM	=	rm -rf

CFLAGS	=	-Wall -Wextra -Werror -g3
LFLAGS	=	-lmlx_Linux -lXext -lX11

all:		${NAME}

${NAME}:	minilibx/libmlx_Linux.a ${OBJS}
		@${CC} ${OBJS} ${CFLAGS} -L ${L_PATH} ${LFLAGS} -o ${NAME} -lm -pthread -I ${I_PATH}
		@echo ""
		@echo "${PURPLE}Building${S} ${IGREY}$@${S} 🔨"
		@echo ""
		@echo "${SGREEN}${ITALIC}Compilation is completed !${S} 🎉"

${O_PATH}%.o:	${S_PATH}%.c
		@mkdir -p ${dir $@}
		@${CC} ${CFLAGS} -c $< -o $@ -I ${I_PATH}
		@echo "${CYAN}Compiling${S} ${IGREY}$<${S} ${YELLOW}➡️  ${S}${SBLUE}$@${S}"

minilibx/libmlx_Linux.a:
		@make -C minilibx

lclean:		
		@echo "${SRED}Removing${S} ${IGREY}Minilibx${S} 🗑️"
		@make clean -C minilibx

clean:
		@${RM} ${O_PATH}
		@echo "${SRED}Removing${S} ${IGREY}${O_PATH}${S} 🗑️"

fclean:		lclean clean
		@${RM} ${NAME}
		@echo "${SRED}Removing${S} ${IGREY}${NAME}${S} 🗑️"

space:
		@echo ""

re:		fclean space  all

.PHONY:		all clean fclean re bonus

S	=	\033[0m
BOLD	=	\033[1m
ITALIC	=	\033[3m
UNDER	=	\033[4m
TEST	=	\033[5m
REV	=	\033[7m

# Colors
GREY	=	\033[30m
RED	=	\033[31m
GREEN	=	\033[32m
YELLOW	=	\033[33m
BLUE	=	\033[34m
PURPLE	=	\033[35m
CYAN	=	\033[36m
WHITE	=	\033[37m

SGREY	=	\033[90m
SRED	=	\033[91m
SGREEN	=	\033[92m
SYELLOW	=	\033[93m
SBLUE	=	\033[94m
SPURPLE	=	\033[95m
SCYAN	=	\033[96m
SWHITE	=	\033[97m

# Colored backgrounds
IGREY	=	\033[40m
IRED	=	\033[41m
IGREEN	=	\033[42m
IYELLOW	=	\033[43m
IBLUE	=	\033[44m
IPURPLE	=	\033[45m
ICYAN	=	\033[46m
IWHITE	=	\033[47m
