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
static double const C(1);                        ///< Capacity
static double const tao(20);                     ///< Time constant ( = R*C )  
static double const R(20);	                     ///< Membrane resistance = tao / C 
static double const h(0.1);                      ///< Time step 
static unsigned long const refTime(1);           ///< Refractory Time ms
static unsigned long const delay(1.5);            ///< Delay between sending and receiving spike
static double const Je(0.1);                     ///< Amplitude of spike from excitatory neurones
static double const Ji(-0.5);                    ///< Amplitude of spike from inhibitory neurones
static unsigned long const delayStep = 15 ;      ///< Step of delay (delay/h)
static int const bufferSize( delayStep + 1);      ///< The size of the buffer (for futur spike)
static int const Nexcit(10000);                  ///< Number of excitatory neurones
static int const Cexcit(1000);                   ///< Number of connections of excitatory neurones (Nexcit*0.1)
static int const Ninhib(2500);                   ///< Number of inhibitory neurones
static int const Cinhib(250);                    ///< Number of connections of inhibitory neurones (Ninhib*0.1)
static int const Cext(Cexcit);                   ///< Number of connections with outside
static int const Next(100);                      ///< Number of neurones connected with outside 
static double const Random(2);                   ///< Random chance for a neuron to be connected with outside (Vext * Cext * h * Je 2 mV/ steps) 
static int const Ntot(Nexcit+Ninhib);            ///< Total number of neurones 

#endif
