/** 
 * @file Network.hpp
 * @brief function prototypes for the network
 * 
 * @author Audrey Bender
 */

#ifndef NETWORK_HPP
#define NETWORK_HPP

#include <iostream>
#include <cmath>
#include <vector>
#include "constant.hpp"
#include "neurone.hpp"

using namespace std; 

typedef vector<vector<int>> NeuronesConnection;   
typedef vector<Neurone*> Brain;

/**
 * @class Network 
 */

class Network {
	
	public : 
	
	/**
	 * @brief Constructeur
	 * 
	 * @param Neurones 
	 */
	Network();
	/**
	 * @brief Destructeur
	 */
	~Network();
	
	/**
	 * @brief Update the membrane potential of all neuron in the network
	 * 
	 * If a neuron is connected to another neuron spiking 
	 * its membrane potential will change 
	 * an inhibitory neuron will inhibe the neurone MP = 0.0
	 * an excitatory neuron will increase MP 
	 * 
	*/
	void update(unsigned long time); 
	
	
	
	NeuronesConnection neurones; ///< Matrice of 12500 neurones
	Brain brain; 
	
	
	
};

#endif 
