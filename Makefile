CXXFLAGS=-std=c++11 -Wall
CC=c++
OBJS=main.o AIPlayer.o GameState.o


tic-tac-toe: $(OBJS)
	$(CC) $(CXXFLAGS) $^ -o $@

clean:
	rm tic-tac-toe *.o
