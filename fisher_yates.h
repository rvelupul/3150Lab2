#ifndef _FISHER_YATES_H_
#define _FISHER_YATES_H_

void print_array(int ary[], int len);

int random_function();

int swap(int * first, int * second);
void fisher_yates(int array[], const int length, int (*fcn)());
bool non_neg_prefix_sum(int ary[], int length);
bool non_pos_prefix_sum(int ary[], int length);
void print_array(int array[], int length);

#endif


