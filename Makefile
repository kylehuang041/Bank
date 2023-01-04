compileAll: Main.cpp User/User.cpp ATM/ATMUser.cpp ATM/ATM.cpp
	g++-11 Main.cpp User/User.cpp ATM/ATMUser.cpp ATM/ATM.cpp -o program

clean:
	rm program