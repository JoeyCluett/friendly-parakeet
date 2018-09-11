g++ -c core/core.cpp -o obj/core.o -std=c++11 -O3
g++ -c main/main.cpp -o obj/main.o -std=c++11 -O3 -I./core/
g++ -o bin/main obj/core.o obj/main.o -std=c++11 -O3 
