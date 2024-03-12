#include <iostream>
#include "CKnapsackProblem.h"
#include "CGeneticAlgorithm.h"
using namespace std;

int main() {

    srand(time(NULL));
    CKnapsackProblem problem;
    cout << problem.iLoadInstance("test.txt") << endl;
    CGeneticAlgorithm AG=CGeneticAlgorithm(problem);
    cout << AG.iExecute(4, 0.6, 0.1, 50) << endl;
    for(int i=0;i<AG.vGetBestGenotype().size();i++)
    {
        cout << AG.vGetBestGenotype()[i];
    }
    cout << endl << problem.dCalculateValue(AG.vGetBestGenotype()) << endl;
    return 0;
}
