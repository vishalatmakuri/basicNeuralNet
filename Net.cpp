#include "Net.h"
#include<vector>
#include<iostream>
#include "Neuron.h"
#include "common.h"

using namespace std;
Net::Net(const vector <unsigned> &topology)
{
    unsigned numLayers = topology.size();

    for(unsigned layerNum = 0; layerNum < numLayers; ++layerNum){
        m_layers.push_back(Layer());
        for(unsigned neuronNum = 0; neuronNum <= topology[layerNum]; ++neuronNum){
            cout<< "made Neuron"<< endl;
            m_layers.back().push_back(Neuron());


        }
    }
}
