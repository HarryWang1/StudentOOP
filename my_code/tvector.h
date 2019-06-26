
const int DEF_CAPACITY = 10;
const int CAPACITY_MULT = 2;
using namespace std;

template <typename T>
class MyVec {
public:
   
    MyVec(){
        sz = 0;
        capacity = DEF_CAPACITY;
        data = new int[DEF_CAPACITY];
    }
    
    MyVec(int sz, T val=T()) {
        capacity = sz;
        data = new T[capacity];
        for(int i = 0; i < sz; ++i){
            data[i] = val;
        }
    }
    
    // copy control:
    MyVec(const MyVec& v2){
        copy(v2);
    }
    ~MyVec() { delete [] data; }
    
    MyVec& operator=(const MyVec& v2){
        copy(v2);
        return *this;
    }
    
    void push_back(T val){
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

    int size() const { return sz; }
    
    T operator[](int i) const {
        return data[i];
    }
    T& operator[](int i){
        return data[i];
    }
   
    
private:
    void copy(const MyVec& v2) {
        sz = v2.sz;
        capacity = v2.capacity;
        data = new T[capacity];
        for (int i = 0; i < sz; i++) {
            data[i] = v2.data[i];
        }
    }
    
    T* data;
    int sz;
    int capacity;
};

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
