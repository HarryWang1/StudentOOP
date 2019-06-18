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
		delete[] data;

		// set ptr to new array
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

vector& vector:: operator = (const vector& v2){
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

vector:: vector(const vector& v2){
	capacity = v2.capacity;
	sz = v2.size();
	data = new int[capacity];
	// copy over existing data
	for(int i = 0; i < size(); ++i){
		data[i] = v2.data[i];
	}
}

vector::~vector(){delete[] data;}











