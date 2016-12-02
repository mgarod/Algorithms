TARGET = CPP_QS
OBJS = main.o randomIntArray.o
CC = g++
DEBUG = -g$
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

$(TARGET): $(OBJS) 
	$(CC) $(LFLAGS) $(OBJS) -o $(TARGET)

main.o: main.cpp randomIntArray.h
	$(CC) -c main.cpp

randomIntArray.o: randomIntArray.h
	$(CC) $(CFLAGS) randomIntArray.cpp

clean: $(OBJS) $(TARGET)
	rm $(OBJS) $(TARGET)