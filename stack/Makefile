CC = gcc
HSRCS = $(wildcard *.h) 
SRCS = $(wildcard *.c) 
OBJS = $(addsuffix .o, $(basename $(SRCS)))

CXXFLAGS += -Wall -Werror -g
lib: libstack.so
a.out: $(OBJS)
	$(CC) $(CXXFLAGS) -o $@ $(OBJS) $(LDFLAGS)

libstack.so: Stack.o
	$(CC) -fPIC -shared -o $@ $<

%.o: %.c $(HSRCS)
	$(CC) $(CXXFLAGS) $(INCLUDES) $(DEFINES) -c -o $@ $<

clean:
	$(RM) -f $(OBJS) a.out

