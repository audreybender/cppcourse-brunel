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
#include <array>
#include "constant.hpp"
#include "neurone.hpp"

using namespace std; 

typedef array<array<Neurone, 12500>, 12500> Neurones;   

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
	Network( Neurones network);
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
	void update(); 
	
	/**
	 * @brief Receive external current 
	 * 
	 * Will call the receive function of neurones 
	 * randomly chosen to be connected with the outside 
	 * 
	*/
	void receive(unsigned long clockDelay, long double j);
	
	
	private : 
	
	Neurones network; ///< Matrice of 12500 neurones
	
	
};

#endif 
