run:
	g++ -DLOCAL -std=c++11 -Wshadow -Wall -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -O2 -g main.cpp	&& ./a.out
fast:
	g++ -DLOCAL -std=c++11  main.cpp 
