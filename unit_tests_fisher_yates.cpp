#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "fisher_yates.h"

int arry_0[] = {};
int arry_1[] = {1,-1};

int first1 = -99;
int save_first1 = first1;
int second1 = 4;
int save_second1 = second1;

int i = swap(& first1, & second1);

int ran_function() {
    return rand();
}

int determ_value = 0;
int determ_function() {
    return determ_value++ % 10;
}

int constant_function() {
    return 2; 
}

int linear_function() {
    int value = 0;
    value = (value + 3) % 10; 
    return value;
}

TEST_CASE("Fisher_Yates") {

    SUBCASE("swap tests") {
        CHECK_EQ(save_first1, second1);
        CHECK_EQ(first1, save_second1);
    };
}


TEST_CASE("Fisher_Yates Shuffle") {
    SUBCASE("fisher_yates shuffle") {
        int test_array[] = {1, 2, 3, 4, 5}; 
        int original_array[] = {1, 2, 3, 4, 5}; 
        int length = sizeof(test_array) / sizeof(test_array[0]);

        fisher_yates(test_array, length, ran_function);

        bool all_elements_present = true;
        for(int i = 0; i < length; i++) {
            bool found = false;
            for(int j = 0; j < length; j++) {
                if(test_array[j] == original_array[i]) {
                    found = true;
                    break;
                }
            }
            if(!found) {
                all_elements_present = false;
                break;
            }
        }

        CHECK_EQ(length, sizeof(test_array) / sizeof(test_array[0])); 
        CHECK(all_elements_present); 

    }
}

TEST_CASE("Fisher_Yates Deterministic Shuffle") {
    SUBCASE("fisher_yates with deterministic function") {
        int determ_value = 0; 
        int test_array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 
        int original_array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 
        int length = sizeof(test_array) / sizeof(test_array[0]);

        fisher_yates(test_array, length, determ_function);

        REQUIRE(memcmp(test_array, original_array, sizeof(test_array)) != 0);

        bool every_element_present = true;
        for(int i = 0; i < length; i++) {
            bool found = false;
            for(int j = 0; j < length; j++) {
                if(test_array[j] == original_array[i]) {
                    found = true;
                    break;
                }
            }
            if(!found) {
                every_element_present = false;
                break;
            }
        }

        REQUIRE(every_element_present); 
    }
}

TEST_CASE("Fisher_Yates Non-Random Shuffle") {
    SUBCASE("fisher_yates with constant function") {
        int test_array[] = {1, 2, 3, 4, 5}; 
        int original_array[] = {1, 2, 3, 4, 5}; 
        int length = sizeof(test_array) / sizeof(test_array[0]);

        
        fisher_yates(test_array, length, constant_function);

        bool is_same_as_original = true;
        for(int i = 0; i < length; i++) {
            if(test_array[i] != original_array[i]) {
                is_same_as_original = false;
                break;
            }
        }

        CHECK_FALSE(is_same_as_original); 
    }
}

TEST_CASE("Fisher_Yates Linear Shuffle") {
    SUBCASE("fisher_yates with linear increment function") {
        int test_array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 
        int original_array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 
        int length = sizeof(test_array) / sizeof(test_array[0]);

        linear_function(); 
        linear_function(); 

        fisher_yates(test_array, length, linear_function);

        bool is_reverse_order = true;
        for(int i = 0; i < length; i++) {
            if(test_array[i] != original_array[length - 1 - i]) {
                is_reverse_order = false;
                break;
            }
        }

        WARN(!is_reverse_order); 
    }
}