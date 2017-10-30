/* 
 * Audrey Bender 
 */
#ifndef CONSTANT_HPP
#define CONSTANT_HPP

#include <cmath>


//Numerical constants
static double const teta(20);                    ///< Theorical membrane potential of spike
static double const Vthr ( 0.01 );
static double const Vext (0.02);                ///< Spikes/ connection in ms                ???
static double const C ( 1);                     ///< Capacity
static double const tao(20);                    ///< Time constant ( = R*C )  
static double const R(20 );	                    ///< Membrane resistance = tao / C 
static double const h(0.1);                     ///< Time step 
static unsigned long const refTime(1);          ///< Refractory Time 
static unsigned long const delay(15);           ///< Delay between sending and receiving spike
static double const Je(0.1);                     ///< Amplitude of spike from excitatory neurones
static double const Ji( -5 * Je);                     ///< Amplitude of spike from inhibitory neurones
static int const bufferSize( delay / h + 1);    ///< The size of the buffer (for futur spike)
static unsigned long const delayStep = delay/h ;///< Step of delay ( delay/h)
static int const E(0.1);                        ///< Constant of proportionality 
static int const Ne(10000);                     ///< Number of excitatory neurones
static int const Ce(Ne*E);                      ///< Number of connections of excitatory neurones 
static int const Ni(2500);                      ///< Number of inhibitory neurones
static int const Ci(Ni*E);                      ///< Number of connections of inhibitory neurones 
static int const Cext(Ce);                      ///< Number of connections with outside
static int const Next(100);                  ///< Number of neurones connected with outside 
static double const Random( Vext * Cext * h * Je ); ///< Random chance for a neuron to be connected with outside (0.2 mV/ steps) 


#endif
