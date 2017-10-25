/*
 * Audrey Bender
 */
#include <iostream> 
#include "neurone.hpp"
#include "gtest/gtest.h" 

TEST (NeuronTest, MembranePotential) {
	Neurone neurone; 
	neurone.setCurrentExt( 1.0); 
	
	//Membrane potential after one update 
	neurone.update(1); 
	EXPECT_EQ( 20.0*(1.0 - std::exp(-0.1/20.0) ), neurone.getPotential() ); 
}

TEST (NeuroneTest, spikeTime) {
	Neurone neurone;
	neurone.setCurrentExt( 1.01 ); 
	
	//First spike time is at 925 ms
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
/*
TEST (TwoNeurons, SpikeReception) {
	Neurone N1; 
	Neurone N2;
	N1.setCurrentExt(1.01); 
	
	N1.update(925); //N1 spike 
	N2.update(940); //After delay
	long double potential =  N2.getPotential()*1000;
	EXPECT_GT( potential , 0.0 );  
} */

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS(); 
}
