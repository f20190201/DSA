class Solution {
public:
    int threeSumClosest(vector<int>& A, int target) {
        sort(A.begin() , A.end());
        int result = INT_MAX , minDiff = INT_MAX;
        
        for(int i = 0 ; i < A.size() ; i++){
            
            int l = i + 1 , r = A.size() - 1;
            
            while(l < r){
                int sum = A[i] + A[l] + A[r];
                
                if(abs(sum - target) < minDiff){
                    
                    minDiff = abs(sum - target);
                    result = sum;    
                }
                
                if(sum > target)
                    r--;
                
                else if(sum < target)
                    l++;
                
                else if(sum == target)
                    return sum;
            }
            
        }
        
        return result;
    }
};