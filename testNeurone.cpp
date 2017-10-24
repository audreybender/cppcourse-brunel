/*
 * Audrey Bender
 */
#include <iostream> 
#include "neurone.hpp"
#include "gtest/gtest.h" 

TEST (NeuronTest, MembranePotential) {
	Neurone neurone; 
	neurone.setCurrentExt( 1.0); 
	
	//First after one update 
	neurone.update(1); 
	EXPECT_EQ( 20.0*(1.0 - std::exp(-0.1/20.0) ), neurone.getPotential() ); 
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS(); 
}
