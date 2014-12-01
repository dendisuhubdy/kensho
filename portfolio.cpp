#include "portfolio.h"

void portfolio::init(double investment, decision *order)
{
	capital = investment;
    this->inventory(order);
    portfoliovalue = capital;
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
            if (inventoryheld[i-1]==1) { // which means hold
                inventoryheld[i] = inventoryheld[i-1];
            }
            else if(inventoryheld[i-1]==0) { //which means we don't own anything
                inventoryheld[i] = 0;
            }
        }
    }
}

void portfolio::countportreturn(decision *order, double *pricepath)
{
    
    for(int i = 0; i<=PATHMAX; i++) {
        if (i==0) {
            dailyreturn[i]=0;
            cummulativereturn[i] = 1;
            continue;
        }
        if (inventoryheld[i]==1 && order[i]==BUY) {
            dailyreturn[i] = 0;
            cummulativereturn[i] = cummulativereturn[i-1]*(1+dailyreturn[i]);
        }
        else if(inventoryheld[i]==0 && order[i]==SELL) {
            dailyreturn[i] = (pricepath[i] - pricepath[i-1])/pricepath[i-1];
            cummulativereturn[i] = cummulativereturn[i-1]*(1+dailyreturn[i]);
        }
        else if (inventoryheld[i]==1) {
            dailyreturn[i] = (pricepath[i] - pricepath[i-1])/pricepath[i-1];
            cummulativereturn[i] = cummulativereturn[i-1]*(1+dailyreturn[i]);
        }
        else if(inventoryheld[i]==0) {
            dailyreturn[i] = 0;
            cummulativereturn[i] = cummulativereturn[i-1]*(1+dailyreturn[i]);
        }
    }
}
