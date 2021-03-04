CC = gcc

SRCS = $(wildcard *.c) \
       $(wildcard hashmap/*.c) \
       $(wildcard lookup/*.c) \
       $(wildcard trie/*.c)

HEADERS = $(wildcard *.h) \
          $(wildcard map/*.h) \
          $(wildcard lookup/*.h) \
          $(wildcard trie/*.h)

OBJECTS = $(SRCS:.c=.o)

./main: $(OBJECTS)
	$(CC) $^ -o $@

./%.o: %.c $(HEADERS)
	$(CC) $< -c -o $@

.PHONY: clean
clean:
	rm -f $(obj) main