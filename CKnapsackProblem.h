#ifndef LISTA6_CKNAPSACKPROBLEM_H
#define LISTA6_CKNAPSACKPROBLEM_H
#include<iostream>
#include <vector>

using namespace std;

#define ERR_INSTANCE_ALREADY_LOADED 1
#define ERR_NOT_OPEN 2
#define ERR_INCOMPLETE_DATA 3
#define ERR_INCORRECT_TYPE 4
#define ERR_NEGATIVE_NUMBER 5
#define ERR_OK 0

class CKnapsackProblem {
private:
    bool b_is_loaded;
    int i_amount;
    double d_capacity;
    vector<double> v_value;
    vector<double> v_size;

public:
    CKnapsackProblem();

    int iLoadInstance(string s_file_name);
    double dCalculateValue(vector<int> v_genotype);
    vector<double> getValue();
    vector<double> getSize();
    int getAmount();
    double getCapacity();
    bool isLoaded();

};

#endif //LISTA6_CKNAPSACKPROBLEM_H
