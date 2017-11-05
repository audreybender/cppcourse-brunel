/* 
 * Audrey Bender
 */

#include "Network.hpp" 
#include <random>
#include <cassert>
#include <fstream>



using namespace std; 

const string nomFichier( "dataNetwork" );

//Constructeur 
Network::Network() 
{
	//Initialization of the connections matrice
	//Random targets connections
	random_device rd; 
	mt19937 gen(rd()); 
	uniform_int_distribution<> excit(0, (Nexcit-1));
	uniform_int_distribution<> inhib(Nexcit, (Ntot-1));
	
	Targets N(Ntot, vector<size_t>(0));
	targets = N;
	for( size_t target(0); target < Ntot; ++target){ 
	//Ce connections with excitory neurons 
		for(size_t i(0); i < Cexcit; ++i) {
			int transmitter( excit(gen) ); 
			targets[transmitter].push_back(target);
		}
		
	//Ci connections with inhibitory neurones
		for( size_t i(0); i < Cinhib; ++i){
			int transmitter( inhib(gen) ); 
			targets[transmitter].push_back(target);
		}
	}
	
	//Initialization of the vectors 
	// SpikesBuffer, potentials, numberSpikes, timeSpikes
	// iExt, sizes should correspond to the numbers of neurones
    Spikes S(Ntot, vector<double> (bufferSize, 0.0));
    spikesBuffer = S;
	potentials =vector<double> (Ntot, 0.0);
	numberSpikes= vector<int> (Ntot, 0); 
	timeSpikes = vector<size_t> (Ntot, 0.0);; 
	iExt = vector<double> (Ntot , 0.0);
		
}

//Destructeur 
Network::~Network()
{}

//Methodes

void Network::update(size_t tstop, size_t clock) {

   size_t t = 0;   
  while( t < tstop) {
   for( size_t neuId(0); neuId < Ntot; ++neuId ) {
	 const size_t tArrival = clock % (delayStep+1); //Convertion for the buffer
     //if neuron spikes
	 if ( potentials[neuId] > Vteta) {            
			++numberSpikes[neuId]; 
			timeSpikes[neuId] = clock;   
			potentials[neuId] = 0.0;
		
		//if the neuron is excitatory, give a Je potential to its 
		//targets neurons (fill the spikesBuffer ) 
		if(neuId < Cexcit ){                
		 for( size_t target= 0; target < targets[neuId].size(); ++target ) {
			const size_t tSpike = ( clock+delayStep)%(delayStep+1);
			const size_t targetId = targets[neuId][target];
			spikesBuffer[targetId][tSpike] += Je ; 
	      }
	    }	
	    
	    //if inhibitory neurons give a Ji potential 
	    if ( Cexcit <= neuId and neuId <= (Cexcit+Cinhib) ) {
		 for( size_t target= 0; target < targets[neuId].size(); ++target ) {
			const size_t tSpike = ( clock+delayStep)%(delayStep+1);
			const size_t targetId = targets[neuId][target];
			spikesBuffer[targetId][tSpike] += Ji ;    
	    }
	  }  
	}
	
	assert( tArrival < bufferSize );
	//If the neuron is refractory
	if( (timeSpikes[neuId] > 0) and ( (clock)-timeSpikes[neuId] < refTime/h) ){
		potentials[neuId] = 0.0; 
   	}else{
		//TimeSpike had been saved, reinitialisation
		timeSpikes[neuId] = 0.0;
		
		//Set the new potential : exponential + external( = 0.0) potential
		//+spike from other neurons(buffer) and random external connection
		static random_device rd; 
		static mt19937 gen(rd());
		static poisson_distribution<> connSpikes(Random); 
		
		potentials[neuId] = exp(-h/tao) * potentials[neuId] +  R*(1-exp(-h/tao)) * iExt[neuId] 
			              + spikesBuffer[neuId][tArrival] + Je * connSpikes(gen); 
		}
		//Clear spike buffer at tArrival
		spikesBuffer[neuId][tArrival] = 0.0; 
	 }
	++clock;
	++t;
  }
}

void Network::display() {
	
    ofstream fichier(nomFichier);
	if(fichier.fail()) {
		cerr << "Erreur : le fichier ne peut pas s'ouvrir ! " << endl;
	}else{
		
	double tStop;	
	
	cout << "Simulation of 12500 neurons. " << endl;
	cout << "Time interval in ms ? " << endl; 
	cin >> tStop;
	
	
   //Convertion in step
   tStop = tStop/h;
   
   for( size_t t = 0; t < tStop ; ++t ) {
	   
	    update(1, t);
	   
	   
	    for( size_t i(0); i < Ntot; ++i) {	
		
		  if(timeSpikes[i] > 0.0){ 
			//Writing time ( in steps ) of spikes of each neurons
		    fichier <<'\t' << timeSpikes[i]*h << '\t' << i << '\n';
		   
		    if ( i== 461 ){
				cerr << " Number : " << numberSpikes[i] << endl;
				cerr << " TimeSpikes : " << timeSpikes[i]*h << endl;
				
			}
		  }
		}
	//	cerr << potentials[461] << endl;
	  }
	  fichier.close();
	}
  cout << " Look at the new file dataNetwork ! " << endl;

}

