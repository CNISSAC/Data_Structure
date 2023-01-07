#include <iostream>
#include <cassert>
using namespace std;

class Vector {
private:
    int *arr = nullptr;
    int size = 0;
    int capacity {};
    
    void expand_capacity(){
        capacity =2*size;
        int *arr_cpy = new int[capacity];

        for(int i {0}; i<size; i++){
            arr_cpy[i]=arr[i];
        }
        swap(arr,arr_cpy);
        delete [] arr_cpy;
    }

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
    
    
    void push_back(int val){
        
        if(size==capacity)
            expand_capacity();
        size++;
        arr[size-1]=val;
    }
    
   void insert(int idx, int value) {
		assert(0 <= idx && idx < size);

		// we can't add any more
		if (size == capacity)
			expand_capacity();

		// Shift all the data to right first
		for (int p = size - 1; p >= idx; --p)
			arr[p + 1] = arr[p];

		arr[idx] = value;
		++size;
	} 
    
    void right_rotate(int times=1){
        for(int j {}; j<(times%size); j++){
            int container {};
            container = arr[size-1];
            for(int i {size-1}; i>0; i--){
                arr[i] = arr[i-1];
            }
            arr[0] = container;
        }
        
    }
    
    void left_rotate(int times=1){
        for(int j {}; j<(times%size); j++){
            int container {};
            container = arr[0];
            for(int i {0}; i<size-1;i++){
                arr[i]=arr[i+1];
            }
            arr[size-1]=container;
        }
    }
    
    int pop(int idx){
        int *arr_cpy= new int[capacity];
        int pop_num = arr[idx];
        for(int i {}; i<size; i++){
            if(i<idx)
                arr_cpy[i]=arr[i];   
            else if(i>idx)
                arr_cpy[i-1] = arr[i];
          
        }
        swap(arr,arr_cpy);
        size--;
        delete [] arr_cpy;
        return pop_num;
    }
    
    int find_transposition(int value){
        int container {value};
        int idx {};
        for(int i {}; i<size; i++){
            if(arr[i]==container && i!=0){
                arr[i]=arr[i-1];
                arr[i-1]=container;
                idx = i-1;
                break;
            }else if(arr[i]==container && i==0){
                idx = 0;
                break;
            }else
                idx = -1;
        }
        return idx;
    }
};




int main() {

//
//	Vector v(10);
//	for (int i = 0; i < 10; ++i)
//		v.set(i, i);
//        
//    v.push_back(3);
//	v.print();
//    
//	cout<<v.find(5)<<" "<<v.find(55);	// 5 -1
    
    int n = 5;
	Vector v(n);
	for (int i = 0; i < n; ++i)
		v.set(i, i);

	v.print();			// 0 1 2 3 4
	v.right_rotate(5 * 1000);
	v.print();			// 0 1 2 3 4
    v.right_rotate(2);
	v.print();			// 3 4 0 1 2
    v.left_rotate();
	v.print();			// 4 0 1 2 3
    int val = v.pop(2);
	cout << val << "\n";	// 1
	v.print();			// 4 0 2 3
    
    cout<<v.find_transposition(3)<<"\n";	// 2
    v.print();			// 4 0 3 2

	return 0;
}
