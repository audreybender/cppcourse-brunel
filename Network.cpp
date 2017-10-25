/* 
 * Audrey Bender
 */

#include "Network.hpp" 
#include "constant.hpp"
#include <cmath>


using namespace std; 

//Constructeur 
Network::Network( Neurones network) 
{
	for( auto neurone : network ){
		for( auto connection : neurone ) {
			connection = 0; 
			// random 1 ou 0 
		}
	}
	
}

//Destructeur 
Network::~Network(){}

//Methodes

void Network::update() {
	for ( auto neurone : network) {
		for( size_t i(0); i < Ne; ++i ) {
			if( neurone[i] = 1 ) {
				if( network[i].update() ) {
					neurone.receive( /*clockDelay*/, Je); 
				}
			}
		}
		
		for( size_t i(Ne); i < neurone.size() ; ++i ) {
			if neurone[i] = 1 ) {
				if( network[i].update() ) {
					neurone.receive( /*clockDelay*/, Ji /* pourquoi pas 0.0 ? */); 
				}
			}
		}
	}
	
}
void Network::receive(unsigned long clockDelay, long double j){
	// ------------------>>>>>  choix random de 10% des neurones faire un array
	array<Neurone, Next> outsideConnection; //Neurones connected with outside 
	for ( auto neurone : outsideConnection ) {
		neurone.receive(clockDelay, j);  
	}
	
}
