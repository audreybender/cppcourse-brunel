/* 
 * Audrey Bender 
 */
#ifndef CONSTANT_HPP
#define CONSTANT_HPP

#include <cmath>


//Numerical constants
static double const Vth(20);                    ///< Theorical membrane potential of spike
static double const C ( 1);                     ///< Capacity
static double const tao(20);                    ///< Time constant ( = R*C )  
static double const R(20 );	                    ///< Membrane resistance = tao / C 
static double const h(0.1);                     ///< Time step 
static unsigned long const refTime(1);          ///< Refractory Time 
static unsigned long const delay(15);           ///< Delay between sending and receiving spike
static double const Je(0.1);                     ///< Amplitude of spike from excitatory neurones
//Mais si inhibiteurs pourquoi amplitude ???
static double const Ji(0.5);                     ///< Amplitude of spike from inhibitory neurones
static int const bufferSize( delay / h + 1);    ///< The size of the buffer (for futur spike)
static unsigned long const delayStep = delay/h ;///< Step of delay ( delay/h)
static int const e(0.1);                        ///< Constant of proportionality 
static int const Ne(10000);                     ///< Number of excitatory neurones
static int const Ce(Ne*e);                      ///< Number of connections of excitatory neurones 
static int const Ni(2500);                      ///< Number of inhibitory neurones
static int const Ci(Ni*e);                      ///< Number of connections of inhibitory neurones 
static int const Cext(Ce);                      ///< Number of connections with outside
static int const Next(Cext/e);                  ///< Number of neurones connected with outside 


#endif
