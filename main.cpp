#include <iostream>
#include <fstream>
#include <string>
#include "neurone.cpp"


using namespace std; 
const string nomFichier( "dataNeurone" );

int main() {
	Neurone neurone;
	double timeStop; 
	double straightCurrent; 
	double a;
	double b;
	
	ofstream fichier(nomFichier);
	if(fichier.fail()) {
		cerr << "Erreur : le fichier ne peut pas s'ouvrir ! " << endl;
	}else{
	
	
	cout << "External current ? ( between 0-400 pA) : " << endl;
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
	
	while( simTime < timeStop ) {
		if ( (a < simTime) and (simTime < b) ) {
		neurone.setRefractory( false);
		neurone.setCurrentExt(straightCurrent); 
		}else {
			neurone.setCurrentExt( 0.0 ); 
		}
		if ( simTime >= b) {
			neurone.setRefractory( true );
		}
		neurone.update(); 
		
		fichier.width(10);
		fichier << simTime << left << neurone.getPotential() << endl;
		
		simTime += h; 	
		}
		fichier << neurone.getNumberSpikes() << endl;
		fichier.close(); 
	}
	cout << " Look at the new file dataNeurone ! " << endl;
	
	return 0;
}
