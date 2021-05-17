SRCS := $(wildcard *.c)
OBJS := $(patsubst %.c,%.o,$(wildcard *.c)) 

libsort.a: $(OBJS)
	ar rv $@ $<
%.o: %.c
	gcc -c $< -o $@
