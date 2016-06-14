#include "Net.h"
#include<vector>
#include <cassert>
#include<iostream>
#include <cmath>
#include "common.h"
#include "Neuron.h"


using namespace std;
Net::Net(const vector <unsigned> &topology)
{
    unsigned numLayers = topology.size();

    for(unsigned layerNum = 0; layerNum < numLayers; ++layerNum){
        m_layers.push_back(Layer());
        unsigned numOutputs = layerNum == topology.size() - 1 ? 0 : topology[layerNum + 1];
        for(unsigned neuronNum = 0; neuronNum <= topology[layerNum]; ++neuronNum){
            cout<< "made Neuron"<< endl;
            m_layers.back().push_back(Neuron(numOutputs));


        }
    }
}

void Net::feedForward(const std::vector <double> &inputsVals){
    assert(inputsVals.size() == m_layers[0].size() -1);
    // assign the input values into input nurions
    for(unsigned i = 0; i < inputsVals.size(); ++i){
        m_layers[0][i].setOutputVal(inputsVals[i]);
    }
    // forward propagate
    for(unsigned layerNum = 1; layerNum < m_layers.size(); ++layerNum){
        Layer &prevLayer = m_layers[layerNum -1];
        for(unsigned n = 0; n < m_layers[layerNum].size() - 1; ++n){
                m_layers[layerNum][n].feedForward(prevLayer, n);
        }
    }
};
void Net::backProp(const vector <double> &targetVals){
    //calc the net error
    Layer &outputLayer = m_layers.back();
    m_error = 0.0;
    for(unsigned n = 0; n < outputLayer.size() -1; n++){
        double delta = targetVals[n] - outputLayer[n].getOutputVals();
        m_error += delta * delta;
    }
    m_error /= outputLayer.size() - 1;
    m_error = sqrt(m_error);
    m_recentAvrageError = (m_recentAverageError * m_recentAverageSmoothingFactor + m_error)/ (m_recentAverageSmoothingFactor + 1.0);
    for(unsigned n = 0; n < outputLayer.size() -1; n++){
        outputLayer[n].calculateOutputGradients(targetVals[n]);
    }
    for(unsigned layerNum =  m_layers.size() - 2; layerNum > 0; n--){
        Layer &hiddenLayer = m_layers[layerNum];
        Layer &nextLayer = m_layers[layerNum + 1];
        for (unsigned n = 0; n < hiddenLayer.size(); n++){
            m_layers[layerNum][n].feedForward(prevLayer);
        }
    }
};
