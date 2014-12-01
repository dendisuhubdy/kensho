/*
// By Dendi Suhubdy
*/

#ifndef PORTFOLIO_H
#define PORTFOLIO_H

#include "strategy.h"

class portfolio {
public:
	void init(double investment, decision *order);
    void countportreturn(decision *order, double *pricepath);
    void inventory(decision *order);
    double cummulativereturn[PATHMAX];
    double dailyreturn[PATHMAX];
    int inventoryheld[PATHMAX];
    double portfoliovalue;
private:
    double capital;
};

#endif
