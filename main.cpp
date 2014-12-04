/*
// By Dendi Suhubdy
*/

#include <iostream>

#include "stock.h"
#include "strategy.h"
#include "portfolio.h"

int main(int argc, const char * argv[])
{
	// Opening message
	std::cout << "Cummulative portfolio return by Dendi Suhubdy" << std::endl;
  std::cout << "Kensho Coding Puzzle" << std::endl;

	// Create a new stock object
	stock *equity = new stock;

	// Create a new portfolio
	portfolio *stocks = new portfolio;

	// Create new strategy object
	strategy *strat = new strategy;

	// Generate price paths for equity
	equity->generatepicepaths();

	// Initialize strategy
	strat->init(98,100);

	// Analyse and make trade decisions based on upper and lower bound
	strat->trade(equity->pricepath);

  // Initialize capital to $1000
  stocks->init(1000.00, strat->order);

  stocks->countportreturn(strat->order, equity->pricepath);


	for (int i=0; i<=PATHMAX-1; i++) {
		std::cout << equity->pricepath[i]
                  << " trade to: "
                  << strat->tradedec(strat->order[i])
                  << " inventory holding is "
                  << stocks->inventoryheld[i]
                  << " shares."
									<< " Shares held is: "
									<< stocks->shares[i]
                  << " Daily return is "
                  << (stocks->dailyreturn[i])*100
									<< " Portfolio value: "
									<< stocks->portfoliovalue[i]
									<< " Cash value: "
									<< stocks->cash[i]
                  << " Cummulative portfolio return since start: "
                  << stocks->cummulativereturn[i]
									<< "%"
                  << std::endl;
	}

	delete equity;
	delete strat;
	delete stocks;

	return 0;

}
