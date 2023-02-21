NAME = ircserv

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC_DIR =	srcs
SRC_NAMES =	main.cpp \
			utils.cpp \
			User.cpp \
			Server.cpp \
			Command.cpp \
			CAP.cpp \
			PASS.cpp \
			NICK.cpp \
			USER.cpp \
			Channel.cpp \

SRCS =	$(addprefix $(SRC_DIR)/, $(SRC_NAMES))

OBJ_DIR =	objs
OBJ_NAMES	= $(SRC_NAMES:.cpp=.o)
OBJS		= $(addprefix $(OBJ_DIR)/, $(OBJ_NAMES))

INC_DIR =	inc
INC_NAMES =	main.hpp \
			User.hpp \
			Server.hpp \
			codes.hpp \
			Command.hpp \
			CommandList.hpp \
			Channel.hpp \
			exceptions.hpp

INC = $(addprefix $(INC_DIR)/, $(INC_NAMES))

RM =	rm -rf

$(NAME):	$(OBJS)
			$(CXX) -o $(NAME) $(OBJS) $(CXXFLAGS)

$(OBJ_DIR)/%.o :	$(SRC_DIR)/%.cpp $(INC) | $(OBJ_DIR)
					$(CXX) $(CXXFLAGS) -c $< -o $@ -I./$(INC_DIR)/

$(OBJ_DIR) :
				mkdir -p $(OBJ_DIR)

all: $(NAME)

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJ_DIR)

fclean:	clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean re fclean
