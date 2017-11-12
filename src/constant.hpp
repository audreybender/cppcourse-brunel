/** 
 * @file constant.hpp
 * @brief constants file
 * 
 * @author Audrey Bender
 */
#ifndef CONSTANT_HPP
#define CONSTANT_HPP

#include <cmath>


//Numerical constants
static double const Vteta(20);                   ///< Theorical membrane potential of spike
static double const Vthr(0.01);                  ///< Threshold potential
static int const ratio(2);                       ///< Ratio Vthr/Vext
static double const Vext(ratio*Vthr);            ///< Spikes per connection in ms
static double const C(1);                        ///< Capacity
static double const tao(20);                     ///< Time constant ( = R*C )  
static double const R(20);	                     ///< Membrane resistance = tao / C 
static double const h(0.1);                      ///< Time step 
static unsigned long const refTime(2);           ///< Refractory Time ms
static unsigned long const delay(1.5);           ///< Delay between sending and receiving spike (ms)
static double const Je(0.1);                     ///< Amplitude of spike from excitatory neurones
static int const g(5); 				   		   	 ///< Constante of proportionnality
static double const Ji(-Je*g);                   ///< Amplitude of spike from inhibitory neurones
static unsigned long const delayStep = 15 ;      ///< Step of delay (delay/h)
static int const bufferSize( delayStep + 1);     ///< The size of the buffer (for futur spike)
static int const Nexcit(10000);                  ///< Number of excitatory neurones
static int const Cexcit(Nexcit*0.1);             ///< Number of connections of excitatory neurones (Nexcit*0.1)
static int const Ninhib(2500);                   ///< Number of inhibitory neurones
static int const Cinhib(Ninhib*0.1);             ///< Number of connections of inhibitory neurones (Ninhib*0.1)
static int const Cext(Cexcit);                   ///< Number of connections with outside
static double const Random(Vext*Cext*Je);        ///< Random chance for a neuron to be connected with outside (Vext * Cext * Je = 2 mV/ steps) 
static int const Ntot(Nexcit+Ninhib);            ///< Total number of neurones 

#endif
