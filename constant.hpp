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
static unsigned long const refTime(1);          ///< Reference Time 
static unsigned long const delay(15);          ///< Delay between sending and receiving spike
static double const J(0.1);                     ///< Amplitude of spike (should match V)
static int const bufferSize( delay / h + 1);    ///< The size of the buffer (for futur spike)
static unsigned long const delayStep = delay/h ;///< Step of delay ( delay/h)
//static unsigned long const C1 = exp(-h/tao);    ///< Constant 1
//static unsigned long const C2 = R*(1.0 -C1);    ///< Constant 2



#endif
