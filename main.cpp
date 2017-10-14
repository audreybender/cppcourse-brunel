#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "constant.hpp"
#include "neurone.cpp"


using namespace std; 
const string nomFichier( "dataNeurone" );

int main() {
	
	Neurone N1;
	Neurone N2;
	double timeStop; 
	double straightCurrent; 
	double a;
	double b;
	vector<Neurone> Neurones;
	Neurones = { N1, N2 };
	
	ofstream fichier(nomFichier);
	if(fichier.fail()) {
		cerr << "Erreur : le fichier ne peut pas s'ouvrir ! " << endl;
	}else{
	
	
	cout << "External current ? " << endl;
	cin >> straightCurrent;
	cout << "Time interval in ms from ? " << endl; 
	cin >> a;
	cout << " until ? " << endl; 
	cin >> b;
	cout << " End time ? " << endl;
	cin >> timeStop;
	
	fichier << "Temps :  " << left << "Potentiel :" << endl;
	
	double tStart(0.0);
	double simTime( tStart);
	
		
	while( simTime < timeStop ) { //General clock
		
		//Set current depending external current to the first neurone 
		if ( (a < simTime) and (simTime < b) ) {
		Neurones[0].setCurrentExt(straightCurrent); 
		
		}else {
			Neurones[0].setCurrentExt( 0.0 );    
		}	
	}
	
	//Connections
	for ( auto neurone : Neurones ) {
		while( neurone.getClock() < timeStop ) {
			bool spike ( false);
			spike = neurone.update(h);
			
			if (spike) {
				Neurones[1].receive( (neurone.getClock()+delay), J);  // Pour l'instant seulement une connection 
			}
		
		//Write in a file result 
		fichier.width(10);
		fichier << simTime << left << N2.getPotential() << endl;
		simTime += h; 	
		
		}
	
	}
		
		//Write number of spikes
		fichier << "Number of spikes N2 : " << endl;
		fichier << N2.getNumberSpikes() << endl;
		fichier.close(); 
		}
		cout << " Look at the new file dataNeurone ! " << endl;

	return 0;
}
