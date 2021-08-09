class Solution {
public:
    int trap(vector<int>& A) {
        int l = 0 , r = A.size() - 1 , leftMax = INT_MIN , rightMax = INT_MIN;
        int ans = 0;
        
        while(l < r){
            if(A[l] > leftMax)
                leftMax = A[l];
            
            if(A[r] > rightMax)
                rightMax = A[r];
            
            if(leftMax < rightMax){
                ans += (leftMax - A[l]);
                l++;
            }
            
            else{
                ans += (rightMax - A[r]);
                r--;
            }
        }
        
        return ans;
        
    }
};