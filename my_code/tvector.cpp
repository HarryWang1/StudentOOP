#include <iostream>
#include "tvector.h"

using namespace std;


template <typename T>
MyVec<T>:: MyVec(){
    sz = 0;
    capacity = DEF_CAPACITY;
    data = new int[DEF_CAPACITY];
}


template <typename T>
void MyVec<T>:: push_back(T val){
    if (sz == capacity){
        // get new array of capacity*2 and copy over old data, delete old array
        capacity *= 2;
        int* new_data = new int[capacity];
        // coping old data
        for (int i = 0; i < size(); i++){
            new_data[i] = data[i];
        }
        // delete old array
        delete[] data;
        
        // set ptr to new array
        data = new_data;
        
    }
    data[sz++] = val;
}

template <typename T>

MyVec<T>& MyVec<T>:: operator = (const MyVec& v2){
    copy(v2);
    return *this;
}

template <typename T>
void print_vector(const MyVec<T>& v){
    for(int i = 0; i < v.size(); ++i){
        cout << v[i] << endl;
    }
}


template <typename T>

bool operator==(MyVec<T>& v1, MyVec<T>& v2){
    if(v1.size()!=v2.size()) return false;
    else{
        for(int i = 0; i < v1.size();++i){
            if(v1[i]!= v2[i]) return false;
        }
    }
    return true;
    
}