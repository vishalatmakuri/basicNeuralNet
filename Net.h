#ifndef NET_H
#define NET_H
#include<vector>
#include "Neuron.h"
#include "common.h"
using namespace std;
class Net
{
    public:
        Net(const std::vector <unsigned> &topology);
        void feedForward(const std::vector <double> &inputsVals);
        void backProp(const std::vector <double> &targetVals);
        void getResults(std::vector <double> &resultVals) const;
    protected:
    private:
        vector <Layer> m_layers;
};

#endif // NET_H
