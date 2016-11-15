//
//  main.cpp
//  mergesort
//
//  Created by Michael Garod on 7/23/15.
//  Copyright (c) 2015 MG. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;


void printArray(int a[], int a_size)
{
    for(int i=0; i < a_size; i++)
    {
        cout << setw(5) << right << a[i];
        
        if((i+1) % 10 == 0)
        {
            cout << endl;
        }
    }
}

void fillArray(int a[], int a_size)
{
    srand(static_cast<unsigned int>(time(NULL)));
    
    for(int i=0; i < a_size; i++)
    {
        a[i] = rand() % 1000;
    }
}

void mergehelp(int a[], int l, int m, int r)
{
    const int n1 = m - l + 1;
    const int n2 = r - m;
    //printf("n1 is %d and n2 is %d\n", n1, n2);
    
    
    int left[n1], right[n2];
    
    for (int i=0; i < n1; i++)
    {
        left[i] = a[l+i];
    }
    
    for (int j=0; j < n2; j++)
    {
        right[j] = a[m+j+1];
    }
    
    int i=0,j=0,k=l;
    
    while ((i < n1) && (j < n2))
    {
        if (left[i] < right[j])
        {
            a[k] = left[i];
            i++;
        }
        else
        {
            a[k] = right[j];
            j++;
        }
        k++;
    }
    
    while (i < n1)
    {
        a[k] = left[i];
        i++;
        k++;
    }
    
    while (j < n2)
    {
        a[k] = right[j];
        j++;
        k++;
    }
}

void mergesort(int a[], int l, int r)
{
    if (l < r)
    {
        int m = (l+r)/2;
        mergesort(a, l, m);
        mergesort(a, m+1, r);
        mergehelp(a, l, m, r);
    }
}


int main()
{
    const int ARRAY_SIZE = 100;
    int my_array[ARRAY_SIZE];
    
    fillArray(my_array, ARRAY_SIZE);
    printf("before mergesort:\n");
    printArray(my_array, ARRAY_SIZE);
    mergesort(my_array, 0, ARRAY_SIZE-1);
    printf("after mergesort:\n");
    printArray(my_array, ARRAY_SIZE);
    
    return 0;
}
