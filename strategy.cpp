
#include "strategy.h"

void strategy::init(double lowerbound_init, double upperbound_init)
{
	lowerbound = lowerbound_init;
	upperbound = upperbound_init;
}

void strategy::trade(double *pricepath)
{
    // reiterate loop for decision array
	for (int i=0; i<=PATHMAX; i++) {
		if(this->isbeginning(i)) {
            if(this->belowintervals(pricepath[i])) {
                order[i] = N;
            }
            else if(this->aboveintervals(pricepath[i])) {
                order[i] = N;
            }
            else if(this->betweenintervals(pricepath[i])) {
                order[i] = BUY;
            }
        }
        
        else if(this->betweenintervals(pricepath[i])) {
            // Check if previous state has been BUY
            
            if (this->isshort(i, order)) {
                order[i] = BUY;
            }
            else if (this->islong(i, order, pricepath[i])) {
                order[i] = N;
            }
            else
                order[i] = BUY;
        }
        
        else if(this->aboveintervals(pricepath[i])) {
            if(this->isshort(i, order)) {
                order[i] = N;
            }
            else
                order[i] = SELL;
        }
        
        else if(this->isendandhold(i, order))
        {
            order[i] = SELL;
        }
	}
}

// burn in strategies, add additional strategies here

bool strategy::betweenintervals(double price)
{
    // Check if prices are between intervals
	if((price <= this->upperbound) && (price >= this->lowerbound)) {
		return true;
	}
	else
        return false;
}

bool strategy::belowintervals(double price)
{
    // Check if prices are below intervals
	if(price < this->lowerbound) {
		return true;
	}
	else
        return false;
}

bool strategy::aboveintervals(double price)
{
    // Check if prices are above intervals
	if(price > this->upperbound) {
		return true;
	}
	else
        return false;
}

bool strategy::islong(int curr_index, decision *order, double price)
{
    // Check if there are any buy positions
    while (order[curr_index]!=BUY) {
        if(order[curr_index]==SELL) {
            return false;
            break;
        }
        curr_index--;
    }
    return true;
}

bool strategy::isshort(int curr_index, decision *order)
{
    // Check if there are any sell positions
    while (order[curr_index]!=SELL) {
        if(order[curr_index]==BUY) {
            return false;
            break;
        }
        curr_index--;
    }
    return true;
}

bool strategy::isbeginning(int curr_index)
{
    // Check if it is beginning of the price path
    if (curr_index==0) {
        return true;
    }
    else return false;
}

bool strategy::isendandhold(int curr_index, decision *order)
{
    // Check if it is end of the price path
    if (curr_index==PATHMAX) {
        while (order[curr_index]!=N) { // check backwards if there is any hold position
            curr_index--;
        }
        return true; // if Hold found return true
    }
    else return false;
}

std::string strategy::tradedec(decision order)
{
    if (order==BUY)
    {
        return "BUY";
    }
    else if (order==N)
    {
        return "DO NOTHING";
    }
    else if (order==SELL)
    {
        return "SELL";
    }
    else
        return "DO NOTHING";
}

