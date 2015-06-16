//
//  randomIntArray.h
//  quicksort
//
//  Created by Michael Garod on 6/8/15.
//  Copyright (c) 2015 MG. All rights reserved.
//

#ifndef quicksort_randomIntArray_h
#define quicksort_randomIntArray_h

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;


class randomIntArray
{
public:
    randomIntArray();
    randomIntArray(int);
    void printArray();
    void quicksort();
    void insertionsort();
    
private:
    int* my_array;
    int  my_array_size;
    
    void swap(int&, int&);
    void quickhelp(int, int);
    
};

#endif
