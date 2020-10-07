PROJECT_NAME = fft

BUILD = build

SRC = src/fft.c\
main.c\

TEST_SRC = src/fft.c\
test/test_fft.c\

INC = -Iinc\

PROJECT_OUTPUT = $(BUILD)/$(PROJECT_NAME).out

TEST_OUTPUT = $(BUILD)/Test_$(PROJECT_NAME).out

DOCUMENTATION_OUTPUT = documentation/html

$(PROJECT_NAME):all

.PHONY: all test doc run clean

all: $(SRC) $(BUILD)
	gcc -lm $(SRC) $(INC) -o $(PROJECT_OUTPUT)

run:$(PROJECT_NAME)
	./$(PROJECT_OUTPUT)

test:$(BUILD)
	gcc $(TEST_SRC) $(INC) -o $(TEST_OUTPUT) -lcunit
	./$(TEST_OUTPUT)

doc:
	make -C documentation

clean:
	rm -rf $(BUILD) $(DOCUMENTATION_OUTPUT)

$(BUILD):
	mkdir build
