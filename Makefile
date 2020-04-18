CXX:=g++
CXX_VER:=c++11

CFLAGS+=-std=$(CXX_VER)
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

TEST_CFLAGS+=$(CFLAGS)
TEST_CFLAGS+=-I /usr/local/include/gtest/
TEST_CFLAGS+=-I h
TEST_CFLAGS+=-I ./

TEST_LFLAGS+=-std=$(CXX_VER)
TEST_LFLAGS+=-I h
TEST_LFLAGS+=-pthread


OBJ = obj
TEST_DIR = test
BIN_DIR = bin
BIN = $(BIN_DIR)/out
TEST_BIN = $(BIN_DIR)/test_out
TEST_OBJ = $(TEST_DIR)/obj
PROJECT_SRC = \
			TestInclude.cc \
			TcpServer.cc   \
			Token.cc
PROJECT_OBJS = $(patsubst %.cc,$(OBJ)/%.o,$(PROJECT_SRC))
MAIN_PROJECT_OBJS = $(addprefix $(OBJ)/,\
			main.o) \
			$(PROJECT_OBJS)

TEST_PROJ_SRC = \
			test-test.cc \
			TcpServerTest.cc \
			TokenTest.cc
TEST_PROJ_OBJS = $(patsubst %.cc,%.o,$(TEST_PROJ_SRC))
TEST_MAIN_PROJ_OBJS = $(addprefix $(TEST_OBJ)/,\
			main.o \
			$(TEST_PROJ_OBJS))


.PHONY: all build dirs clean test
all: build test

build: dirs $(MAIN_PROJECT_OBJS)
	$(CXX) -o $(BIN) $(MAIN_PROJECT_OBJS)

test: dirs $(TEST_BIN)
	./$(TEST_BIN)

dirs: $(OBJ) $(TEST_OBJ) $(BIN_DIR)

$(OBJ):
	mkdir -p $(OBJ)

$(TEST_OBJ):
	mkdir -p $(TEST_OBJ)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(OBJ)/%.o: %.cc
	$(CXX) -c $(CFLAGS) $< -o $@

$(TEST_OBJ)/%.o: $(TEST_DIR)/%.cc
	$(CXX) -c $(TEST_CFLAGS) $< -o $@

$(TEST_BIN): $(PROJECT_OBJS) $(TEST_MAIN_PROJ_OBJS)
	$(CXX) $(TEST_LFLAGS) -o $(TEST_BIN) $(TEST_MAIN_PROJ_OBJS) $(PROJECT_OBJS) /usr/local/lib/libgtest.a

clean:
	rm -rf $(OBJ) $(TEST_OBJ) $(BIN_DIR) *.o 
