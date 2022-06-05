CC = gcc
CFLAGS = -Wall -Wextra -pedantic-errors -O2
LIBS = -lm
OBJS = src/main.o src/stack.o src/parser.o src/operators/operations.o src/operators/mathematics.o src/operators/conversions.o src/structures/strings.o src/structures/arrays.o src/structures/blocks.o 
TARGET = main
DOC_FILE = cfg/doxygen.config
COVERAGE_FILE = cfg/doxygen-coverage.info

define test_script = 
	pmccabe src/**/*.c | awk -v OFS='\t' 'BEGIN {printf "%s\t%s\t%s\n", "CC", "NOI", "FUNCTION"} {print $1, $3, $6 $7}' | sort -n
endef

define coverage_script =
	python3 -m coverxygen --xml-dir doc/xml --src-dir src/ --format summary --output cfg/doxygen-coverage.info
endef

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

run: $(TARGET)
	./main

clean:
	@rm -f $(TARGET) $(OBJS)

test:
	$(value test_script)

submit:
	zip -r submission.zip src/**/*{.c,.h}

doc: $(DOC_FILE)
	doxygen $(DOC_FILE)

coverage: doc
	$(value coverage_script); clear; cat $(COVERAGE_FILE); rm $(COVERAGE_FILE)

log: 
	chmod +x cfg/repl; ./cfg/repl
