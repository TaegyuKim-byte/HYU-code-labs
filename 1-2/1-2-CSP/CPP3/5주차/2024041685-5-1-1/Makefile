all: shapes.o main.o
	g++ -o draw_shape shapes.o main.o

shapes.o: shapes.cc
	g++ -c -o shapes.o shapes.cc

main.o: main.cc
	g++ -c -o main.o main.cc

clean: 
	rm draw_shape shapes.o main.o

