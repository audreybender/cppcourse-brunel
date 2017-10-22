#include <iostream> 
#include "neurone.hpp"
#include "gtest/gtest.h" 

TEST (NeuronTest, MembranePotential) {
	Neurone neurone; 
	neurone.setCurrentExt( 1.0); 
	
	//First update test
	neurone.update(1); 
	EXPECT_EQ( 20.0*(1.0 -std::exp(-0.1/20.0) ), neurone.getPotential() ); 

