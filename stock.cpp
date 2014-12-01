/*
// By Dendi Suhubdy
*/

#include "stock.h"

stock::stock()
{
	// Initializing the properties of the stock
	c = new int[RANDOMMAX] {46, 64, 98, 99, 101, 104, 106, 107, 109, 110, 111, 111, 111, 115, 115};
}

// price deterministic value

double stock::price(int time)
{
	double result;
	double sum;
	for (int i=0; i<=15; i++) {
			sum += (sin(time*c[i]));
	}
	result = 100 + sum;
	return result;
}

// Generating price path with respect to time

void stock::generatepicepaths()
{
	for (int t=0; t <= PATHMAX; t++) {
		pricepath[t] = price(t);
	}
}
