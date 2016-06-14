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
        void calcOutputGradients(double targetVal);
        void calcHiddenGradients(const Layer &nextLayer);
        void updateInputWeights(Layer &prevLayer);
    protected:
    private:
        static double randomWeight(void);
        static double transferFunction(double x);
        static double transferFunctionDerivative(double x);
        double m_outputVal;
        unsigned m_myIndex;
        vector<Connection> m_outputWeights;
        double m_gradient;
        double sumDOW(const Layer &nextLayer)const;
        static double eta;
        static double alpha;
};

#endif // NEURON_H
