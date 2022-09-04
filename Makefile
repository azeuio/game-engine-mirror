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

SRC	=	$(shell find src -name "*$(EXTENSION)" -type f)

OBJ	=	$(SRC:$(EXTENSION)=.o)

CFLAGS	=	-Wall -Wextra -Werror -Iinclude #-O3

LDFLAGS	=	-lsfml-graphics -lsfml-window -lsfml-system

all: $(DEPENDENCIES) $(NAME)

$(DEPENDENCIES): $(SRC)
	@echo -e "\033[1;32mGenerating dependencies...\033[0m"
	@$(RM) $@
	@$(CC) $(CFLAGS) -MM $^ >> $@;

include $(DEPENDENCIES)

%.o: %$(EXTENSION)
	@echo -e "\033[34mCompiling $<\033[0m"
	@mkdir -p $$(echo $(@D) | sed 's/src/obj/g')
	@$(CC) -c $< -o $@ $(CFLAGS)
	@mv $@ $$(echo $@ | sed 's/src/obj/g')

$(NAME): $(OBJ)
	@echo -e "\033[1;32mLinking $@\033[0m"
	@$(CC) $(shell find obj -name *.o) -o $(NAME) $(LDFLAGS) $(CFLAGS)

clean:
	@echo -e "\033[1;31mCleaning objects...\033[0m"
	@$(RM) -r obj

clean_gcovr:
	@echo -e "\033[1;31mCleaning gcovr...\033[0m"
	@$(RM) *.gcda
	@$(RM) *.gcno

fclean: clean clean_gcovr
	@echo -e "\033[1;31mCleaning executable...\033[0m"
	@$(RM) $(NAME)

re: fclean all

tests_run: NAME = unit_tests
tests_run: fclean run_tests coverage

run_tests:
	@echo -e "\033[1;32mRunning tests...\033[0m"
	@$(CC) $(filter-out src/main.cpp,$(SRC)) -o $(NAME) $(CFLAGS) $(LDFLAGS) \
	--coverage -lcriterion
	@./$(NAME)
	@$(RM) $(NAME)

coverage:
	@gcovr --exclude tests/

.phony: all clean fclean
