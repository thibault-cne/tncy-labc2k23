# You have to put your .c files in the FILES variable.
FILES_1 =	helloworld.c
FILES_2	=	max3.c
FILES_3 = 	max3_stdin.c
FILES_4	=	max3_args.c
FILES_5	=	zodiac.c
FILES_6	=	dayofbirth.c
FILES_7	=	dayofbirth_stdin.c
FILES_8	=	stringtools.c stringtools_main.c
FILES_9	=	occurence.c occurence_main.c

S_PATH	=	src/
O_PATH	=	objs/
I_PATH	=	includes/
B_PATH	=	build/

SRCS_1	=	${addprefix ${S_PATH}, ${FILES_1}}
OBJS_1	=	${addprefix ${O_PATH}, ${FILES_1:.c=.o}}

SRCS_2	=	${addprefix ${S_PATH}, ${FILES_2}}
OBJS_2	=	${addprefix ${O_PATH}, ${FILES_2:.c=.o}}

SRCS_3	=	${addprefix ${S_PATH}, ${FILES_3}}
OBJS_3	=	${addprefix ${O_PATH}, ${FILES_3:.c=.o}}

SRCS_4	=	${addprefix ${S_PATH}, ${FILES_4}}
OBJS_4	=	${addprefix ${O_PATH}, ${FILES_4:.c=.o}}

SRCS_5	=	${addprefix ${S_PATH}, ${FILES_5}}
OBJS_5	=	${addprefix ${O_PATH}, ${FILES_5:.c=.o}}

SRCS_6	=	${addprefix ${S_PATH}, ${FILES_6}}
OBJS_6	=	${addprefix ${O_PATH}, ${FILES_6:.c=.o}}

SRCS_7	=	${addprefix ${S_PATH}, ${FILES_7}}
OBJS_7	=	${addprefix ${O_PATH}, ${FILES_7:.c=.o}}

SRCS_8	=	${addprefix ${S_PATH}, ${FILES_8}}
OBJS_8	=	${addprefix ${O_PATH}, ${FILES_8:.c=.o}}

SRCS_9	=	${addprefix ${S_PATH}, ${FILES_9}}
OBJS_9	=	${addprefix ${O_PATH}, ${FILES_9:.c=.o}}

CC		=	clang

RM		=	rm -rf

CFLAGS		=	-DSNOW_ENABLED -Wall -Wextra -Werror -pedantic -O0 -g3 -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls

${O_PATH}%.o:	${S_PATH}%.c
				@mkdir -p ${dir $@}
				@${CC} ${CFLAGS} -c $< -o $@
				@echo "${BOLD}${CYAN}Compiling${S}${S} ${IGREY}$<${S} ${YELLOW}-> ${S}${SBLUE}$@${S} ⚙️"


ex1:				build ${OBJS_1}
					@${CC} ${OBJS_1} ${CFLAGS} -o $@ -I ${I_PATH}
					@echo ""
					@echo "${BOLD}${PURPLE}Building${S}${S} ${IGREY}$@${S} 🖥️"
					@echo ""
					@echo "\033[3;92mCompilation is completed !${S} 🎉"
					@mv ./$@ ${B_PATH}$@

ex2: ex2_1 ex2_2 ex2_3

ex2_1:				build ${OBJS_2}
					@${CC} ${OBJS_2} ${CFLAGS} -o $@ -I ${I_PATH}
					@echo ""
					@echo "${BOLD}${PURPLE}Building${S}${S} ${IGREY}$@${S} 🖥️"
					@echo ""
					@echo "\033[3;92mCompilation is completed !${S} 🎉"
					@mv ./$@ ${B_PATH}$@

ex2_2:				build ${OBJS_3}
					@${CC} ${OBJS_3} ${CFLAGS} -o $@ -I ${I_PATH}
					@echo ""
					@echo "${BOLD}${PURPLE}Building${S}${S} ${IGREY}$@${S} 🖥️"
					@echo ""
					@echo "\033[3;92mCompilation is completed !${S} 🎉"
					@mv ./$@ ${B_PATH}$@

ex2_3:				build ${OBJS_4}
					@${CC} ${OBJS_4} ${CFLAGS} -o $@ -I ${I_PATH}
					@echo ""
					@echo "${BOLD}${PURPLE}Building${S}${S} ${IGREY}$@${S} 🖥️"
					@echo ""
					@echo "\033[3;92mCompilation is completed !${S} 🎉"
					@mv ./$@ ${B_PATH}$@

ex3:				build ${OBJS_5}
					@${CC} ${OBJS_5} ${CFLAGS} -o $@ -I ${I_PATH}
					@echo ""
					@echo "${BOLD}${PURPLE}Building${S}${S} ${IGREY}$@${S} 🖥️"
					@echo ""
					@echo "\033[3;92mCompilation is completed !${S} 🎉"
					@mv ./$@ ${B_PATH}$@

ex4:	ex4_1 ex4_2

ex4_1:				build ${OBJS_6}
					@${CC} ${OBJS_6} ${CFLAGS} -o $@ -I ${I_PATH}
					@echo ""
					@echo "${BOLD}${PURPLE}Building${S}${S} ${IGREY}$@${S} 🖥️"
					@echo ""
					@echo "\033[3;92mCompilation is completed !${S} 🎉"
					@mv ./$@ ${B_PATH}$@

ex4_2:				build ${OBJS_7}
					@${CC} ${OBJS_7} ${CFLAGS} -o $@ -I ${I_PATH}
					@echo ""
					@echo "${BOLD}${PURPLE}Building${S}${S} ${IGREY}$@${S} 🖥️"
					@echo ""
					@echo "\033[3;92mCompilation is completed !${S} 🎉"
					@mv ./$@ ${B_PATH}$@

ex5:				build ${OBJS_8}
					@${CC} ${OBJS_8} ${CFLAGS} -o $@ -I ${I_PATH}
					@echo ""
					@echo "${BOLD}${PURPLE}Building${S}${S} ${IGREY}$@${S} 🖥️"
					@echo ""
					@echo "\033[3;92mCompilation is completed !${S} 🎉"
					@mv ./$@ ${B_PATH}$@

ex6:				build ${OBJS_9}
					@${CC} ${OBJS_9} ${CFLAGS} -o $@ -I ${I_PATH}
					@echo ""
					@echo "${BOLD}${PURPLE}Building${S}${S} ${IGREY}$@${S} 🖥️"
					@echo ""
					@echo "\033[3;92mCompilation is completed !${S} 🎉"
					@mv ./$@ ${B_PATH}$@


all:		build ex1 ex2 ex3 ex4 ex5 ex6

clean:
			@${RM} ${O_PATH}*
			@echo "${BOLD}${SRED}Removing${S}${S} ${IGREY}${O_PATH}${S} 🗑️"

fclean:		clean
			@${RM} ${B_PATH}*
			@echo "${BOLD}${SRED}Removing${S}${S} ${IGREY}${B_PATH}${S} 🗑️"

space:
			@echo " "

re:			fclean space all

build: 		
			@mkdir -p $@

.PHONY: all clean fclean re build space

S 		=		\033[0m
BOLD 	= 		\033[1m
ITALIC 	= 		\033[3m
UNDER 	= 		\033[4m
REV 	= 		\033[7m

# Colors
GREY 	= 		\033[30m
RED 	= 		\033[31m
GREEN	=		\033[32m
YELLOW	=		\033[33m
BLUE	=		\033[34m
PURPLE	=		\033[35m
CYAN	=		\033[36m
WHITE	=		\033[37m

SGREY	=		\033[90m
SRED	=		\033[91m
SGREEN	=		\033[92m
SYELLOW	=		\033[93m
SBLUE	=		\033[94m
SPURPLE	=		\033[95m
SCYAN	=		\033[96m
SWHITE	=		\033[97m

# Colored backgrounds

IGREY	=		\033[40m
IRED	=		\033[41m
IGREEN	=		\033[42m
IYELLOW	=		\033[43m
IBLUE	=		\033[44m
IPURPLE	=		\033[45m
ICYAN	=		\033[46m
IWHITE	=		\033[47m