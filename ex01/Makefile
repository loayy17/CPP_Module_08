CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = span
SRCS = main.cpp Span.cpp
OBJS = ${SRCS:.cpp=.o}

${NAME}: ${OBJS}
		${CXX} ${CXXFLAGS} -o ${NAME} ${OBJS}

all: ${NAME}

clean:
	rm -rf ${OBJS}

fclean:clean
		rm -rf ${NAME}

re: fclean all

.PHONY: re fclean clean all 