// implementing merge sort to an array - to check if it works -> merge sort workss
#include <iostream>

template <typename T>
void merge(T *QArr,int start, int mid, int end){
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
void mergeSort(T QArr[],int start, int end){
    // if multiple elements in aux array - keep dividing array
    if (start < end ){
        int mid = (start+end)/2;
        // left half 
        mergeSort(QArr,start,mid);

        //right half
        mergeSort(QArr, mid+1, end);

        merge(QArr,start,mid,end);
    }
}


int main(){

    // defining an array 
    int myarr[5] = {5,4,3,2,1,};

    for(int i = 0; i < 5; i++){
        std::cout<< "unsorted: "<<myarr[i]<<std::endl;

    }

    // calling sort function 
    mergeSort(myarr,0,4);

    for (int i = 0; i <5; i++){
        std::cout<< "sorted: "<<myarr[i]<<std::endl;

    }

}