all: intset.o main.o
	g++ -o integer_set intset.o main.o

intset.o: intset.cc
	g++ -c -o intset.o intset.cc

main.o: main.cc
	g++ -c -o main.o main.cc

clean:
	rm integet_set intset.o main.o
