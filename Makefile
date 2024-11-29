# Variables de compilation
CXX = g++
CXXFLAGS = -Wall -Wextra -g -ggdb -I./include --coverage
LDFLAGS = --coverage -lgtest -lgtest_main -pthread -llapin -lsfml-graphics -lsfml-audio -lsfml-window \
          -lsfml-system -lstdc++ -lm -ldl -lopencv_imgproc -lopencv_highgui -lopencv_objdetect \
          -lopencv_videoio -lopencv_core -lavcall

SRCDIR = ./src
INCDIR = ./include
TESTDIR = ./test
OBJDIR = ./obj
TARGET = main

# Couleurs
GREEN = \033[32m
RED = \033[31m
YELLOW = \033[33m
CYAN = \033[36m
RESET = \033[0m

# Recherche des fichiers sources
SRCS = $(shell find $(SRCDIR) -name '*.cpp')
# Séparer main.cpp des autres fichiers sources
MAIN_SRC = $(SRCDIR)/main.cpp
# Objets sauf main.cpp
OBJS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(filter-out $(MAIN_SRC), $(SRCS)))

# Recherche des fichiers de test
TEST_SRCS = $(shell find $(TESTDIR) -name '*.cpp')
TEST_OBJS = $(patsubst $(TESTDIR)/%.cpp, $(OBJDIR)/%.o, $(TEST_SRCS))

# Règle principale
all: $(TARGET) test run

# Compilation du programme principal
$(TARGET): $(OBJS) $(OBJDIR)/main.o
	@echo "$(CYAN)[LINK]$(RESET) Linking $(TARGET)..."
	@$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)
	@echo "$(GREEN)[DONE]$(RESET) $(TARGET) built successfully."

# Compilation des fichiers objets
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(@D)
	@echo "$(YELLOW)[COMPILE]$(RESET) Compiling $<..."
	@$(CXX) $(CXXFLAGS) -c -o $@ $<

# Règle pour exécuter le programme
run:
	@echo "$(CYAN)[RUN]$(RESET) Running $(TARGET)..."
	@./$(TARGET)

# Compilation et exécution des tests unitaires
test: $(TEST_OBJS)
	@echo "$(CYAN)[TEST]$(RESET) Compiling and running tests..."
	@$(CXX) $(CXXFLAGS) -o test_runner $(OBJS) $(TEST_OBJS) $(LDFLAGS)
	@./test_runner || echo "$(RED)[FAILURE]$(RESET) One or more tests failed."
	@echo "$(GREEN)[SUCCESS]$(RESET) All tests passed."

# Compilation des fichiers objets des tests
$(OBJDIR)/%.o: $(TESTDIR)/%.cpp
	@mkdir -p $(@D)
	@echo "$(YELLOW)[COMPILE TEST]$(RESET) Compiling test $<..."
	@$(CXX) $(CXXFLAGS) -c -o $@ $<

# Règle pour générer le rapport de couverture
coverage: test
	@echo "$(CYAN)[COVERAGE]$(RESET) Generating coverage report..."
	@gcov $(SRCS) $(TEST_SRCS)

# Nettoyage des fichiers temporaires
fclean:
	@echo "$(CYAN)[CLEAN]$(RESET) Cleaning build artifacts..."
	@rm -rf $(OBJDIR) *.gcda *.gcno *.gcov $(TARGET) test_runner
	@find . -name "*~" -type f -delete

# Nettoyage et recompilation complète
re: fclean all

# Règles de base
.PHONY: all run test fclean re coverage

