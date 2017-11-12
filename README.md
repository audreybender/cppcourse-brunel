
Presentation of the program : 

	This program creates neurons that are connected with each others like in human brain. This simulation is based of Brunel's cortex model. Each neuron has a membrane potential that evolves in time.
Each neuron is connected with 1250 other neurons. 1000 of them are excitatory and so will increase its membrane potential, 250 are inhibitory and will in contrary decrease its potential. Furthermore, the neuron has a probability to be connected with outside it means to be excited by an exterior source. 
This simulation is divided in two, first it simulates two connected neurons and then a network of 12500 neurons. 
It's possible to know the time in ms at which a neuron is spiking by looking to “dataNeurone” or “dataNetwork” files.

Compilation of the program : 

	To compile the program you need to write “./Neurone” in the terminal from build directory (cppcourse-brunel/src/build). 
You can then simulate two neurons that interact with each other and also add a external current at your desired time. You will then simulate 12500 neurons as long as you wish. 
Have a look to “dataNeurone” and “dataNetwork” files for your results !
It's also possible to change the constant for example g and rate in “constant.hpp” (cppcourse-brunel/src) to get the four different plots of Brunel. 

Tools : 

	In the directory “cppcourse-brunel/src”, you will find an “index.html” file  that will link to a doxygen documentation of the project. 

Compilation of tests : 

	You can find different tests in “testNeurone.cpp” that test the two neurons compilation but also the network simulation. 
From build directory, write “./testNeurone” in the terminal to launch the tests. 

Visualisation : 

	The visualization of the network spikes is possible on jupyter website. Browse the “dataNetwork” result file (cppcourse-brunel/build), choose python 3 and add text from “diagram.gdf” (cppcourse-brunel/src/build). You should get two plots.
