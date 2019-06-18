const int DEF_CAPACITY = 10;

class vector{
public:
	vector();
	vector(const vector& v2);
	~vector();
	vector& operator = (const vector& v2);
	
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