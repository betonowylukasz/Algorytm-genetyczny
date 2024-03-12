#include "CKnapsackProblem.h"
#include<iostream>
#include<fstream>
using namespace std;

CKnapsackProblem::CKnapsackProblem()
{
    b_is_loaded=false;
    i_amount=0;
    d_capacity=0;
}

int CKnapsackProblem::iLoadInstance(string s_file_name)
{
    fstream fFile;
    double dReaded;
    if (b_is_loaded) return(ERR_INSTANCE_ALREADY_LOADED);
    fFile.open(s_file_name, ios::in);
    if (!fFile.is_open()) return (ERR_NOT_OPEN);
    fFile >> d_capacity;
    if (fFile.eof()) return (ERR_INCOMPLETE_DATA);
    if (fFile.fail()) return (ERR_INCORRECT_TYPE);
    if (d_capacity<=0) return (ERR_NEGATIVE_NUMBER);

    fFile >> dReaded;
    if (fFile.eof()) return (ERR_INCOMPLETE_DATA);
    v_value.clear();
    v_size.clear();

    while(!fFile.eof() || !fFile.fail())
    {
        if (fFile.fail()) return (ERR_INCORRECT_TYPE);
        if (dReaded <= 0) return (ERR_NEGATIVE_NUMBER);
        v_value.push_back(dReaded);
        fFile >> dReaded;
        if (fFile.eof() && fFile.fail()) return (ERR_INCOMPLETE_DATA);

        if (fFile.fail())return (ERR_INCORRECT_TYPE);
        if (dReaded <= 0) return (ERR_NEGATIVE_NUMBER);
        v_size.push_back(dReaded);
        fFile >> dReaded;
    }
    fFile.close();
    b_is_loaded=true;
    i_amount=v_value.size();
    return (ERR_OK);
}

double CKnapsackProblem::dCalculateValue(vector<int> v_genotype)
{
    double dValue=0;
    for(int i=0;i<v_genotype.size();i++)
    {
        if(v_genotype[i]==1) dValue+=v_value[i];
    }
    return dValue;
}

int CKnapsackProblem::getAmount()
{
    return i_amount;
}

double CKnapsackProblem::getCapacity()
{
    return d_capacity;
}

vector<double> CKnapsackProblem::getValue()
{
    return v_value;
}

vector<double> CKnapsackProblem::getSize()
{
    return v_size;
}

bool CKnapsackProblem::isLoaded()
{
    return b_is_loaded;
}