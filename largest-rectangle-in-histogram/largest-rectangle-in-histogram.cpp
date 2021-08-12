class Solution {
public:
    int largestRectangleArea(vector<int>& A) {
        int n = A.size() , temp = 0 , ans = 0;
        stack<int> s;
        int i = 0;
        
        while(i < n){
            
            if(s.empty() || A[s.top()] <= A[i]){
                s.push(i++);
                continue;
            }
            
            int top = s.top();
            s.pop();
            
            int leftBound = (s.empty() ? -1 : s.top());
            
            temp = A[top] * (i - leftBound - 1);
            
            ans = max(ans , temp);
        }
        
        while(!s.empty()){
            
            int top = s.top();
            s.pop();
            
            int leftBound = (s.empty() ? -1 : s.top());
            
            temp = A[top] * (i - leftBound - 1);
            
            ans = max(ans , temp);    
        }
        
        return ans;
    }
};