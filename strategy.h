/*
// By Dendi Suhubdy
*/

#ifndef STRATEGY_H
#define STRATEGY_H

#include <iostream>
#include <cstring>

#define RANDOMMAX 15
#define PATHMAX 260

enum decision {N=0,BUY, SELL};

//enum FLAG {LONG=0, SHORT};

class strategy {
public:
	void init(double lowerbound_init, double upperbound_init);
	void trade(double *pricepath);
	decision order[PATHMAX];
    std::string tradedec(decision order);
	// FLAG fund; prevents from double Buy buy or Sell Sell, flag purpose
private:
	bool betweenintervals(double price);
	bool belowintervals(double price);
	bool aboveintervals(double price);
    bool islong(int curr_index, decision *order, double price);
    bool isshort(int curr_index, decision *order);
    bool isbeginning(int curr_index);
    bool isendandhold(int curr_index, decision *order);
	double upperbound;
	double lowerbound;
};

#endif
