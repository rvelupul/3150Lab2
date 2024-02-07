#include <iostream>
#include <cstdlib>

#include "fisher_yates.h"

using namespace std;

int main() {

    srand(time(NULL)); 

    int n;
    std::cout << "Enter the number of open-parens: ";
    std::cin >> n;

    int arrayValues[2*n];
    for (int i = 0; i < n; i++) {
        arrayValues[i] = 1;
    }


    for (int i = 0; i < n; i++) {
        arrayValues[i+n] = -1;
    }


    int BalancedCount = 0;

    int BalancedCount1 = 0;
    cout << "Enter number of runs: "<< endl;
    int runs;
	cin >> runs;
    

    for (int i = 0; i < runs; i++) {
        fisher_yates(arrayValues, 2*n, random_function);
        if (non_neg_prefix_sum(arrayValues, 2*n)) {
            BalancedCount++;
        }
    }
    
    for (int i = 0; i < runs; i++) {
        fisher_yates(arrayValues, 2*n, random_function);
        if (non_pos_prefix_sum(arrayValues, 2*n)) {
            BalancedCount1++;
        }
    }


    double proportion = (double)BalancedCount / runs;
    std::cout << "Proportion of well-balanced sequences: " << proportion << std::endl;
    double proportion1 = (double)BalancedCount1 / runs;
    std::cout << "Proportion of well-balanced sequences: " << proportion1 << std::endl;

    return 0;
}

