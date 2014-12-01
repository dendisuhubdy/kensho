#include "portfolio.h"

void portfolio::init(double investment, decision *order)
{
	capital = investment;
    this->inventory(order);
    portfoliovalue = capital;
}

int portfolio::sharesheld(double portfolioval, double price)
{
	return (portfolioval/price);
}

void portfolio::inventory(decision *order)
{
    for (int i=0; i<=PATHMAX; i++) {
        if (i==0) {
            if(order[i]==BUY) {
                inventoryheld[i] = 1;
            }
            else if(order[i]==N) {
                inventoryheld[i] = 0;
            }
        }
        else if(order[i]==BUY) {
            inventoryheld[i] = inventoryheld[i-1] + 1;
        }
        else if(order[i]==SELL) {
            inventoryheld[i]= inventoryheld[i-1] - 1 ;
        }
        else if(order[i]==N) {
            if (inventoryheld[i-1]==true) { // which means hold
                inventoryheld[i] = inventoryheld[i-1];
            }
            else if(inventoryheld[i-1]==false) { //which means we don't own anything
                inventoryheld[i] = false;
            }
        }
    }
}

void portfolio::countportreturn(double *pricepath)
{
    for(int i = 0; i<=PATHMAX; i++) {
        if (i==0) {
            dailyreturn[i]=0;
            cummulativereturn[i] = 1;
        }
        else {
            if (inventoryheld[i]==true) {
                dailyreturn[i] = (pricepath[i] - pricepath[i-1])/pricepath[i-1];
            }
            else if(inventoryheld[i]==false) {
                dailyreturn[i] = cummulativereturn[i-1];
            }
        }
    }
}
