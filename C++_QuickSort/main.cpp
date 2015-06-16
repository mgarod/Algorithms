//
//  main.cpp
//  quicksort
//
//  Created by Michael Garod on 6/8/15.
//  Copyright (c) 2015 MG. All rights reserved.
//

#include <iostream>
#include "randomIntArray.h"

int main() {

    randomIntArray myrandomarray(100);
    myrandomarray.printArray();
    
    cout << endl << endl;
    
    myrandomarray.quicksort();
    myrandomarray.printArray();
    
    return 0;
}
