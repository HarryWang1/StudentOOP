#include <iostream>
#include "vector.h"

using namespace std;

MyVec:: MyVec(){
	sz = 0;
	capacity = DEF_CAPACITY;
	data = new int[DEF_CAPACITY];

}

MyVec:: MyVec(int sz, int val):sz(sz){
	capacity = sz;
	data = new int[capacity];
	for(int i = 0; i < sz; ++i){
		data[i] = val;
	}

}

void MyVec:: push_back(int val){
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


MyVec& MyVec:: operator = (const MyVec& v2){
	if (this != &v2){
		delete[] data;
		// Remember to copy over the capacity and size
		capacity = v2.capacity;
		sz = v2.size();
		data = new int[capacity];
		// copy over existing data
		for(int i = 0; i < size(); ++i){
			data[i] = v2.data[i];
		}
	}
	return *this;
}

MyVec:: MyVec(const MyVec& v2){
	capacity = v2.capacity;
	sz = v2.size();
	data = new int[capacity];
	// copy over existing data
	for(int i = 0; i < size(); ++i){
		data[i] = v2.data[i];
	}
}

MyVec::~MyVec(){delete[] data;}

MyVec::Iterator MyVec::begin() const {
    return Iterator(data);
}

MyVec::Iterator MyVec::end() const {
    return Iterator(data+sz);
}

	
void print_vector(const MyVec& v) {
    for (int i : v) cout << i << " ";
    cout << endl;
}



bool operator==(MyVec& v1, MyVec& v2){
	if(v1.size()!=v2.size()) return false;
	else{
		for(int i = 0; i < v1.size();++i){
			if(v1[i]!= v2[i]) return false;
		}
	}
	return true;

}









