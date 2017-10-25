/** 
 * @file neurone.h 
 * @brief function prototypes for the neurone
 * 
 * @author Audrey Bender
 */

#ifndef NEURONE_HPP
#define NEURONE_HPP

#include <iostream>
#include <cmath>
#include <array>
#include "constant.hpp"

using namespace std; 

/**
 * @class Neurone
 */

class Neurone {
	public : 

	/**
	 * @brief Constructeur
	 * 
	 * @param membranePotential 
	 * @param timeSpikes occurence 
	 * @param currentExt 
	 * @param numberSpikes 
	 * @param clock
	 * @param refStep 
	 */
	Neurone( long double membranePotential=0.0, unsigned long timeSpikes=0,
			double currentExt=0.0, unsigned long numberSpikes=0,
	        unsigned long clock= 0, double refStep =( refTime / h)) ;
	/**
	 * @brief Destructeur
	 */
	~Neurone();
	//Getter 
	/**
	 * @brief Get the membrane potential 
	 * @return membrane potential 
	 */ 
	long double getPotential() const; 
	/**
	 * @brief Get number of spikes
	 * @return number of spikes 
	 */ 
	double getNumberSpikes() const; 
	/**
	 * @brief Get time of spikes occurence
	 * @return the time when spike occurs 
	 */ 
	double getTimeSpikes() const;
	/**
	 * @brief Get extrenal current 
	 * @return external current 
	 */ 
	double getCurrentExt() const; 
	/**
	 * @brief Get clock of the neurone 
	 * @return the clock of the neurone
	 */ 
	double getClock() const; 
	
	//Setter
	/**
	 * @brief Set the membrane potential
	 * @param p 
	 * new membrane potential (double)
	 */
	void setPotential( long double p);
	/**
	 * @brief Set the external current 
	 * @param c 
	 * new external current (double)
	 */
	void setCurrentExt( double c);
	/**
	 * @brief Set the number of spikes 
	 * @param n 
	 * number of spikes (int)
	 */
	void setNumberSpikes( int n);
	
	//Méthodes 
	
	/**  
	 * @brief Update the membrane Potential 
	 * @param time
	 * @return booleen true if spike occured 
	 */
	bool update(unsigned long time); 
	/**
	 * @brief Add a futur spike in the buffer
	 * If the neurone1 spikes the neurone link to it will receive a new 
	 * Membrane Potential J at his time + Delay so potential is put 
	 * In its buffer at clock + delay 
	 * 
	 * @param clockDelay
	 * the clock+delay of the neuron that had spiked (unsigned long)
	 * @param j 
	 * J the amplitude of the futur spike (double) 
	*/
	void receive(unsigned long clockDelay, long double j);
	
	
	private : 
	long double membranePotential; ///< Membrane potential 
	unsigned long timeSpikes; ///< Time of spikes occurence
	double currentExt;        ///< External current 
	int numberSpikes;         ///< Number of spikes
	unsigned long clock;      ///< Individual clock of the neurone
	double refStep;           ///< Reference step 
	array<double, bufferSize> buffer; ///< Buffer to insert futur spikes
	
};

#endif
