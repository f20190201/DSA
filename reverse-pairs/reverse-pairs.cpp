class Solution {
public:
    vector<int>A;
    
    int merge(int start , int mid , int end){
        int count = 0;
        
        int l = mid + 1;
        
        for(int i = start ; i <= mid ; i++){
            while(l <= end && A[i] > 2ll * A[l])
                l++;
            count += (l - (mid + 1));
        }
        
        int n1 = mid - start + 1;
        int n2 = end - mid;
        int arr1[n1];
        int arr2[n2];
        
        for(int i = 0 ; i < n1 ; i++)
            arr1[i] = A[start + i];
        
        for(int i = 0 ; i < n2 ; i++)
            arr2[i] = A[mid + 1 + i];
        
        int i = 0 , j = 0 , k = start;
        
        while(i < n1 && j < n2){
            
            if(arr1[i] < arr2[j]){
                A[k] = arr1[i];
                k++;
                i++;
            }
            
            else{
                
                A[k] = arr2[j];
                k++;
                j++;
            }
        }
        
        while(i < n1){
            A[k] = arr1[i];
            k++;
            i++;    
        }
        
        while( j < n2){
            A[k] = arr2[j];
            k++;
            j++;    
        }
        
        return count;
    }
    
    int mergeSort(int start , int end){
        int count = 0;
        
        if(start < end){
            
            int mid = (start + end) / 2;
            
            count += mergeSort(start , mid);
            count += mergeSort(mid + 1 , end);
            count += merge(start , mid , end);
        }
        
        return count;
    }
    
    int reversePairs(vector<int>& nums) {
        A = nums;
        
        return mergeSort(0 , nums.size() - 1); 
    }
};