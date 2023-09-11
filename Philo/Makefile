# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/11 18:10:35 by fsantama          #+#    #+#              #
#    Updated: 2023/09/11 18:55:58 by fsantama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# =============================================================================#
#                        	GENERAL CONFIG & FLAGS                             #
# =============================================================================#

# PROGRAM FOR COMPILING C PROGRAMS
CC 		=	gcc
# C COMPILER FLAGS
CFLAGS =	-Werror -Wall -Wextra

NAME 	=	so_long
LIBFT 	=	./inc/Libft/libft.a
PRINTF 	=	./inc/ft_printf/libftprintf.a

# =============================================================================#
#                              MANDATORY PART                                  #
# =============================================================================#

SRCS	=	src/philosophers.c

OBJS	=	$(SRCS:.c=.o)

# =============================================================================#
#                                  RULES                                       #  
# =============================================================================#


all : $(NAME) $(LIBFT) $(PRINTF)

$(LIBFT) : 
	@make  -C inc/Libft > /dev/null

$(PRINTF) : 
	@make  -C inc/ft_printf > /dev/null


$(NAME) : $(LIBFT) $(PRINTF) $(OBJS)
	@echo "$(CYAN) ======================================================="
	@echo "|		        _     _ _     		    |"
	@echo "|		  _ __ | |__ (_) | ___  		|"
	@echo "|		 | '_ \| '_ \| | |/ _ \ 		|"
	@echo "|		 | |_) | | | | | | (_) |		|"
	@echo "|		 | .__/|_| |_|_|_|\___/ 		|"
	@echo "|		 |_|                    		|"
	@echo " ======================================================="
	@echo " ================ Develop by fsantama =================="
	@echo " ======================================================="
	@echo "																	"
	@echo "      (((/               /(((((,              .((((				"
	@echo "     ((,,,*((((((((((((((,,*,,,*(((((((((((((/   *(/				"
	@echo "     ((,,,,,,,,,,,,,,,,,,,,,,,,,,,,,(((..       .(((				"
	@echo "    ((/,,,,,,,,,,,,(##(####/,,,,*(((   *%, # ,(((%((				"
	@echo "    #(/,,,,,,,,,,*%##########(((/  #  ,*, *((#  %#((				"
	@echo "    /((,,,,/(#(###%##%%#,,,*,,,#,   // /((,,%%  %#((				"
	@echo "     (((###(##((#####%,,,/,*##,*#*  (((#%% ,%%  %(((				"
	@echo "     (((%##%%%%%%%#(((,,(/,((*#*,,((#. #%% ,%%  %((,				"
	@echo "      ((#%%%####(((* .,,,%/*,*/*,* %%. #%% ,%%  (((				"
	@echo "      ,((#%%%(((, *%, %((,,,/,,/#  %%. #%% ,%% (((				"
	@echo "       *(((((   ## (   *(((%( ,%%  %%. #%% ,%%(((				"
	@echo "        .((*  /*((  /(((%%%%( ,%%  %%. #%% ,%(((					"
	@echo "          (((    (((#%%%%%%%( ,%%  %%. #%% ,(((					"
	@echo "           ((((((#%%%%%%%%%%( ,%%  %%. #%%/((,					"
	@echo "             (((#%%%%%%%%%%%( ,%%  %%. ##(((						"
	@echo "              .(((%%%%%%%%%%( ,%%  %%. (((						"
	@echo "                ,(((%%%%%%%%( ,%%  %#(((							"
	@echo "                  .(((%%%%%%( ,%% .(((							"
	@echo "                     (((#%%%( ,%((((								"
	@echo "                       *(((%( (((.								"
	@echo "                          ((((*									"
	@echo "	                                                      			"
	@echo " =======================================================			"
	@echo "                                                       $(DEFAULT)"
	@echo "$(GREEN) $(NAME) make done ✅ $(DEFAULT)"
	@echo "$(GREEN) $(LIBFT) make done ✅ $(DEFAULT)"
	@echo "$(GREEN) $(PRINTF) make done ✅ $(DEFAULT)"
	@$(CC) $(CFLAGS) $(LIBFT) $(PRINTF) $(OBJS) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -f $(OBJS)
	@make -C inc/Libft clean > /dev/null
	@make -C inc/ft_printf clean > /dev/null
	@echo "$(RED) $(NAME) objects clean done 🧹 $(DEFAULT)"
	@echo "$(RED) $(LIBFT) objects clean done 🧹 $(DEFAULT)"
	@echo "$(RED) $(PRINTF) objects clean done 🧹 $(DEFAULT)"

fclean : clean
	@rm -f $(NAME)
	@make -C inc/Libft fclean > /dev/null
	@make -C inc/ft_printf fclean > /dev/null
	@echo "$(RED) $(NAME) clean done 🧹 $(DEFAULT)"
	@echo "$(RED) $(LIBFT) clean done 🧹 $(DEFAULT)"
	@echo "$(RED) $(PRINTF) clean done 🧹 $(DEFAULT)"
re: fclean all

#bonus : $(NAME_BONUS)

# =============================================================================#
#                                 COLORS                                       #
# =============================================================================#

BOLD	:=	\033[1m
BLACK	:=	\033[30;1m
RED		:=	\033[31;1m
GREEN	:=	\033[32;1m
YELLOW	:=	\033[33;1m
BLUE	:=	\033[34;1m
MAGENTA	:=	\033[35;1m
CYAN	:=	\033[36;1m
WHITE	:=	\033[37;1m
DEFAULT	:=	\033[0m

.PHONY: all clean fclean re