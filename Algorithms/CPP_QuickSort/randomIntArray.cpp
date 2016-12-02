//
//  randomIntArray.cpp
//  quicksort
//
//  Created by Michael Garod on 6/8/15.
//  Copyright (c) 2015 MG. All rights reserved.
//

#include "randomIntArray.h"

// Default constructor makes an array of 100 numbers
randomIntArray::randomIntArray()
{
    srand(static_cast<unsigned int>(time(NULL)));
    
    my_array = new int[100];
    
    for(int i=0; i < 100; i++)
    {
        my_array[i] = rand() % 1000;
    }
    
    my_array_size = 100;
}

// Argument constructor makes an array of input_size
randomIntArray::randomIntArray(int input_size)
{
    srand(static_cast<unsigned int>(time(NULL)));
    
    my_array = new int[input_size];
    
    for(int i=0; i < input_size; i++)
    {
        my_array[i] = rand() % 1000;
    }
    
    my_array_size = input_size;
}

void randomIntArray::printArray()
{
    for(int i=0; i < my_array_size; i++)
    {
        cout << setw(5) << right << my_array[i];
        
        if((i+1) % 10 == 0)
        {
            cout << endl;
        }
    }
}

void randomIntArray::quicksort()
{
    quickhelp(0, my_array_size-1);
}

///////////////////////////////////////////////////

void randomIntArray::quickhelp(int left, int right)
{
    
    // select pivot
    int i = left, j = right, temp;
    int midpoint = (left+right)/2;
    int pivot = my_array[midpoint];

    while (i <= j)
    {
        while (my_array[i] < pivot)
        {
            i++;
        }
        while (my_array[j] > pivot)
        {
            j--;
        }
        
        if (i <= j)
        {
            temp = my_array[i];
            my_array[i] = my_array[j];
            my_array[j] = temp;
            i++;
            j--;
        }
    }
    if (left < j)
        quickhelp(left, j);
    if (i < right)
        quickhelp(i, right);
}