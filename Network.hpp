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
#include "gtest/gtest.h" 


using namespace std; 

typedef vector<vector<size_t>> Targets; 
typedef vector<vector<double>> Spikes; 

/**
 * @class Network 
 */

class Network {
	
	public : 
	
	/**
	 * @brief Constructeur
	 */
	Network();
	/**
	 * @brief Destructeur
	 */
	~Network();
	
	/**
	 * @brief Update the membrane potential of all neuron in the network
	 * 
	 * Manage exchange of potential between a spiking neuron and its targets,
	 * also refractory time. In brief the set the potential according to time.
	 * 
	 * @param tstop               <<<<<<<<
	 * = the lenght of the simulation
	 * 
	*/
	void update(size_t tstop, size_t clock); 
	/**
	 * @brief Starts the simulation of a network and stores datas
	 * 
	 * Store the time of each spike 
	 * and the IDnumber of the neuron that had spiked
	 * in a "DataNetwork" file 
	 * 
	 */
	void display();
	
	private : 
	
	Targets targets;              ///< Matrice of connections, each neurone(ID) has Cexcit(for the first Nexcit) or Cinhib(for the last Ninhib) targets neurones(number between 0 and Ntot) 
	Spikes spikesBuffer;          ///< Matrice of futur receiving potentials from connected neurons that had spiked 
	vector<double> potentials;    ///< Vector of actual potential of each neuron
	vector<int> numberSpikes;     ///< Number of time the neuron had spiked
	vector<size_t> timeSpikes;    ///< The last time the neuron had spiked
	vector<double> iExt;          ///< Vector of external current that is given to a specific neuron
	FRIEND_TEST(NetworkTest, numberSpikes);
	FRIEND_TEST(NetworkTest, connectionNumber);
	
};

#endif 
