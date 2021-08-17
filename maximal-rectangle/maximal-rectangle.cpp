class Solution {
public:
    int MAH(vector<int> &A){
        int n = A.size() , res = 0;
        stack<int>s;
        
        int i = 0;
        
        while(i < n){
            
            if(s.empty() || A[i] >= A[s.top()]){
                s.push(i);
                i++;
                continue;
            }
            
            int top = s.top();
            s.pop();
            
            int leftBound = (s.empty()) ? -1 : s.top();
            
            res = max(res , A[top] * (i - leftBound - 1));
            
        }
        
        while(!s.empty()){
            
            int top = s.top();
            s.pop();
            
            int leftBound = (s.empty()) ? -1 : s.top();
            
            res = max(res , A[top] * (i - leftBound - 1));
            
        }
        
        return res;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size() ;
        if(!n)
            return 0;
        int m = matrix[0].size() , ans = 0;

        vector<int> prefix(m);
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                
                if(i == 0){
                    prefix[j] = matrix[i][j] - 48;
                    continue;
                }
                
                prefix[j] = (matrix[i][j] == '0') ? 0 : prefix[j] + 1;
            }
            ans = max(ans , MAH(prefix));
        }
        
        return ans;
    }
};