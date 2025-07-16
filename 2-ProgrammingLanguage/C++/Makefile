# C++ 学习模块 Makefile
# 基于 "Learn C The Hard Way" 风格

CXX = g++
CXXFLAGS = -Wall -g -std=c++17
TARGET_DIR = bin

# 创建目标目录
$(shell mkdir -p $(TARGET_DIR))

# 第一章练习
CHAPTER1_EXERCISES = exercise1_1 exercise1_2 exercise1_3
CHAPTER1_TESTS = test_exercise1_1

# 第二章练习
CHAPTER2_EXERCISES = exercise2_1 exercise2_2 exercise2_3

# 第三章练习
CHAPTER3_EXERCISES = exercise3_1

# 第四章练习
CHAPTER4_EXERCISES = exercise4_1

# 所有练习
ALL_EXERCISES = $(CHAPTER1_EXERCISES) $(CHAPTER2_EXERCISES) $(CHAPTER3_EXERCISES) $(CHAPTER4_EXERCISES)
ALL_TESTS = $(CHAPTER1_TESTS)

# 默认目标
all: $(ALL_EXERCISES)

# 第一章练习
exercise1_1: exercises/chapter01/exercise1_1.cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET_DIR)/$@ $<

exercise1_2: exercises/chapter01/exercise1_2.cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET_DIR)/$@ $<

exercise1_3: exercises/chapter01/exercise1_3.cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET_DIR)/$@ $<

# 第二章练习
exercise2_1: exercises/chapter02/exercise2_1.cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET_DIR)/$@ $<

exercise2_2: exercises/chapter02/exercise2_2.cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET_DIR)/$@ $<

exercise2_3: exercises/chapter02/exercise2_3.cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET_DIR)/$@ $<

# 第三章练习
exercise3_1: exercises/chapter03/exercise3_1.cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET_DIR)/$@ $<

# 第四章练习
exercise4_1: exercises/chapter04/exercise4_1.cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET_DIR)/$@ $<

# 测试
test_exercise1_1: tests/chapter01/test_exercise1_1.cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET_DIR)/$@ $<

# 运行所有测试
test: $(ALL_TESTS)
	@echo "Running all tests..."
	@for test in $(ALL_TESTS); do \
		echo "Running $$test..."; \
		./$(TARGET_DIR)/$$test; \
	done

# 运行第一章练习
chapter1: $(CHAPTER1_EXERCISES)
	@echo "Running Chapter 1 exercises..."
	@for ex in $(CHAPTER1_EXERCISES); do \
		echo "Running $$ex..."; \
		./$(TARGET_DIR)/$$ex; \
		echo ""; \
	done

# 运行第二章练习
chapter2: $(CHAPTER2_EXERCISES)
	@echo "Running Chapter 2 exercises..."
	@for ex in $(CHAPTER2_EXERCISES); do \
		echo "Running $$ex..."; \
		./$(TARGET_DIR)/$$ex; \
		echo ""; \
	done

# 运行第三章练习
chapter3: $(CHAPTER3_EXERCISES)
	@echo "Running Chapter 3 exercises..."
	@for ex in $(CHAPTER3_EXERCISES); do \
		echo "Running $$ex..."; \
		./$(TARGET_DIR)/$$ex; \
		echo ""; \
	done

# 运行第四章练习
chapter4: $(CHAPTER4_EXERCISES)
	@echo "Running Chapter 4 exercises..."
	@for ex in $(CHAPTER4_EXERCISES); do \
		echo "Running $$ex..."; \
		./$(TARGET_DIR)/$$ex; \
		echo ""; \
	done

# 清理
clean:
	rm -rf $(TARGET_DIR)
	rm -f *.o
	rm -f *.out

# 帮助信息
help:
	@echo "C++ Learning Module Makefile"
	@echo ""
	@echo "Available targets:"
	@echo "  all        - Build all exercises"
	@echo "  chapter1   - Build and run Chapter 1 exercises"
	@echo "  chapter2   - Build and run Chapter 2 exercises"
	@echo "  chapter3   - Build and run Chapter 3 exercises"
	@echo "  chapter4   - Build and run Chapter 4 exercises"
	@echo "  test       - Build and run all tests"
	@echo "  clean      - Remove all build files"
	@echo "  help       - Show this help message"
	@echo ""
	@echo "Individual exercises:"
	@for ex in $(ALL_EXERCISES); do \
		echo "  $$ex"; \
	done
	@echo ""
	@echo "Individual tests:"
	@for test in $(ALL_TESTS); do \
		echo "  $$test"; \
	done

# 检查依赖
check-deps:
	@echo "Checking dependencies..."
	@which $(CXX) > /dev/null || (echo "Error: $(CXX) not found" && exit 1)
	@echo "$(CXX) found: $(shell $(CXX) --version | head -n1)"
	@echo "Dependencies OK"

# 安装（可选）
install: all
	@echo "Installing exercises to /usr/local/bin..."
	@sudo cp $(TARGET_DIR)/* /usr/local/bin/ || echo "Installation failed (try with sudo)"

.PHONY: all test chapter1 chapter2 chapter3 chapter4 clean help check-deps install 