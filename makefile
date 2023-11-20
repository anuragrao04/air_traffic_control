CC = gcc

CFLAGS = -Wall -g -lm

SRCS = main.c anikethan/anikethan.c anujna/anujna.c

OBJS = $(SRCS:.c=.o)

MAIN = whos_your_classmate

.PHONY: depend clean

all:   $(MAIN)
	@printf "\n\nProgram has been compiled! Run ./air_traffic_control to execute the program.\n"

$(MAIN): $(OBJS) 
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(MAIN)

depend: $(SRCS)
	makedepend $^
