myshell: myshell.cpp param.cpp param.hpp parse.cpp parse.hpp
	g++ -g -Wall myshell.cpp param.cpp parse.cpp -o myshell

clean:
	rm -f myshell