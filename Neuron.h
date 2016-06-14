#ifndef NEURON_H
#define NEURON_H
#include <vector>
#include "common.h"
using namespace std;

struct Connection{
    double weight;
    double deltaWeight;
};

class Neuron
{
    public:
        Neuron(unsigned numOutputs);
        void setOutputVal(double val);
        double getOutputVal(void) const;
        void feedForward(const Layer &prevLayer, unsigned myIndex);
    protected:
    private:
        static double randomWeight(void);
        static double transferFunction(double x);
        static double transferFunctionDerivative(double x);
        double m_outputVal;
        unsigned m_myIndex;
        vector<Connection> m_outputWeights;
};

#endif // NEURON_H
