#include <iostream>
#include <vector>
#include "Neuron.h"
#include "common.h"
#include "Net.h"

// nural-net-tutorial
using namespace std;


int main()
{
    vector <unsigned> topology;
    topology.push_back(3);
    topology.push_back(2);
    topology.push_back(1);
    Net myNet(topology);
    std::vector <double> inputVals;
//    myNet.feedForward(inputVals);
    vector <double> targetVals;
  //  myNet.backProp(targetVals);
    vector <double> resultVals;
    //myNet.getResults(resultVals);
    return 0;
}
