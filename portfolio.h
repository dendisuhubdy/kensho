/*
// By Dendi Suhubdy
*/

#ifndef PORTFOLIO_H
#define PORTFOLIO_H

#include <cmath>

#include "strategy.h"

class portfolio {
public:
	void init(double investment, decision *order);
  void countportreturn(decision *order, double *pricepath);
  void inventory(decision *order);
	double cashheld(double portvalue, double price);
	int sharesheld(double portvalue, double price);
	double portfvalue(int shares, double price);
  double cummulativereturn[PATHMAX];
  double dailyreturn[PATHMAX];
  int inventoryheld[PATHMAX];
  double portfoliovalue[PATHMAX];
	int shares[PATHMAX];
	double cash[PATHMAX];
	double capital;
};

#endif
