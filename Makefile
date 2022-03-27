program: Main.o User.o ATMUser.o ATM.o
	g++-11 Main.o User.o ATMUser.o ATM.o -o program

Main.o: Main.cpp
	g++-11 -c Main.cpp

User.o: User.cpp
	g++-11 -c User.cpp

ATMUser.o: ATMUser.cpp
	g++-11 -c ATMUser.cpp

ATM.o: ATM.cpp
	g++-11 -c ATM.cpp

clean:
	rm *.o