#include "neurone.hpp" 
#include "constant.hpp"
#include <cmath>


using namespace std; 


//Constructeur
Neurone::Neurone( double membranePotential, double timeSpikes,
				double currentExt, int numberSpikes, bool refractory,
				double clock )
		{
			membranePotential= 0.0;
			timeSpikes = 0.0;
			currentExt = 00;
			numberSpikes = 0.0;
			refractory = false;
			clock = 0.0;
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
void Neurone::calculPotential() {
	double Potential = getPotential(); 
	double constant( exp( (-h / tao ) ));
	double newPotential;
	newPotential = Potential * constant 
			+ getCurrentExt() * R * (1- constant); 
	setPotential( newPotential ); 
}

bool Neurone::update(double time) {
		bool spike(false);
		double timeR(0.0);
		
		if ( buffer.CQ[buffer.getFront()] != 0.0 ) {
			setPotential( buffer.getFront() );
		}
		
		if (membranePotential > Vth) {
			setRefractory( true );	
		}
		if ( getRefractory() == true ){
			setPotential(0.0);
			timeR += time;
				if ( timeR > refTime ) {
					setRefractory( false );
					timeR = 0.0;
					numberSpikes +=1;
			}
		 
		}else{
			calculPotential();	
		}
		
		clock +=time;
		buffer.dequeue(); 
	
		if ( numberSpikes > 0 ) {
			spike = true;
		}
	
	return spike;
}

void Neurone::receive(double clockDelay, double j){

	buffer.enqueue( getPotential() + j); 

}
