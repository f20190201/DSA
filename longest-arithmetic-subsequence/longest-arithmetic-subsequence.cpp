class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size() , maxLen = 0;
        
        vector<map<int , int>> sequences(n);    // map stores differences as key and their existence as values
        
        for(int i = 0 ; i < n ; i++){
            for(int j = i + 1 ; j < n ; j++){
                
                int diff = nums[j] - nums[i];   // implying that ... , A[i] , A[j] , ... form AP
                
                if(sequences[i].find(diff) != sequences[i].end())
                    sequences[j][diff] = sequences[i][diff] + 1;
                
                else
                    sequences[j][diff] = 2;
                
                maxLen = max(maxLen , sequences[j][diff]);
            }
        }
        
        return maxLen;
    }
};