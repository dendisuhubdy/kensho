/*
// By Dendi Suhubdy
*/

#ifndef STOCK_H
#define STOCK_H

#define MAX 260

#include <cmath>

class stock{
public:
	stock();
	double price(int time);
	void generatepicepaths();
	double pricepath[MAX];
private:
	int *c;
};

#endif
