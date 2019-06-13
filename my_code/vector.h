const int DEF_CAPACITY = 10;

class vector{
public:
	vector();
	void push_back(int val);
	int size() const{return sz;}
	int operator[] (int i) const {return data[i];}
	int& operator[] (int i) const {return data[i];}


private:
	int sz;
	int capacity;
	int* data;
}

void print_vector(vector v);