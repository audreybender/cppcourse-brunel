/*
 * Audrey Bender
 */
#include <iostream> 
#include "neurone.hpp"
#include "gtest/gtest.h" 
#include "Network.hpp"


TEST (NeuronTest, MembranePotential) {
	Neurone neurone; 
	neurone.setCurrentExt( 1.0); 
	
	//Membrane potential after 1 sec 
	neurone.update(1); 
	EXPECT_EQ( 20.0*(1.0 - std::exp(-0.1/20.0) ), neurone.getPotential() ); 
}

TEST (NeuroneTest, spikeTime) {
	Neurone neurone;
	neurone.setCurrentExt( 1.01 ); 
	
	//First spike time is at 92.5 ms
	neurone.update(924); 
	EXPECT_EQ(0, neurone.getNumberSpikes() ); 
	neurone.update(1); 
	EXPECT_EQ(1, neurone.getNumberSpikes() ); 
	//Membrane potential should be at 0.0 because of refratory time
	EXPECT_EQ( 0.0, neurone.getPotential() ); 
	
	//Second spike time is at 1851 ms (925*2 + 1ms refractory time) 
	neurone.update(924);  //At 1850ms (1850-925-1 = 924)
	EXPECT_EQ(1, neurone.getNumberSpikes() ); 
	neurone.update(1);
	EXPECT_EQ(2, neurone.getNumberSpikes() ); 
	//Membrane potential should be at 0.0 because of refratory time
	EXPECT_EQ( 0.0, neurone.getPotential() ); 
	
}

TEST (NeuroneTest, positiveInput) {
	Neurone neuron;
	
	neuron.setCurrentExt(0.0); //Poentential should tend to 0
	neuron.update(1000);
	EXPECT_GT(0.1, neuron.getPotential() );
	
	
	neuron.setCurrentExt( 1.0); //Too low to spike 
	
	//First check after 1 update if the potential corresponds to equation
	neuron.update(1); 
	EXPECT_EQ(20*(1-std::exp(-0.1/20.0)), neuron.getPotential() );
	
	//The potential will not reach 20mV so the neuron won't spike 
	neuron.update(5000); 
	EXPECT_GT((1E3), (20-neuron.getPotential()) ); //Difference should be positiv near 0
	EXPECT_EQ(0, neuron.getNumberSpikes() );
	
}

TEST (NeuroneTest, negativeInput) {
	Neurone neuron;
	
	neuron.setCurrentExt( -1.0 ); //Too low to spike 
	
	//First check after 1 update if the potential corresponds to equation
	neuron.update(1); 
	EXPECT_EQ(-20*(1-std::exp(-0.1/20.0)), neuron.getPotential() );
	
	//The potential will not reach 20mV so the neuron won't spike 
	neuron.update(5000); 
	EXPECT_LT((-1E5), (-20-neuron.getPotential()) ); //Difference should be negativ near 0
	EXPECT_EQ(0, neuron.getNumberSpikes() );
	
}



TEST (TwoNeurons, SpikeReception) {
	Neurone N1; 
	Neurone N2;
	N1.setCurrentExt(1.01); 
	N2.setCurrentExt(1.009); //Would spike alone at 94.5
	
	
	N2.update(925);
	if( N1.update(925)){  //N1 spike 
	 N2.receive(940, Je);
	}
	N2.update(17); //After delay (94.2)
	EXPECT_EQ(1, N2.getNumberSpikes() ); 
	double potential =  N2.getPotential();
	EXPECT_EQ( potential , 0.0 );  //Refractory time
} 

TEST(NetworkTest, connectionNumber) {
	Network brain; 
	int connectionNumber(0); 
	for( auto line : brain.targets) {
		for ( auto target : line) {
			if ( target == 12001 ) { //Neuron number 12001 (same for the other)
				++connectionNumber;
			}
		}
	}
	EXPECT_EQ( (Cexcit+Cinhib) , connectionNumber );
}

TEST(NetworkTest, numberSpikes) {
	Network brain; 
	brain.update(10000, 0);
	cerr << brain.numberSpikes[44]<<endl;
	EXPECT_GT(40  , brain.numberSpikes[44] );  //should be around 38-39 per ms
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS(); 
}
