###############    variables    ###############

CXX = c++
CFLAGS = -Wall -Wextra -Werror -g -std=c++98 -I./includes -I./libs -O2

SRC_DIR = ./srcs
OBJS_DIR = ./objs
OUTPUT_DIR ?= .
NAME_PROG ?=  EasyFind

###############    Files    ###############

SRC_GENERAL =	main \

SRC	= $(addprefix $(SRC_DIR)/, $(addsuffix .cpp,	$(SRC_GENERAL) \
))

OBJS	:= $(patsubst $(SRC_DIR)/%.cpp, $(OBJS_DIR)/%.o, $(SRC))

###############    Compilation    ###############
all: create_obj_dir $(NAME_PROG)

$(NAME_PROG): $(OBJS)
	$(CXX) $(CFLAGS) -o $(OUTPUT_DIR)/$(NAME_PROG) $(OBJS)

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CFLAGS) -o $@ -c $<

create_obj_dir :
	mkdir -p $(OBJS_DIR)

###############    Cleaning    ###############
clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME_PROG)

###############    Re    ###############
re: fclean all