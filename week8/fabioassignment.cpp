/*Make a Linear Data Structure with pointers or array (your choice) and make sure it works and can accept many elements.

Then with the elements inserted into the Data Structure, make sure to perform Binary Search on the dataset. ( Make sure to sort beforehand!!)

The sorting can be done with the bubble sort algorithm or you can use another sorting algorithm. */

// ascending priority queue with array implementation 
// implementing queues with arrays 
#include <iostream>
#include <array>

#define MAX 100 // constant 

// DECLARATIONS 
template <typename T>
class Queue{
    private:
    // PROPERTIES
    std::array < T,MAX> items;// pointer to array
    int size; // number of elements in queue 
    int i;// index of the queueFront

    // alternative properties
    // int queueFront;
    // int queueEnd;

    public:
    // OPERATIONS 
    Queue():items(), size(0), i(0) {}; // constructor
    void enqueue(T item);
    T dequeue();
    void print();
    void sort();

    int binarySearch(T item, int i, int arrSize); // binary search the array, returns index of desired element

    // getter and setter functions
    int getSize();
    int getI();
};

// IMPLEMENTATIONS
template <typename T>
int Queue<T>::getSize(){
    return this->size;
}

template <typename T>
int Queue<T>::getI(){
    return this->i;
}

template <typename T>
void Queue<T>::enqueue(T item){
    this->items[this->size] = item;
    this->size++;
    
    if(this->size>1){
        this->sort();
    }

}

template <typename T>
T Queue<T>::dequeue(){
    this->size--;
    return this->items[this->i++];
}

template <typename T>
void Queue<T>::print(){
    std::cout << "SIZE OF QUEUE: " << this->size << std::endl;
    int idx = 0;
    for (int x = this->i; x < this->size; x++)
    {
        std::cout << idx++ << ": " << this->items[x] << std::endl;
    }
}

template <typename T>
void Queue<T>::sort(){
    T temp;
    // bubble sort 
    for(this->i; i<this->size; this->i++){
        for (int j = this->i+1; j <this->size; j++){
            if (this->items[this->i]>this->items[j]){
                //swap
                temp = this->items[this->i];
                this->items[this->i] = this->items[j];
                this->items[j] = temp;

            }
        }
    }
    this-> i = 0;
}

// TO DO: BINARY SEARCH ALGORITHM
template <typename T>
// (item, low,high)
int Queue<T>::binarySearch(T item, int low, int high){ // low =queueFront = 0, high = max size 
    int mid = (low+high)/2;
    // std::cout<<"mid"<<mid<<std::endl; //test
    // 1. BASE CASE 
    if(this->items[mid] == item){
        return mid;
    }

    // 2. LOGIC 
    // error handling: element not found 
    if(low >= high){
        return -1;
    }    
    
    // if mid is greater than item => left 
    if (this->items[mid]>item){
        // 3. RECURSIVE FUNCTION CALL
        binarySearch(item,low, mid-1);
    }
    else {
        // 3. RECURSIVE FUNCTION CALL
        binarySearch(item, mid+1, high);
    }

}
 


int main(){
    Queue<int> myQueue;
    myQueue.enqueue(10);
    myQueue.enqueue(11);
    myQueue.enqueue(2);
    myQueue.enqueue(4);
    myQueue.enqueue(9);
    myQueue.enqueue(100);
    myQueue.enqueue(6);

    myQueue.print();
    // std:: cout<< myQueue.dequeue()<<std::endl;
 

    std::cout<<myQueue.binarySearch(22,0,myQueue.getSize())<<std::endl;
    std::cout<<"found at array index: "<<myQueue.binarySearch(100,myQueue.getI(),myQueue.getSize())<<std::endl;
    

}