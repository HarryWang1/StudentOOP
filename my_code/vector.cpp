#include <iostream>
#include "vector.h"

using namespace std;

void vector:: vector(){
	sz = 0;
	capacity = DEF_CAPACITY;
	data = new int[DEF_CAPACITY];

}


void vector:: push_back(int val){
	data[sz++] = val;
}

void print_vector(vector v){
	for(int i = 0; i < v.size(); i++){
		cout<<v.data[i] <<" ";
	}
	cout << endl;
}

