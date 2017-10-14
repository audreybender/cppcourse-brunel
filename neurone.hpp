#ifndef NEURONE_HPP
#define NEURONE_HPP

#include <iostream>
#include <array>
#include "CQ.cpp"

using namespace std; 
	

class Neurone {
	public : 

	//Constructeur
	Neurone( double membranePotential=0.0, double timeSpikes=0.0,
			double currentExt=0.0, int numberSpikes=0,
			 bool refractory=false, double clock= 0.0 );
	//Destructeur
	~Neurone();
	//Getter
	double getPotential() const; 
	double getNumberSpikes() const; 
	double getTimeSpikes() const;
	double getCurrentExt() const; 
	bool getRefractory() const;
	double getClock() const; 
	//Setter
	void setPotential( double p);
	void setCurrentExt( double c);
	void setRefractory( bool r);
	void setNumberSpikes( int n);
	//Méthodes 
	bool update(double time); 
	void calculPotential(); 
	void receive(double clockDelay, double j);
	
	
	private : 
	double membranePotential; 
	double timeSpikes;
	double currentExt; 
	int numberSpikes;
	bool refractory;
	double clock;
	cqueue buffer; 
	
};

#endif
