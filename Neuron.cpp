#include <iostream>
#include <cstdlib>
#include "Neuron.h"
#include <cmath>
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

void Neuron:: setOutputVal(double val){m_outputVal = val;};
double Neuron::getOutputVal(void) const{ return m_outputVal;};

void Neuron::feedForward(const Layer &prevLayer, unsigned myIndex){
    double sum = 0.0;

    for (unsigned n = 0; n < prevLayer.size(); n++){
       sum += prevLayer[n].getOutputVal() * prevLayer[n].m_outputWeights[m_myIndex].weight;
    }
    m_outputVal =  Neuron::transferFunction(sum);
};

double Neuron::transferFunction(double x){
    return tanh(x);
};

double Neuron::transferFunctionDerivative(double x){
    return 1.0 - x * x;
};
