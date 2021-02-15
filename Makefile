run:
	g++ -DLOCAL -std=c++11 -Wshadow -Wall -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -O2 -g main.cpp	&& ./a.out $(path)
verbose:
	g++ -Dverbose -std=c++11  main.cpp  && ./a.out $(path)
test:
	g++ -DTEST -std=c++11 test.cpp && ./a.out
