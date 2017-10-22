#ifndef NEURONE_HPP
#define NEURONE_HPP

#include <iostream>
#include <cmath>
#include <array>
#include "constant.hpp"

using namespace std; 
	

class Neurone {
	public : 

	//Constructeur
	Neurone( double membranePotential=0.0, unsigned long timeSpikes=0,
			double currentExt=0.0, unsigned long numberSpikes=0,
			 bool refractory=false, unsigned long clock= 0, 
			 double refStep =( refTime / h)) ;
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
	
	// Update the membrane Potential   
	bool update(unsigned long time); 
	//If the neurone1 spikes the neurone link to it will receive a new 
	//Membrane Potential J at his time + Delay so potential is put 
	//In its buffer at clock + delay 
	void receive(unsigned long clockDelay, double j);
	
	
	private : 
	double membranePotential; 
	unsigned long timeSpikes;
	double currentExt; 
	int numberSpikes;
	bool refractory;
	unsigned long clock;
	double refStep; 
	array<double, bufferSize> buffer; 
	
};

#endif
