/* 
 * Audrey Bender
 */

#include "Network.hpp" 
#include <random>


using namespace std; 



//Constructeur 
Network::Network() 
{	

default_random_engine generator;
 NeuronesConnection N(12500, vector<int>(12500, 0));
 neurones = N;
   for( size_t j(0); j <= 12500; ++j) {
	   
       int connectNumber(0);
	  do {
		  
	    for (size_t i(0); i < Ne; ++i ) {
			
	     	uniform_int_distribution<int> distribution(0,1);
			neurones[j][i] = distribution(generator); 
			//Connection randomly and uniformly distributed
			if ( neurones[j][i] == 1 ) {
				connectNumber += 1; 
			}
		  }
	   }while (connectNumber != Ce );
	   
	 do {
	   for (size_t i(Ne); i <= 12500 ; ++i ) {
		   uniform_int_distribution<int> distribution(0,1);
		   neurones[j][i] = distribution(generator); 
	     if ( neurones[j][i] == 1 ) {
				connectNumber += 1; 
			}
	    }
    }while( connectNumber != (Ce+Ci) );
  } 
 
  for ( size_t j(0); j <= 2; ++j ) {
	  Neurone* N1; 
	  brain.push_back(N1);
  }
  cerr << " contructor done " << endl; 
 
}

//Destructeur 
Network::~Network()
{
	cerr << " destruction begins " << endl; 
	brain.clear();
	
}

//Methodes

void Network::update(unsigned long time) {

	for (  size_t j(0); j < neurones.size() ; ++j ) {
		for( size_t i(0); i < Ne; ++i ) {
			if( neurones[j][i] == 1 ) {
				if( brain[i]->update(time) ) {
					brain[j]->receive( (brain[i]->getClock() + delay ), Je); 
				}
			}
		}
		
		for( size_t i(Ne); i < neurones.size() ; ++i ) {
			if ( neurones[j][i] == 1 ) {
				if( brain[i]->update(time) ) {
					brain[j]->receive( (brain[i]->getClock() + delay ), Ji ); 
				}
			}
		}
	}
	cerr << " update done " << endl; 
}
