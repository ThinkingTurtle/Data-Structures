/*
 * main.cpp
 *
 * Includes the main() function for the sorting project. 
 *
 * This code is included in the build target "run-main"
*/

#include <iostream>
#include <cstddef>
#include <vector>
#include <chrono>
#include <cmath>
#include "sorter.h"

using namespace std;
double time_n_sort(int n, int k) {
    vector<int> v;
    // get starting clock value
    for (unsigned i = 0; i < n; i++) {
        v.push_back(100000*(rand()/RAND_MAX));
    }
    auto start_time = chrono::system_clock::now();
    // do the n pushes
    sorter(v,k);
    // get ending clock value
    auto stop_time = chrono::system_clock::now();
    // compute elapsed time in seconds
    chrono::duration<double> elapsed = stop_time - start_time;
    return elapsed.count();
}
int main() {
    // You can use this main() to run your own analysis or testing code.
    cout << "If you are seeing this, you have successfully run main!" << endl;
    cout << "k: " << 2 << endl;
    for (int i = 100000; i<600000 ; i+=100000){
        cout << time_n_sort(i,2) << endl;
    }
    cout << "k: " << 3 << endl;
    for (int i = 100000; i<600000 ; i+=100000){
        cout << time_n_sort(i,3) << endl;
    }
    cout << "k: " << 5 << endl;
    for (int i = 100000; i<600000 ; i+=100000){
        cout << time_n_sort(i,5) << endl;
    }
    cout << "k: " << 10 << endl;
    for (int i = 100000; i<600000 ; i+=100000){
        cout << time_n_sort(i,10) << endl;
    }
    cout << "k: " << 50 << endl;
    for (int i = 100000; i<600000 ; i+=100000){
        cout << time_n_sort(i,50) << endl;
    }
    cout << "k: " << 100 << endl;
    for (int i = 100000; i<600000 ; i+=100000){
        cout << time_n_sort(i,100) << endl;
    }
    cout << "k: " << 200 << endl;
    for (int i = 100000; i<600000 ; i+=100000){
        cout << time_n_sort(i,200) << endl;
    } 
    return 0;
}


