TARGET_EXEC := app
BUILD_DIR := ./build/linux/x86_64/release
SRC_DIRS := ./src
SRCS := $(shell find $(SRC_DIRS) -name '*.cpp' -or -name '*.c' -or -name '*.s')


.PHONY: run clean

run:
	@echo "********************"
	@echo "*                  *"
	@echo "*    Debug Start   *"
	@echo "*                  *"
	@echo "********************\n"
	@$(BUILD_DIR)/$(TARGET_EXEC)

clean:
	rm -r $(BUILD_DIR)
