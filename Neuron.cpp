#include <iostream>
#include <cstdlib>
#include "Neuron.h"
using namespace std;
Neuron::Neuron(unsigned numOutputs)
{
   cout<< "I am a Neuron"<< endl;
    for(unsigned c = 0; c < numOutputs; ++c){
        Connection setConnection = Connection() ;
        setConnection.weight = randomWeight();
        m_outputWeights.push_back(setConnection);
    }
};

double Neuron::randomWeight(void){
    double randomW = rand() / double (RAND_MAX);
    return randomW;
};
