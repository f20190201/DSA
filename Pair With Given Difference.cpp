int Solution::solve(vector<int> &A, int B) {
    sort(A.begin() , A.end());

    for(int i = 0 ; i < A.size() ; i++){
        int left = binary_search(A.begin() + i + 1 , A.end() , A[i] + B);
        int right = binary_search(A.begin() + i + 1 , A.end() , A[i] - B);

        if(left || right)
            return 1;
    }

    return 0;
}


--------------------------------------------------------------------------------
  
  // C++ program to find a pair with the given difference 
#include <bits/stdc++.h>
using namespace std;
  
// The function assumes that the array is sorted 
bool findPair(int arr[], int size, int n) 
{ 
    // Initialize positions of two elements 
    int i = 0; 
    int j = 1; 
  
    // Search for a pair 
    while (i < size && j < size) 
    { 
        if (i != j && arr[j] - arr[i] == n) 
        { 
            cout << "Pair Found: (" << arr[i] <<
                        ", " << arr[j] << ")"; 
            return true; 
        } 
        else if (arr[j]-arr[i] < n) 
            j++; 
        else
            i++; 
    } 
  
    cout << "No such pair"; 
    return false; 
} 
  
// Driver program to test above function 
int main() 
{ 
    int arr[] = {1, 8, 30, 40, 100}; 
    int size = sizeof(arr)/sizeof(arr[0]); 
    int n = 60; 
    findPair(arr, size, n); 
    return 0; 
} 
