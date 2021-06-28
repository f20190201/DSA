#include <bits/stdc++.h>
using namespace std;

int lastOccurence(vector<int> &A , int B){
    int low = 0 , high = A.size() - 1 , res = -1;
    
    while(low <= high){
        int mid = low + (high - low) / 2;
        
        if(A[mid] == B){
            res = mid;
            low = mid + 1;
            
        }
        
        else if(A[mid] > B)
            high = mid - 1;
        
        else
            low = mid + 1;
        }
    return res;
    }
    
    


int firstOccurence(vector<int> &A , int B){
    int low = 0 , high = A.size() - 1 , res = -1;
    
    while(low <= high){
        int mid = low + (high - low) / 2;
        
        if(A[mid] == B){
            res = mid;
            high = mid - 1;
        }
        
        else if(A[mid] > B)
            high = mid - 1;
        
        else
            low = mid + 1;
        }
    return res;
    }
    
    

int countLessThanOrEqual(vector<int> &A , int B){
    if(B >= A[A.size() - 1])
        return A.size();
    
    if(B < A[0])
        return 0;
    
    int low = 0 , res = -1;
    int high = A.size() - 1;
    
    
    while(low <= high){
        int mid = low + (high - low) / 2;
        
       if(A[mid] > B){
        high = mid - 1;
        res = mid;   
       }
        
        else
            low = mid + 1;
        
    }
    
    return res;
    
    
}

int countOfElement(int a , int b){
    if( a == -1 and b == -1)
        return 0;
    
    return max(b - a + 1 , 0);
}

int main() {
	// your code goes here
	vector<int>A = {2,3,4,4,4,6,9};
	cout<<lastOccurence(A , 1)<<endl;
	cout<<firstOccurence(A , 1)<<endl;
	cout<<countLessThanOrEqual(A , 1)<<endl;
	cout<<countOfElement(firstOccurence(A , 1) , lastOccurence(A , 1))<<endl;
	return 0;
}
