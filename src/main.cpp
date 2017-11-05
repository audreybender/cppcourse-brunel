#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Network.hpp"
#include "neurone.hpp"


using namespace std; 
const string nomFichier( "dataNeurone" );

int main() {
	
	
//TESTS creation of 2 neurones 
  	Neurone N1;
	Neurone N2;
	double tStop; 
	double straightCurrent; 
	double a; //Beginning of straightCurrent for N1
	double b; // End of straightCurrent

	ofstream fichier(nomFichier);
	if(fichier.fail()) {
		cerr << "Erreur : le fichier ne peut pas s'ouvrir ! " << endl;
	}else{
	
	cout << "Simulation of two neurons : " << endl; 
	cout << "External current ? " << endl;
	cin >> straightCurrent;
	cout << "Time interval (ms) from ? " << endl; 
	cin >> a;
	cout << " until ? " << endl; 
	cin >> b;
	cout << " End time ? " << endl;
	cin >> tStop;
	
	fichier << "Temps (in STEPS) :  " << '\t' << "Potentiel N1 :";
	fichier << '\t'<< "Potentiel N2 :" << '\n';
	
	//Convertion in steps
	a = a/h;
	b=b/h;
	tStop=tStop /h;
		
	for( int t= 0; t < tStop ; ++t ) { //General clock
		
		//Set current depending external current to the first neurone 
		if ( (a < t) and (t < b) ) {
			N1.setCurrentExt(straightCurrent); 
		}else {
			N1.setCurrentExt( 0.0 );   
		}	
	
	bool spike1 = N1.update(1); 
	bool spike2 = N2.update(1); 

		//Write in a file result 
	    fichier<< '\t' << t << '\t' << '\t' << N1.getPotential();
	    fichier  << '\t'<< '\t' << N2.getPotential() << '\n';
		if(spike1) { 
			fichier << "Spike1 at t =" << t << '\n';
			N2.receive(t+delayStep, Je); //suppose an excitatory neuron
		}
		if(spike2) {
			fichier << " Spike2 at t =" << t << '\n'; 
		}
	  }
		
		//Write number of spikes
	    fichier << endl; 
		fichier << "Number of spikes N2 : " << N2.getNumberSpikes() << '\n';
		fichier.close();
	 }
	
	 cout << " Look at the new file dataNeurone ! " << '\n';	
//////////////////

//TESTS of a network
   Network brain1; 
   brain1.display();
    
	return 0;
}
