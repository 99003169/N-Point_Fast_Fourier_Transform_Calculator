PROJECT_NAME = fft

BUILD = build

SRC = src/fft.c\
main.c\

TEST_SRC = src/fft.c\
test/tb_fft.c\
unity/unity.c\

INC = -Iinc\
-Iunity\

PROJECT_OUTPUT = $(BUILD)/$(PROJECT_NAME).out

TEST_OUTPUT = $(BUILD)/Test_$(PROJECT_NAME).out

DOCUMENTATION_OUTPUT = documentation/html

$(PROJECT_NAME): $(SRC) $(BUILD)
	gcc $(SRC) $(INC) -o $(PROJECT_OUTPUT)

run:$(PROJECT_NAME)
	./$(PROJECT_OUTPUT)

test:$(BUILD)
	gcc $(TEST_SRC) $(INC) -o $(TEST_OUTPUT)
	./$(TEST_OUTPUT)

doc:
	make -C documentation

clean:
	rm -rf $(BUILD) $(DOCUMENTATION_OUTPUT)

$(BUILD):
	mkdir build
