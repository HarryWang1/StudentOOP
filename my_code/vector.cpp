#include <iostream>
#include "vector.h"

using namespace std;

void vector:: vector(){
	sz = 0;
	capacity = DEF_CAPACITY;
	data = new int[DEF_CAPACITY];

}


void vector:: push_back(int val){
	if (sz == capacity){
		// get new array of capacity*2 and copy over old data, delete old array
		capacity *= 2;
		new_data = new int[capacity];
		// coping old data
		for (int i = 0; i < size(); i++){
			new_data[i] = data[i];
		}
		// delete old array
		// set ptr to new array
		delete[] data;
		data = new_data;
		
	}
	data[sz++] = val;
}

void print_vector(vector v){
	for(int i = 0; i < v.size(); i++){
		cout<<v.data[i] <<" ";
	}
	cout << endl;
}

