/*
// By Dendi Suhubdy
*/

#ifndef STRATEGY_H
#define STRATEGY_H

class strategy {
public:
	decision investment(double upperbound, double lowerbound);
private:
	enum decision {hold=0,buy, sell, NA};
};

#endif
