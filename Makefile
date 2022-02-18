program: Main.o User.o ATMUser.o ATM.o
	g++ Main.o User.o ATMUser.o ATM.o -o program

Main.o: Main.cpp
	g++ -c Main.cpp

User.o: User.cpp
	g++ -c User.cpp

ATMUser.o: ATMUser.cpp
	g++ -c ATMUser.cpp

ATM.o: ATM.cpp
	g++ -c ATM.cpp

clean:
	rm *.o