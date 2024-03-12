#include "CIndividual.h"
#include<iostream>
using namespace std;

CIndividual::CIndividual(vector<int> &v_genotype)
{
    this->v_genotype=v_genotype;
}

double CIndividual::dCalculateFitness(CKnapsackProblem &cProblem)
{
    double dValue=0, dSize=0;
    for(int i=0;i<cProblem.getAmount();i++)
    {
        if(v_genotype[i]==1)
        {
            dValue += cProblem.getValue()[i];
            dSize += cProblem.getSize()[i];
        }
    }
    if (dSize>cProblem.getCapacity()) return 0;
    return dValue;
}

vector<CIndividual> CIndividual::vCrossIndividuals(CIndividual cParent, double dCrossProb)
{
    vector<CIndividual> v_children;
    if (((double)rand()/(double)RAND_MAX)>dCrossProb)
    {
        v_children.push_back(*this);
        v_children.push_back(cParent);
        return v_children;
    }
    int iCrossingPoint=rand()%(v_genotype.size()-1);
    vector<int> vNewGenotype1, vNewGenotype2;
    for (int i=0;i<=iCrossingPoint;i++)
    {
        vNewGenotype1.push_back(v_genotype[i]);
        vNewGenotype2.push_back(cParent.vGetGenotype()[i]);
    }
    for (int i=iCrossingPoint+1;i<v_genotype.size();i++)
    {
        vNewGenotype1.push_back(cParent.vGetGenotype()[i]);
        vNewGenotype2.push_back(v_genotype[i]);
    }
    v_children.emplace_back(vNewGenotype1);
    v_children.emplace_back(vNewGenotype2);
    return v_children;
}

void CIndividual::vMutation(double dMutProb)
{
    for (int i=0;i<v_genotype.size();i++)
    {
        if (((double)rand()/(double)RAND_MAX)<=dMutProb)
        {
            if (v_genotype[i]==1) v_genotype[i]=0;
            else v_genotype[i]=1;
        }
    }
}

void CIndividual::vMutationWithMask(CIndividual &cIndividual, double dMutProb)
{
    vector<int> vMask=cIndividual.vGetGenotype();
    for (int i=0;i<v_genotype.size();i++)
    {
        if (v_genotype[i]!=vMask[i])
        {
            if (((double) rand() / (double) RAND_MAX) <= dMutProb)
            {
                if (v_genotype[i] == 1) v_genotype[i] = 0;
                else v_genotype[i] = 1;
            }
        }
    }
}

vector<int> CIndividual::vGetGenotype()
{
    return v_genotype;
}

void CIndividual::vPrint()
{
    for (int i=0;i<v_genotype.size();i++)
    {
        cout << v_genotype[i];
    }
    cout << endl;
}