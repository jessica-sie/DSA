// CONVERT DECIMAL NOTATION TO BINARY
#include <iostream>
#include <array>
#include <string>
using namespace std;

// iterative function 
int DTBIteration(int dec){
    // initializing binary array 
    array<int,8> binary;

    while(dec/2 == 0){
        binary[i] = dec%2;
        dec = dec/2;
    };

    string result;
    for (int i = 8; i>0; i--){
        result = result + binary[i]
    }
    
    return binary;
}
int main(){

}