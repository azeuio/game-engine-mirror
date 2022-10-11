##
## EPITECH PROJECT, 2022
## game_engine
## File description:
## Makefile
##

NAME	=	a.out

CC	=	g++

EXTENSION	=	.cpp

TESTS_DIR	=	tests/

TEST_SRC	=	$(shell find $(TESTS_DIR) -name "*$(EXTENSION)" -type f)

SRC	=	$(shell find src -name "*$(EXTENSION)" -type f)

SRC_NO_MAIN	=	$(shell find src -name "*$(EXTENSION)" -type f | \
				grep -v main.cpp | grep -v src/demo)

OBJ	=	$(patsubst src/%$(EXTENSION), obj/%.o, $(SRC))

TEST_OBJ	=	$(patsubst src/%$(EXTENSION), obj/%.o, $(SRC_NO_MAIN))

CFLAGS	=	-std=c++2a -Wall -Wextra -Wshadow -Wpedantic -Iinclude -O3

LDFLAGS	=	-lsfml-graphics -lsfml-window -lsfml-system

ifeq ($(OS),Windows_NT)
DEPENDENCIES	=	dependencies.win.d
EXTERNAL_LIBS	=	C:/lib/SFML-2.5.1/
DLLS	=	$(shell find $(EXTERNAL_LIBS)/bin -name "*.dll" -type f)
LDFLAGS	+=	$(foreach lib, $(EXTERNAL_LIBS), -L"$(lib)/lib")
CFLAGS	+=	$(foreach lib, $(EXTERNAL_LIBS), -I"$(lib)/include")
CFLAGS	+=	-DWINDOWS
ECHO	=	echo -e
NAME	:=	$(NAME:.out=.exe)

else
DEPENDENCIES	=	dependencies.unix.d
CFLAGS	+=	-DLINUX
ECHO	=	echo
NAME	:=	$(NAME:.exe=.out)

endif

all: $(DEPENDENCIES) $(NAME)

run: all
	./$(NAME)

$(DEPENDENCIES): $(SRC)
	@$(ECHO) "\033[1;32mGenerating dependencies...\033[0m"
	@$(RM) $@
	@$(CC) $(CFLAGS) -MT"$(patsubst src/%$(EXTENSION), obj/%.o, $<)" \
	-MM $^ >> $@;

include $(DEPENDENCIES)
obj/%.o: src/%$(EXTENSION)
	@$(ECHO) "\033[34mCompiling $<\033[0m"
	@mkdir -p $$($(ECHO) $(@D) | sed 's/src/obj/g')
	@$(CC) -c $< -o $@ $(CFLAGS)

ifeq ($(OS),Windows_NT)
$(NAME): $(OBJ)
	@$(ECHO) "\033[36;1mCopying dlls to $(CURDIR)\033[0m"
	@$(RM) $(wildcard $(CURDIR)/*.dll)
	@cp $(DLLS) $(CURDIR)
	@$(ECHO) "\033[1;32mLinking $@\033[0m"
	@$(CC) $(shell find obj -name *.o) -o $(NAME) $(LDFLAGS) $(CFLAGS)
else
$(NAME): $(OBJ)
	@$(ECHO) "\033[1;32mLinking $@\033[0m"
	@$(CC) $(shell find obj -name *.o) -o $(NAME) $(LDFLAGS) $(CFLAGS)
endif

clean:
	@$(ECHO) "\033[1;31mCleaning objects...\033[0m"
	@$(RM) -r obj
	@$(ECHO) "\033[1;31mCleaning dependencies...\033[0m"
	@$(RM) $(DEPENDENCIES)

clean_gcovr:
	@$(ECHO) "\033[1;31mCleaning gcovr...\033[0m"
	@$(RM) *.gcda
	@$(RM) *.gcno
	@$(RM) *.gcov

fclean: clean clean_gcovr
	@$(ECHO) "\033[1;31mCleaning executable...\033[0m"
	@$(RM) $(NAME)

re: fclean all

tests_run: NAME = unit_tests
tests_run: run_tests coverage

ifneq (${DISPLAY},)
run_tests: CFLAGS += -DDISPLAY
endif
run_tests: CFLAGS += --coverage -O0
run_tests: LDFLAGS += -lcriterion
run_tests: fclean $(TEST_OBJ)
	@echo "\033[1;32mRunning tests...\033[0m"
	@$(CC) $(TEST_OBJ) \
	$(TEST_SRC) \
	-o $(NAME) $(CFLAGS) $(LDFLAGS)
	@./$(NAME)
	$(RM) $(NAME)

coverage:
	gcovr --exclude $(TESTS_DIR) --exclude include/$(TESTS_DIR)
	gcovr --exclude $(TESTS_DIR) --exclude include/$(TESTS_DIR) -b

debug: CFLAGS += -g3 -O0
debug: re

.phony: all clean fclean re debug run tests_run
