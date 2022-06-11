CCF = gcc -Wall -Wextra -Werror

all: s21_string.a test gcov_report

test:
	$(CCF) -std=c11 s21_test.c s21_string.c sprintf/*.c  -lcheck -coverage -o test.out
	rm -rf s21_test.gcno

s21_string.a:
	$(CCF) -c s21_string.c sprintf/*.c
	ar rcs s21_string.a *.o
	ranlib s21_string.a
	rm -rf *.o

gcov_report: test
	./test.out
	lcov -t "gcov_report" -o gcov_report.info -c -d ./ 
	genhtml -o report gcov_report.info;
	rm -rf *.info *.gcda *.gcno *.out
	clear

clean:
	rm -rf *.info *.gcda *.gcno report *.out *.o