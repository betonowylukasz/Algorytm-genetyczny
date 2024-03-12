#ifndef LISTA6_CGENETICALGORITHM_H
#define LISTA6_CGENETICALGORITHM_H
#include<iostream>
#include "CKnapsackProblem.h"
#include "CIndividual.h"
using namespace std;

#define ERR_PROBLEM_NOT_LOADED 1
#define ERR_WRONG_PARAMETER 2

class CGeneticAlgorithm {

private:
    CKnapsackProblem c_problem;
    vector<int> v_best_genotype;

    vector<CIndividual> vCreatePopulation(int iPopSize);
    vector<double> vEvaluatePopulation(vector<CIndividual> &vPopulation);
    int cChooseFromRandomPair(vector<double> &vFitness);
public:
    CGeneticAlgorithm(CKnapsackProblem &c_problem);

    int iExecute(int iPopSize, double dCrossProb, double dMutProb, int iIterations);
    vector<int> vGetBestGenotype();
};


#endif //LISTA6_CGENETICALGORITHM_H
