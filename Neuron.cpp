#include <iostream>
#include "Neuron.h"
using namespace std;
Neuron::Neuron(unsigned numOutputs)
{
   cout<< "I am a Neuron"<< endl;
    for(unsigned c = 0; c < numOutputs; ++c){
        Connection setConnection = Connection() ;
        setConnection
        m_outputWeights.push_back(Connection());
    }
}
