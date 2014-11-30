/*
// By Dendi Suhubdy
*/

#include <iostream>

#include "stock.h"
#include "strategy.h"

int main(int argc, const char * argv[])
{
	std::cout << "Cummulative portfolio return by Dendi Suhubdy" << std::endl;
	stock *GM = new stock;
	GM->generatepicepaths();
	for (int t=0; t<=MAX ; t++) {
		std::cout << GM->pricepath[t] << std::endl;
	}
}
