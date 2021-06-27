// We divide the array into two halves. We consider the left half to be sorted.
// We now consider each element from the right half and push it into its correct position on the left half


#include <iostream>
using namespace std;

void insertionSort(int A[] , int n){
    
    for(int i = 1 ; i < n ; i++){
        int hole = i;
        int value = A[i];
        
        while(hole > 0 and A[hole - 1] > value){
            A[hole] = A[hole - 1];
            hole--;
        }
            
        
        A[hole] = value;
        
    }
    return;
}


int main() {
	// your code goes here
	int arr[] = {3,5,1,9,4,6};
	insertionSort(arr , 6);
	
	for(auto x:arr)
	    cout<<x<<" , ";
	    
	
	return 0;
}
