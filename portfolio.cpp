#include "portfolio.h"

void portfolio::init(double investment, decision *order)
{
	capital = investment;
  this->inventory(order);
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
					portfoliovalue[i] = capital;
					shares[i] = (this->sharesheld(capital,pricepath[i]));
					cash[i] = (this->cashheld(capital,pricepath[i]));
					cummulativereturn[i] = ((portfoliovalue[i] - capital) / capital )*100;
        }
        else if (inventoryheld[i]==1 && order[i]==BUY) {
          dailyreturn[i] = 0;
					shares[i] = (this->sharesheld(portfoliovalue[i-1],pricepath[i]));
					cash[i] = this->cashheld(portfoliovalue[i-1],pricepath[i]);
					portfoliovalue[i] = this->portfvalue(shares[i], pricepath[i]) + cash[i];
					cummulativereturn[i] = ((portfoliovalue[i] - capital) / capital )*100;
        }
        else if(inventoryheld[i]==0 && order[i]==SELL) {
          dailyreturn[i] = (pricepath[i] - pricepath[i-1])/pricepath[i-1];
					shares[i] = shares[i-1];
					cash[i] = cash[i-1];
					portfoliovalue[i] = this->portfvalue(shares[i], pricepath[i]) + cash[i-1];
					cummulativereturn[i] = ((portfoliovalue[i] - capital) / capital )*100;
        }
        else if (inventoryheld[i]==1) {
					dailyreturn[i] = (pricepath[i] - pricepath[i-1])/pricepath[i-1];
					shares[i] = shares[i-1];
					cash[i] = cash[i-1];
					portfoliovalue[i] = this->portfvalue(shares[i], pricepath[i-1]) + cash[i-1];
					cummulativereturn[i] = ((portfoliovalue[i] - capital) / capital )*100;
        }
        else if(inventoryheld[i]==0) {
					dailyreturn[i] = 0;
					shares[i] = shares[i-1];
					cash[i] = cash[i-1];
					portfoliovalue[i] = portfoliovalue[i-1];
					cummulativereturn[i] = ((portfoliovalue[i] - capital) / capital )*100;
        }
    }
}

int portfolio::sharesheld(double portvalue, double price)
{
	return (portvalue/price);
}

double portfolio::portfvalue(int shares, double price)
{
	return (shares*price);
}

double portfolio::cashheld(double portvalue, double price)
{
	return fmod(portvalue,price);
}
