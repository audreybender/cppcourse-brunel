#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Network.hpp"
//#include "neurone.hpp"   //FIRST TESTS


using namespace std; 
const string nomFichier( "dataNeurone" );

int main() {
	
	
//FIRST TESTS creation of 1 or 2 neurones 
/*
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
	
	
	cout << "External current ? " << endl;
	cin >> straightCurrent;
	cout << "Time interval in ms from ? " << endl; 
	cin >> a;
	cout << " until ? " << endl; 
	cin >> b;
	cout << " End time ? " << endl;
	cin >> tStop;
	
	cout << "Temps :  " << '\t' << "Potentiel :" << endl;
	
		
	for( int t= 0; t < tStop ; ++t ) { //General clock
		
		//Set current depending external current to the first neurone 
		if ( (a < t) and (t < b) ) {
			N1.setCurrentExt(straightCurrent); 
		
		}else {
			N1.setCurrentExt( 0.0 );   
		}	
	
	bool spike1 = N1.update(1); 
	bool spike2 = N2.update(1); 
	//Write the result in the terminal 
	    cout << t << '\t' << N2.getPotential() << endl;
		if(spike1) { 
			cout << "Spike1 at t=" << t << endl;
			N2.receive(t+delay, h); 
		}
		if(spike2) {
			cout << "Spike2 at t=" << t << endl; 
		}

		
		//Write in a file result 
	    fichier << t*h << '\t' << N2.getPotential() << endl;
		if(spike1) { 
			fichier << "Spike1 okkk at t=" << t*h << endl;
			N2.receive(t+delay, h); 
		}
		if(spike2) {
			fichier << " Spike2 at t=" << t*h << endl; 
		}
		
	}
		
		//Write number of spikes
	    fichier << endl; 
		fichier << "Number of spikes N2 : " << endl;
		fichier << N2.getNumberSpikes() << endl;
		fichier.close();
		
		}
	 cout << " Look at the new file dataNeurone ! " << endl;
*/

//FINAL TESTS reation of a network


   Network brain1; 
   brain1.update(1);
   cout << brain1.neurones[1][12] << endl;
   cout << brain1.brain[0]->getPotential() << endl; 

	return 0;
}
