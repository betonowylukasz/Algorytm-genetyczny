#ifndef LISTA6_CINDIVIDUAL_H
#define LISTA6_CINDIVIDUAL_H
#include "CKnapsackProblem.h"
#include<iostream>
#include<vector>
using namespace std;

class CIndividual {
private:
    vector<int> v_genotype;

public:
    CIndividual(vector<int> &v_genotype);

    double dCalculateFitness(CKnapsackProblem &cProblem);
    vector<int> vGetGenotype();
    vector<CIndividual> vCrossIndividuals(CIndividual cParent, double dCrossProb);
    void vMutation(double dMutProb);
    void vMutationWithMask(CIndividual &cIndividual, double dMutProb);
    void vPrint();
};


#endif //LISTA6_CINDIVIDUAL_H
