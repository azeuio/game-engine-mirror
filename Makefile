##
## EPITECH PROJECT, 2022
## game_engine
## File description:
## Makefile
##

NAME	=	a.out

CC	=	g++

EXTENSION	=	.cpp

DEPENDENCIES	=	dependencies.d

TESTS_DIR	=	tests/

TEST_SRC	=	$(shell find $(TESTS_DIR) -name "*$(EXTENSION)" -type f)

SRC	=	$(shell find src -name "*$(EXTENSION)" -type f)

OBJ	=	$(patsubst src/%$(EXTENSION), obj/%.o, $(SRC))

CFLAGS	=	-Wall -Wextra -Werror -Iinclude -O3

LDFLAGS	=	-lsfml-graphics -lsfml-window -lsfml-system

all: $(DEPENDENCIES) $(NAME)

$(DEPENDENCIES): $(SRC)
	@echo "\033[1;32mGenerating dependencies...\033[0m"
	@$(RM) $@
	@$(CC) $(CFLAGS) -MM $^ >> $@;

include $(DEPENDENCIES)
obj/%.o: src/%$(EXTENSION)
	@echo "\033[34mCompiling $<\033[0m"
	@mkdir -p $$(echo $(@D) | sed 's/src/obj/g')
	@$(CC) -c $< -o $@ $(CFLAGS)

$(NAME): $(OBJ)
	@echo "\033[1;32mLinking $@\033[0m"
	@$(CC) $(shell find obj -name *.o) -o $(NAME) $(LDFLAGS) $(CFLAGS)

clean:
	@echo "\033[1;31mCleaning objects...\033[0m"
	@$(RM) -r obj

clean_gcovr:
	@echo "\033[1;31mCleaning gcovr...\033[0m"
	@$(RM) $(shell find . -name "*.gcda")
	@$(RM) $(shell find . -name "*.gcno")
	@$(RM) $(shell find . -name "*.gcov")

fclean: clean clean_gcovr
	@echo "\033[1;31mCleaning executable...\033[0m"
	@$(RM) $(NAME)

re: fclean all

tests_run: NAME = unit_tests
tests_run: run_tests coverage

ifneq (${DISPLAY},)
run_tests: fclean
	@printf "/*\n \
	** EPITECH PROJECT, 2022\n \
	** game-engine\n \
	** File description:\n \
	** set_env_display\n \
	*/\n\n" > include/tests/set_env_display.hpp
	@printf "#define DISPLAY 1\n" >> include/tests/set_env_display.hpp
else
run_tests: fclean
	@printf "/*\n \
	** EPITECH PROJECT, 2022\n \
	** game-engine\n \
	** File description:\n \
	** set_env_display\n \
	*/\n\n" > include/tests/set_env_display.hpp
	@printf "#define DISPLAY 0\n" >> include/tests/set_env_display.hpp
endif
	@echo "\033[1;32mRunning tests...\033[0m"
	@$(CC) $(shell find src -name "*$(EXTENSION)" -type f | \
	grep -v main.cpp | grep -v src/demo) \
	$(TEST_SRC) \
	-o $(NAME) $(CFLAGS) $(LDFLAGS) --coverage -lcriterion
	@./$(NAME)
	$(RM) $(NAME)

coverage:
	@gcovr --exclude $(TESTS_DIR) --exclude include/$(TESTS_DIR)
	@gcovr --exclude $(TESTS_DIR) --exclude include/$(TESTS_DIR) -b

.phony: all clean fclean
