FLAGS = -Wall -Wextra -Werror -std=c11
CC = gcc
TEXT_FILE1 = grep_test1.txt
TEXT_FILE2 = grep_test2.txt
TEXT_FILE3 =not_found.txt
MY_GREP = ./s21_grep 
STD_GREP = /bin/grep


all: s21_grep test clean

s21_grep:
	$(CC) $(FLAGS) grep.c -o s21_grep

clean:
	rm -rf s21_grep

rebuild: clean all

clang:
	clang-format -n --style=google *.c *.h

test:
	@echo "Запуск тестов..."
	# Проверка флага без флагов
	@bash -c "diff <($(STD_GREP) HE $(TEXT_FILE1) $(TEXT_FILE2)) <($(MY_GREP) HE $(TEXT_FILE1) $(TEXT_FILE2))" && echo "Test 0:  OK" || echo "Test 1: FAILED"
	# Проверка флага -e
	@bash -c "diff <($(STD_GREP) -e HE $(TEXT_FILE1) $(TEXT_FILE2)) <($(MY_GREP) -e HE $(TEXT_FILE1) $(TEXT_FILE2))" && echo "Test 1:  OK" || echo "Test 1: FAILED"
	# Проверка флага -i
	@bash -c "diff <($(STD_GREP) -i he $(TEXT_FILE1) $(TEXT_FILE2)) <($(MY_GREP) -i he $(TEXT_FILE1) $(TEXT_FILE2))" && echo "Test 2:   OK" || echo "Test 2:  FAILED"
	# Проверка флага -v
	@bash -c "diff <($(STD_GREP) -v u $(TEXT_FILE1) $(TEXT_FILE2)) <($(MY_GREP) -v u $(TEXT_FILE1) $(TEXT_FILE2))" && echo "Test 3: OK" || echo "Test 3:  FAILED"
	# Проверка флага -c
	@bash -c "diff <($(STD_GREP) -c 1 $(TEXT_FILE1) $(TEXT_FILE2)) <($(MY_GREP) -c 1 $(TEXT_FILE1) $(TEXT_FILE2))" && echo "Test 4:  OK" || echo "Test 4: FAILED"
	# Проверка флага -l
	@bash -c "diff <($(STD_GREP) -l 1 $(TEXT_FILE1) $(TEXT_FILE2)) <($(MY_GREP) -l 1 $(TEXT_FILE1) $(TEXT_FILE2))" && echo "Test 5: OK" || echo "Test 5: FAILED"
	# Проверка флага -h
	@bash -c "diff <($(STD_GREP) -h HE $(TEXT_FILE1) $(TEXT_FILE2)) <($(MY_GREP) -h HE $(TEXT_FILE1) $(TEXT_FILE2))" && echo "Test 6:  OK" || echo "Test 6: FAILED"
	# Проверка флага -s
	@bash -c "diff <($(STD_GREP) -s HE $(TEXT_FILE1) $(TEXT_FILE2) notfound.txt) <($(MY_GREP) -s HE $(TEXT_FILE1) $(TEXT_FILE2) notfound.txt) " && echo "Test 7:  OK" || echo "Test 7:  FAILED"
	# Проверка флага -iv
	@bash -c "diff <($(STD_GREP) -iv HE $(TEXT_FILE1) $(TEXT_FILE2)) <($(MY_GREP) -iv HE $(TEXT_FILE1) $(TEXT_FILE2))" && echo "Test 8:  OK" || echo "Test 8: FAILED"
	# Проверка флага -in
	@bash -c "diff <($(STD_GREP) -in HE $(TEXT_FILE1) $(TEXT_FILE2)) <($(MY_GREP) -in HE $(TEXT_FILE1) $(TEXT_FILE2))" && echo "Test 9:  OK" || echo "Test 9: FAILED"
	# Проверка с несущетвующим файлом
	@bash -c "diff <(grep -e 123 $(TEXT_FILE1) $(TEXT_FILE2) notfound.txt)  <($(MY_GREP) -e 123 $(TEXT_FILE1) $(TEXT_FILE2) notfound.txt) " && echo "Test 10:  OK" || echo "Test 10: FAILED"
	# Проверка флага -h -e 
	@bash -c "diff <($(STD_GREP) -h -e HE $(TEXT_FILE1) $(TEXT_FILE2)) <($(MY_GREP) -h -e HE $(TEXT_FILE1) $(TEXT_FILE2))" && echo "Test 11:  OK" || echo "Test 11:  FAILED"
	@echo "Тесты завершены."