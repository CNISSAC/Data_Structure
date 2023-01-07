#include <iostream>
#include <cassert>
using namespace std;

class Vector {
private:
    int *arr = nullptr;
    int size = 0;
    int capacity {};
    

public:
	Vector(int size) :
			size(size) {
		if (size < 0)
			size = 1;
        capacity=size*2;
		arr = new int[capacity] { };
	}

	~Vector() {
		delete[] arr;
		arr = nullptr;
	}

	int get_size() {
		return size;
	}

	int get(int idx) {
		assert(0 <= idx && idx < size);
		return arr[idx];
	}

	void set(int idx, int val) {
		assert(0 <= idx && idx < size);
		arr[idx] = val;
	}

	void print() {
		for (int i = 0; i < size; ++i)
			cout << arr[i] << " ";
		cout << "\n";
	}

	int find(int value) {
		for (int i = 0; i < size; ++i)
			if (arr[i] == value)
				return i;
		return -1;	// -1 for NOT found
	}
    
    
    
//    void push_back(int val){
//        int *arr_cpy = nullptr;
//        arr_cpy = new int[size] {};
//        for(int i {0};i<size;++i)
//            arr_cpy[i] = arr[i];
//        
//        size++;
//        delete[] arr;
//        arr = new int[size] {};
//
//        for(int i {0};i<size-1;++i)
//            arr[i] = arr_cpy[i];
//        arr[size-1] = val;
//        
//        delete[] arr_cpy;
//        
//        // we could use swap(arr,arr_cpy) eventhough they are different in size
//        // and then delete [] arr_cpy
//        
//    }
    void expand_capacity(){
        capacity =2*size;
        int *arr_cpy = new int[capacity];

        for(int i {0}; i<size; i++){
            arr_cpy[i]=arr[i];
        }
        swap(arr,arr_cpy);
        delete [] arr_cpy;
    }
    
    void push_back(int val){
        
        if(size==capacity)
            expand_capacity();
        size++;
        arr[size-1]=val;
    }
};

int main() {


	Vector v(10);
	for (int i = 0; i < 10; ++i)
		v.set(i, i);
        
    v.push_back(3);
//    v.push_back(3);
//    v.push_back(3);
//    v.push_back(3);
	v.print();
    
	cout<<v.find(5)<<" "<<v.find(55);	// 5 -1

	return 0;
}
