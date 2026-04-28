FORMATTER = clang-format

SRC_FILES := $(shell find . -name "*.c" -o -name "*.h")

TEST_SRCS := $(shell find . -name "*_test.c")

TEST_BINS := $(TEST_SRCS:.c=)

.PHONY: help clean format check-format test

help:
	@echo "Доступные цели:"
	@echo "  make clean        - очистка директории от бинарников и .o файлов"
	@echo "  make format       - автоматическое форматирование кода ($(FORMATTER))"
	@echo "  make check-format - проверка кода на соответствие стилю (без изменений)"
	@echo "  make test         - сборка и запуск всех тестов (*_test.c)"

clean:
	@echo "Очистка сгенерированных файлов"
	rm -f $(TEST_BINS)
	find . -type f -name "*.o" -delete

check-format:
	@echo "Проверка форматирования кода"
	$(FORMATTER) --dry-run --Werror $(SRC_FILES)

format:
	@echo "Применение форматирования"
	$(FORMATTER) -i $(SRC_FILES)

test: $(TEST_BINS)
	@echo "Запуск тестов"
	@for test_bin in $(TEST_BINS); do \
		echo "----------------------------------------"; \
		echo "Выполнение $$test_bin:"; \
		./$$test_bin || exit 1; \
	done
	@echo "----------------------------------------"
	@echo "Все тесты успешно пройдены!"

%_test: %_test.c
	gcc -Wall -Wextra -std=c11 -g $< -o $@ -lm