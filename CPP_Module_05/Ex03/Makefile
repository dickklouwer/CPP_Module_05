#= Variables =#

NAME := Intern
SRCS :=  Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp main.cpp
SRCSDIR := srcs

OBJDIR := obj

OBJ := $(addprefix $(OBJDIR)/,$(SRCS:.cpp=.o))

CPP_FLAGS = -Wall -Werror -Wextra -std=c++98

INCLUDES := includes/Bureaucrat.hpp includes/AForm.hpp includes/ShrubberyCreationForm.hpp includes/RobotomyRequestForm.hpp includes/PresidentialPardonForm.hpp includes/Intern.hpp

#= COLORS =#

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

#= Targets =#

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJ) $(INCLUDES)
	@echo "$(GREEN)Building Intern ...$(RESET)"
	@g++ $(OBJ) -o $(NAME)

$(OBJDIR)/%.o: $(addprefix $(SRCSDIR)/, %.cpp) $(INCLUDES)
	@g++ $(CPP_CFLAGS) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@rm -rf $(OBJDIR)
	@rm *_shrubbery
	@echo "$(RED)Cleaning ...$(RESET)"

fclean: clean
	@rm -rf $(NAME) $(OBJDIR)

re: fclean all