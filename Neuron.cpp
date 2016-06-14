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

void Neuron::calcOutputGradients(double targetVal){
    double delta = targetVal - m_outputVal;
    m_gradient = delta * Neuron::transferFunction(m_outputVal);
};
 void Neuron::calcHiddenGradients(const Layer &nextLayer){
    double dow = sumDOW(nextLayer);
    m_gradient = dow * Neuron::transferFunction(m_outputVal);
 };
double Neuron::sumDOW(const Layer &nextLayer) const {
    double sum = 0.0;
    for(unsigned n = 0; n < nextLayer.size() - 1; n++ ){
        sum += m_outputWeights[n].weight * nextLayer[n].m_gradient;
    }
    return sum;
};
void Neuron::updateInputWeights(Layer &prevLayer){
    for(unsigned n = 0; n < prevLayer.size(); n++){
        Neuron &neuron = prevLayer[n];
        double oldDeltaWeight = neuron.m_outputWeights[m_myIndex].deltaWeight;
        double newDeltaWeight =  eta * neuron.getOutputVal() * m_gradient + alpha * oldDeltaWeight;
        neuron.m_outputWeights[m_myIndex].deltaWeight = newDeltaWeight;
        neuron.m_outputWeights[m_myIndex].weight += newDeltaWeight;

    }
};
double Neuron::eta = 0.15;
double Neuron::alpha = 0.5;
