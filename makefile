

mp: Main.o Student.o Date.o Address.o
	g++ main.o Student.o Date.o Address.o -o mp

Main.o: main.cpp Student.h Address.h Date.h
	g++ -Wall -c main.cpp

Student.o: Student.cpp Student.h Address.h Date.h
	g++ -Wall -c Student.cpp

Date.o: Date.cpp Date.h
	g++ -Wall -c Date.cpp

Address.o: Address.cpp Address.h
	g++ -Wall -c Address.cpp