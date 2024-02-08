#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>

void swap(int *first, int *second) {
    int temp = *first;
    *first = *second;
    *second = temp;
}

void fisher_yates(int array[], int length, int(*fcn)()) {
    for (int i = length - 1; i > 0; i--) {
        int rnd_location = fcn() % (i + 1);
        swap(&array[i], &array[rnd_location]);
    }
}

int random_function() {
   std::random_device rd;  
    std::mt19937 eng(rd()); 
    
    int min = 0;
    int max = 100;

    std::uniform_int_distribution<> distr(min, max);
    return distr(eng);
}

bool non_neg_prefix_sum(int ary[], int length) {
    bool negative_found = true;
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += ary[i];
        if (sum < 0) {
            negative_found = false; 
            break;
        }
    }
    return negative_found; 
}

bool non_pos_prefix_sum(int ary[], int length) {
    bool positive_found = true;
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += ary[i];
        if (sum > 0) {
            positive_found = false;
            break;
        }
    }
    return positive_found;
}

void print_array(int array[], int length) {
    for (int i = 0; i < length; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}


