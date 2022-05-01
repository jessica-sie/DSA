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
    std::array<T,MAX> items;// pointer to array
    int end; // index of queueEnd
    int i;// index of the queueFront 

    // alternative properties
    // int queueFront;
    // int queueEnd;

    public:
    // OPERATIONS 
    Queue():items(), end(0), i(0) {}; // constructor
    void enqueue(T item);
    T dequeue();
    void print();
    void sort();

    int binarySearch(T item, int i, int arrSize); // binary search the array, returns index of desired element

    // merge sort functions - divide and conquer 
    void mergeSort(T *QArr, int start, int end);//divide 
    void merge(T *QArr, int start, int mid,int end); // conquer 


    // getter and setter functions
    int getSize();
    int getI();
};

// IMPLEMENTATIONS
template <typename T>
int Queue<T>::getSize(){
    return this->end;
}

template <typename T>
int Queue<T>::getI(){
    return this->i;
}

template <typename T>
void Queue<T>::enqueue(T item){
    this->items[this->end] = item;
    this->end++;
    
    if(this->end>1){
        this->mergeSort(this->items,this->i,this->end);
    }

}

template <typename T>
T Queue<T>::dequeue(){
    // ERROR HANDLE if queue is empty
    if(i == end){
        std::cout << "queue is empty"<<std::endl;
    }
    else{
        return this->items[this->i++]; // increment front pointer   
    }
}

// TO DO: implement merge sort
// REFERENCE TO :https://www.interviewbit.com/tutorial/merge-sort-algorithm/ 



// TO DO: fix error to handle passing array into a function
template <typename T>
void Queue<T>::merge(T *QArr,int start, int mid, int end){
    // create auxillary array, to store sorted values?
    int temp[end-start+1];

    // declaring iterator vaiables 
    int i = start;
    int j = mid +1; 
    int k= 0;//k -> the index of the newly sorted arr

    // traversing both sub arrays
    while (i <= mid && j <= end){
        // add smaller element into aux array
        if(QArr[i]<QArr[j]){
            temp[k] = QArr[i];
            k++;
            i++;
        }
        else{
            temp[k] = QArr[j];
            j++;
            k++;
        }
    }

    // adding remaining elements 
    while(i<=mid){
        temp[k] = QArr[i];
        k++;
        i++;
    }
    while (j<= end){
        temp[k] = QArr[j];
        j++;
        k++;
    }

    //copy sorted array to original interval 
    for(i = start;i <=end;i++){
        QArr[i] = temp[i-start];
    }
}

//TO DO: implement mergeSort function - done
template <typename T>
void Queue<T>::mergeSort(T *QArr, int start, int end){
    // if multiple elements in aux array - keep dividing array
    if (start < end ){
        int mid = (start+end)/2;
        // left half 
        this->mergeSort(QArr,start,mid);

        //right half
        this->mergeSort(QArr, mid+1, end);

        this->merge(QArr,start,mid,end);
    }
}


// TO DO: ensure it prints ALL elements currently in queue -> done
template <typename T>
void Queue<T>::print(){
    std::cout << "SIZE OF QUEUE: " << this->end << std::endl;
    // printing the index
    int idx = 0; 
    for (int x = this->i; x < this->end; x++)
    {
        std::cout << idx++ << ": " << this->items[x] << std::endl;
    }
}

// bubble sort
template <typename T>
void Queue<T>::sort(){
    T temp;
    // bubble sort 
    for(int x = this->i; x<this->end; x++){ // x is a temp variable to traverse throughout the array 
        for (int y = x+1; y <this->end; y++){
            if (this->items[x]>this->items[y]){
                //swap
                temp = this->items[x];
                this->items[x] = this->items[y];
                this->items[y] = temp;

            }
        }
    }
    
}

// TO DO: BINARY SEARCH ALGORITHM -> done 
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
    std:: cout<< myQueue.dequeue()<<std::endl;
    myQueue.print();

    myQueue.enqueue(12); // enqueing a new element doesnt work 

    myQueue.print();
 

    std::cout<<myQueue.binarySearch(22,0,myQueue.getSize())<<std::endl;
    std::cout<<"found at array index: "<<myQueue.binarySearch(100,myQueue.getI(),myQueue.getSize())<<std::endl;
    

}