/*
// By Dendi Suhubdy
*/

#ifndef STOCK_H
#define STOCK_H

#define RANDOMMAX 15
#define PATHMAX 260

#include <cmath>

class stock{
public:
	stock();
	double price(int time);
	void generatepicepaths();
	double pricepath[PATHMAX];
private:
	int *c;
};

#endif
