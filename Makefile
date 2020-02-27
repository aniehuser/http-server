CXX:=g++

CFLAGS+=-std=c++11
# CFLAGS+=-Werror
CFLAGS+=-Wall
# CFLAGS+=-Wmissing-declarations
# CFLAGS+=-Wreturn-type
# CFLAGS+=-Wformat
# CFLAGS+=-Wunused-function
# CFLAGS+=-Wunused-variable
# CFLAGS+=-Wuninitialized
# CFLAGS+=-Wmissing-prototypes
# CFLAGS+=-Wimplicit
# CFLAGS+=-Wparentheses
# CFLAGS+=-Wswitch


OBJ = obj
TEST_DIR = test
BIN_DIR = bin
BIN = $(BIN_DIR)/out.exe
TEST_OBJ = $(TEST_DIR)/obj
PROJECT_SRC = \
			TestInclude.cc
PROJECT_OBJS = $(patsubst %.cc,%.o,$(PROJECT_SRC))
MAIN_PROJECT_OBJS = $(addprefix $(OBJ)/,\
			main.o \
			$(PROJECT_OBJS))


 .PHONY: all
 all: build

.PHONY: build
build: dirs $(MAIN_PROJECT_OBJS)
	$(CXX) -o $(BIN) $(MAIN_PROJECT_OBJS)

 .PHONY: dirs
 dirs: $(OBJ) $(TEST_OBJ) $(BIN_DIR)

$(OBJ):
	mkdir -p $(OBJ)

$(TEST_OBJ):
	mkdir -p $(TEST_OBJ)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(OBJ)/%.o: %.cc
	$(CXX) -c $(CFLAGS) $< -o $@

# $(OBJ)/%.o: %.cc
# 	$(CXX) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -rf $(OBJ) $(TEST_OBJ) $(BIN_DIR) *.o 

