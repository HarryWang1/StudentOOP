const int DEF_CAPACITY = 10;

class MyVec{
public:
	MyVec();
	MyVec(const MyVec& v2);
	~MyVec();
	MyVec& operator = (const MyVec& v2);
	
	void push_back(int val);
	int size() const{return sz;}
	int operator[] (int i) const {return data[i];}
	int& operator[] (int i){return data[i];}


private:
	int sz;
	int capacity;
	int* data;
};

void print_vector(MyVec v);
bool operator==(MyVec& v1, MyVec& v2);
