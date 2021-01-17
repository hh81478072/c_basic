CC = gcc
HSRCS = $(wildcard *.h) 
SRCS = $(wildcard *.c) 
OBJS = $(addsuffix .o, $(basename $(SRCS)))

CXXFLAGS += -Wall -Werror -g

a.out: $(OBJS)
	$(CC) $(CXXFLAGS) -o $@ $(OBJS) $(LDFLAGS)

%.o: %.c $(HSRCS)
	$(CC) $(CXXFLAGS) $(INCLUDES) $(DEFINES) -c -o $@ $<

clean:
	$(RM) -f $(OBJS) a.out

