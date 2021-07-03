class Solution {
public:
    int trap(vector<int>& A) {
        int l = 0 , r = A.size() - 1 , leftMax = INT_MIN , rightMax = INT_MIN;
        int result = 0;
        while(l <= r){
            if(A[l] > leftMax)  leftMax = A[l];
            if(A[r] > rightMax) rightMax = A[r];
            
            if(leftMax < rightMax){
                result += (leftMax - A[l]);
                l++;
            }
            else{
                result += (rightMax - A[r]);
                r--;
            }
            
        }
        return result;
        
    }
};