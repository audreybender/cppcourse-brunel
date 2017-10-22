#include "neurone.hpp" 
#include "constant.hpp"
#include <cmath>
#include <assert.h>


using namespace std; 


//Constructeur
Neurone::Neurone( double membranePotential, unsigned long timeSpikes,
				double currentExt,unsigned long numberSpikes, bool refractory,
				unsigned long clock, double refStep )
			
		{
			membranePotential = 0.0;
			timeSpikes = 0;
			currentExt = 0.0;
			numberSpikes = 0;
			refractory = false;
			clock = 0;
			refStep = ( refTime / h);
			for ( auto& element : buffer) {
				element = 0; 
			} 
		}
		
//Destructeur 
Neurone::~Neurone(){}
//Getters
double Neurone::getPotential() const {
	return membranePotential; 
}

double Neurone::getNumberSpikes() const {
	return numberSpikes;
}
double Neurone::getTimeSpikes() const {
	return timeSpikes; 
}
double Neurone::getCurrentExt() const {
	return currentExt;
}
bool Neurone::getRefractory() const {
	return refractory;
}
double Neurone::getClock() const {
	return clock;
}
//Setter
void Neurone::setPotential( double p) {
	membranePotential = p; 
}
void Neurone::setCurrentExt( double c) {
	currentExt = c; 
}
void Neurone::setRefractory( bool r) {
	refractory = r; 
}
void Neurone::setNumberSpikes( int n) {
	numberSpikes = n;
}
//Méthodes

bool Neurone::update(unsigned long time) {
	
		bool spike(false);
		unsigned long tStop = clock + time; 
		
		
		while( clock < tStop) 
		{
			unsigned long tStart = clock % (delayStep + 1); 
			
			if ( getPotential() > Vth) {
			//	setRefractory( true );	
			spike = true; 
			numberSpikes += 1; 
			timeSpikes = clock; 
			}
			
		if ( (timeSpikes > 0) and (clock-timeSpikes < refStep) ){
			setPotential(0.0);
		 
		}else{
			assert( tStart < buffer.size() );
			double potential = getPotential();
			setPotential( c1*potential + c2*getCurrentExt() + buffer[tStart]  );	
		}
		
		buffer[tStart] = 0; 
		clock += 1; 
		}
		
		if ( numberSpikes > 0 ) {
			spike = true;
		}
	return spike;
}

void Neurone::receive(unsigned long clockDelay, double j)
{
	int tOut = (clockDelay%(delayStep + 1)); 
	buffer[tOut] += j; 

}
