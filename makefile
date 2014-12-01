all: kensho

kensho: main.o stock.o strategy.o portfolio.o
	g++ main.o stock.o strategy.o portfolio.o -o kensho

main.o: main.cpp
	g++ -c main.cpp -std=c++11

stock.o: stock.cpp
	g++ -c stock.cpp -std=c++11

strategy.o: strategy.cpp
	g++ -c strategy.cpp -std=c++11

portfolio.o: portfolio.cpp
	g++ -c portfolio.cpp -std=c++11

clean:
	rm -rf *.o kensho
