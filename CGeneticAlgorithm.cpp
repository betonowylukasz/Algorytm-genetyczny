#include "CGeneticAlgorithm.h"
#include "CIndividual.h"
#include<iostream>
using namespace std;

CGeneticAlgorithm::CGeneticAlgorithm(CKnapsackProblem &c_problem)
{
    this->c_problem=c_problem;
}

int CGeneticAlgorithm::iExecute(int iPopSize, double dCrossProb, double dMutProb, int iIterations)
{
    if (!c_problem.isLoaded()) return(ERR_PROBLEM_NOT_LOADED);
    if(iPopSize<=0 || dCrossProb<0 || dCrossProb>1 || dMutProb<0 || dMutProb>1 || iIterations<=0) return(ERR_WRONG_PARAMETER);
    v_best_genotype.clear();
    double dBestFitness=0;
    vector<CIndividual> vPopulation=vCreatePopulation(iPopSize);
    vector<double> vFitness;
    for(int i=0;i<iIterations;i++)
    {
        vFitness=vEvaluatePopulation(vPopulation);
        for(int j=0;j<iPopSize;j++)
        {
            if (vFitness[j] > dBestFitness)
            {
                v_best_genotype=vPopulation[j].vGetGenotype();
                dBestFitness=vFitness[j];
            }
        }
        vector<CIndividual> vNewPopulation, vChildren;
        for(int j=0;j<iPopSize;j+=2)
        {
            vChildren=vPopulation[cChooseFromRandomPair(vFitness)].vCrossIndividuals(
                    vPopulation[cChooseFromRandomPair(vFitness)], dCrossProb);
            vNewPopulation.push_back(vChildren[0]);
            vNewPopulation.push_back(vChildren[1]);
        }
        if (iPopSize%2==1) iPopSize++;
        for (int j=0;j<iPopSize;j++)
        {
            vNewPopulation[j].vMutation(dMutProb);
            //vNewPopulation[j].vMutationWithMask(vNewPopulation[rand()%iPopSize], dMutProb);
        }
        vPopulation=vNewPopulation;
    }
    return(ERR_OK);
}

vector<CIndividual> CGeneticAlgorithm::vCreatePopulation(int iPopSize)
{
    vector<CIndividual> vPopulation;
    for (int i = 0; i < iPopSize; i++)
    {
        vector<int> vGenotype;
        for (int j = 0; j < c_problem.getAmount(); j++)
        {
            vGenotype.push_back(rand() % 2);
        }
        vPopulation.emplace_back(vGenotype);
    }
    return vPopulation;
}

vector<double> CGeneticAlgorithm::vEvaluatePopulation(vector<CIndividual> &vPopulation)
{
    vector<double> vFitness;
    for (int i = 0; i < vPopulation.size(); i++)
    {
        vFitness.push_back(vPopulation[i].dCalculateFitness(c_problem));
    }
    return vFitness;
}

int CGeneticAlgorithm::cChooseFromRandomPair(vector<double> &vFitness)
{
    int iRandom1=rand()%vFitness.size();
    int iRandom2=rand()%vFitness.size();
    if (vFitness[iRandom1]>vFitness[iRandom2]) return iRandom1;
    return iRandom2;
}

vector<int> CGeneticAlgorithm::vGetBestGenotype()
{
    return v_best_genotype;
}