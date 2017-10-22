#ifndef CONSTANT_HPP
#define CONSTANT_HPP

#include <cmath>



static double const Vth = 20;
static double const C ( 1);
static double const tao(20);
static double const R(20 );		// tao / C 
static double const h(0.1);
static unsigned long const refTime(1);
static unsigned long const delay(1.5);
static double const J(0.1); //Amplitude should match V
static int const bufferSize( delay / h + 1); 
static unsigned long const delayStep = delay/h ;
static unsigned long const c1 = exp( -h/ tao); 
static unsigned long c2 = R*(1.0 -c1); 



#endif
