FLAGS = -Wall -Wextra -Werror -std=c11
CC = gcc
TEXT_FILE1 = cat_test1.txt
TEXT_FILE2 = cat_test2.txt
MY_CAT = ./s21_cat 
STD_CAT = /bin/cat
TARGET = s21_cat

all: $(TARGET) test clean

s21_cat:
	$(CC) $(FLAGS) cat.c -o $(TARGET)

clean:
	rm -rf $(TARGET)

rebuild: clean all

clang:
	clang-format -n --style=google *.c *.h

test: $(TARGET)
	@echo "Запуск тестов..."
	# Проверка флага -E
	@bash -c "diff <($(STD_CAT) -E $(TEXT_FILE1)) <($(MY_CAT) -E $(TEXT_FILE1))" && echo "Test 0: -E OK" || echo "Test 1: -E FAILED"
	# Проверка флага -e
	@bash -c "diff <($(STD_CAT) -e $(TEXT_FILE1)) <($(MY_CAT) -e $(TEXT_FILE1))" && echo "Test 1: -e OK" || echo "Test 1: -e FAILED"
	# Проверка флага -b
	@bash -c "diff <($(STD_CAT) -b $(TEXT_FILE1)) <($(MY_CAT) -b $(TEXT_FILE1))" && echo "Test 2: -b OK" || echo "Test 2: -b FAILED"
	# Проверка флага -v
	@bash -c "diff <($(STD_CAT) -v $(TEXT_FILE1)) <($(MY_CAT) -v $(TEXT_FILE1))" && echo "Test 3: -v OK" || echo "Test 3: -v FAILED"
	# Проверка флага -T
	@bash -c "diff <($(STD_CAT) -T $(TEXT_FILE1)) <($(MY_CAT) -T $(TEXT_FILE1))" && echo "Test 4: -T OK" || echo "Test 4: -T FAILED"
	# Проверка флага -t
	@bash -c "diff <($(STD_CAT) -t $(TEXT_FILE1)) <($(MY_CAT) -t $(TEXT_FILE1))" && echo "Test 5: -t OK" || echo "Test 5: -t FAILED"
	# Проверка объединения двух файлов
	@bash -c "diff <($(STD_CAT) $(TEXT_FILE1) $(TEXT_FILE2)) <($(MY_CAT) $(TEXT_FILE1) $(TEXT_FILE2))" && echo "Test 6: Combine files OK" || echo "Test 6: Combine files FAILED"
	# Проверка флага -n
	@bash -c "diff <($(STD_CAT) -n $(TEXT_FILE1)) <($(MY_CAT) -n $(TEXT_FILE1))" && echo "Test 7: -n OK" || echo "Test 7: -n FAILED"
	# Проверка флага -s
	@bash -c "diff <($(STD_CAT) -s $(TEXT_FILE1)) <($(MY_CAT) -s $(TEXT_FILE1))" && echo "Test 8: -s OK" || echo "Test 8: -s FAILED"
	# Проверка использования нескольких флагов
	@bash -c "diff <($(STD_CAT) -n -e $(TEXT_FILE1)) <($(MY_CAT) -n -e $(TEXT_FILE1))" && echo "Test 9: -n -e OK" || echo "Test 9: -n -e FAILED"
	# Проверка с пустым файлом
	@bash -c "diff <($(STD_CAT) /dev/null) <($(MY_CAT) /dev/null)" && echo "Test 10: Empty file OK" || echo "Test 10: Empty file FAILED"
	# Проверка длинных фоагов
	@bash -c "diff <($(STD_CAT) --number-nonblank -e --squeeze-blank $(TEXT_FILE1)) <($(MY_CAT) --number-nonblank -e --squeeze-blank $(TEXT_FILE1))" && echo "Test 11: --number-nonlank -e --squeeze-blank OK" || echo "Test 11: --number-nonlank -e --squeeze-blank FAILED"
	@echo "Тесты завершены."





