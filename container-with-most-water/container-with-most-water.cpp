class Solution {
public:
    int maxArea(vector<int>& A) {
        int l = 0 , r = A.size() - 1;
        int res = INT_MIN;
        
        while(l < r){
            int temp = (r - l) * min(A[l] , A[r]);
            res = max(temp , res);
            
            if(A[l] > A[r])
                r--;
            else
                l++;
            
        }
        
        return res;
    }
};