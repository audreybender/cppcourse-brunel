#include "neurone.hpp" 
#include <cmath>

constexpr double h(0.1);
using namespace std; 


//Constructeur
Neurone::Neurone( double membranePotential, double timeSpikes,
				double currentExt, int numberSpikes, bool refractory )
		{
			refractory = false;
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
//Méthodes
double Neurone::calculPotential() {
	double Potential = getPotential(); 
	double constant( exp( -h / tao ) );
	double newPotential;
	newPotential = Potential * constant 
			+ getCurrentExt() * R / tao * (1- constant); 
	if ( newPotential > Potential ) {
		numberSpikes +=1; 
	}
	setPotential( newPotential ); 
	return newPotential;
}

void Neurone::update() {

		if ( getRefractory() ){
			setPotential(0.0);
		}else{
		
		//if ( getPotential() > Vth ) {
		calculPotential();
		//}
	}
}
