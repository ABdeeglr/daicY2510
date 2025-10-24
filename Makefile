TARGET_EXEC := final_program

TARGET_ARGS =
BUILD_DIR := ./build
SRC_DIRS := ./src

SRCS := $(shell find $(SRC_DIRS) -name '*.cpp' -or -name '*.c' -or -name '*.s')

OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)
# Every folder in ./src will need to be passed to GCC so that it can find header files
INC_DIRS := $(shell find $(SRC_DIRS) -type d)
# Add a prefix to INC_DIRS. So moduleA would become -ImoduleA. GCC understands this -I flag
INC_FLAGS := $(addprefix -I,$(INC_DIRS))
CPPFLAGS := $(INC_FLAGS) -MMD -MP
# The final build step.
$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

# Build step for C source
$(BUILD_DIR)/%.c.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

# Build step for C++ source
$(BUILD_DIR)/%.cpp.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

.PHONY: clean love run kkp asm mem_test mem_check 

mem_check:
	@valgrind --leak-check=full ./$(BUILD_DIR)/$(TARGET_EXEC)

mem_test:
	@valgrind ./$(BUILD_DIR)/$(TARGET_EXEC)
clean:
	rm -r $(BUILD_DIR)

run:
	@echo "********************"
	@echo "*                  *"
	@echo "*    Debug Start   *"
	@echo "*                  *"
	@echo -e "********************\n"
	@$(BUILD_DIR)/final_program $(TARGET_ARGS) 

love:
	@echo "********************"
	@echo "*                  *"
	@echo "*    Debug Start   *"
	@echo "*                  *"
	@echo -e "********************\n"
	@$(BUILD_DIR)/final_program

kkp:
	@vim src/main.c*

asm:
	@gcc -S src/main.c -o asm.s  

release:
	@cp ./build/final_program ~/bin/$(TARGET_NAME)
	@chmod a+x ~/bin/$(TARGET_NAME)
# Include the .d makefiles. The - at the front suppresses the errors of missing
# Makefiles. Initially, all the .d files will be missing, and we don't want those
# errors to show up.
-include $(DEPS)
