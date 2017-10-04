#ifndef NEURONE_HPP
#define NEURONE_HPP

#include <iostream>


using namespace std; 

constexpr double Vth(20);
constexpr double C ( 1);
constexpr double tao(20);
constexpr double R( tao / C);

class Neurone {
	public : 
	
	//Constructeur
	Neurone( double membranePotential=0.0, double timeSpikes=0.0,
			double currentExt=0.0, int numberSpikes=0,
			 bool refractory=false );
	//Destructeur
	~Neurone();
	//Getter
	double getPotential() const; 
	double getNumberSpikes() const; 
	double getTimeSpikes() const;
	double getCurrentExt() const; 
	bool getRefractory() const;
	//Setter
	void setPotential( double p);
	void setCurrentExt( double c);
	void setRefractory( bool r);
	//Méthodes 
	void update(); 
	double calculPotential(); 
	
	
	private : 
	double membranePotential; 
	double timeSpikes;
	double currentExt; 
	int numberSpikes;
	bool refractory;
	
};

#endif
