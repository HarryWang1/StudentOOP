//
//  main.cpp
//  MemLeak
//
//  Created by Hanyi Wang on 6/5/19.
//  Copyright © 2019 Hanyi Wang. All rights reserved.
//

#include <iostream>
struct Thing{
    int* iarr;
    Thing(int n){
        iarr = new int[n];
    }
};
const int OUTER = 10000000;
const int INNER = 100000;

int main() {
    for(int i = 0; i < OUTER; ++i){
        Thing** things = new Thing*[INNER];
        for(int j = 0; j<INNER; ++j){
            things[j] = new Thing(INNER);
            delete things[j];
        }
        delete[] things;
    }
}
