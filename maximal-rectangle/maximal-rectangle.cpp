class Solution {
public:
    int MAH(vector<int> &A){
        int n = A.size() , res = 0;
        stack<int>s;
        
        vector<int> leftMin(n , -1);
        vector<int> rightMin(n , n);
        
        for(int i = 0 ; i < n ; i++){
            
            while(!s.empty() && A[s.top()] >= A[i])
                s.pop();
            
            if(!s.empty())
                leftMin[i] = s.top();
            
            s.push(i);
        }
        
        while(!s.empty())
            s.pop();
        
        for(int i = n - 1 ; i >= 0 ; i--){
            while(!s.empty() && A[s.top()] >= A[i])
                s.pop();
            
            if(!s.empty())
                rightMin[i] = s.top();
            
            s.push(i);
        }
        
        for(int i = 0 ; i < n ; i++){
            int area = A[i] * (rightMin[i] - leftMin[i] - 1);
            
            res = max(res , area);
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