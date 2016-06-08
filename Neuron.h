#ifndef NEURON_H
#define NEURON_H
#include <vector>

using namespace std;

struct Connection{
    double weight;
    double deltaWeight;
};

class Neuron
{
    public:
        Neuron(unsigned numOutputs);
    protected:
    private:
        static double randomWeight(void);
        double m_outputValue;
        vector<Connection> m_outputWeights;


};

#endif // NEURON_H
