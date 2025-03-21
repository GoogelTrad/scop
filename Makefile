NAME = scop
CFLAGS = -Wall -Wextra -Werror -std=c++11 -g -fsanitize=address
CLINKS = -framework OpenGL -framework GLUT -I/usr/local/include
# CLINKS = -lGL -lGLU -lglut
CC = c++
RM = rm -f

SRCS =	srcs/main.cpp \
		srcs/window.cpp \
		srcs/draw.cpp \
		class/Vertex.cpp \
		class/Face.cpp \
		srcs/parsing.cpp \
		class/Objets.cpp \
		class/Matrices.cpp \

		

OBJC = ${SRCS:.cpp=.o}


all: ${NAME}

.cpp.o:
	c++ $(CFLAGS) -c $< -o $@


${NAME}: ${OBJC}
	${CC} ${CFLAGS} ${OBJC} ${CLINKS} -o ${NAME}

clean: 
	 ${RM} ${OBJC}

fclean: clean
	${RM} ${NAME}

re: fclean all