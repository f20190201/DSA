class Solution {
public:
    int largestRectangleArea(vector<int>& A) {
        stack<int>s;
        int i = 0 , n = A.size() , temp = 0 , ans = 0;
        
        while(i < n){
            
            if(s.empty() || A[s.top()] <= A[i]){
                s.push(i++);
                continue;
            }
            
            int top = s.top();
            s.pop();
            
            if(!s.empty()){
                temp = A[top] * (i - s.top() - 1);
            }
            else
                temp = A[top] * (i - (-1) - 1);     // s.top() = -1 (assume)
            
            ans = max(ans , temp);
        }
        
        while(!s.empty()){
            int top = s.top();
            s.pop();
            
            if(!s.empty()){
                temp = A[top] * (i - s.top() - 1);
            }
            else
                temp = A[top] * (i - (-1) - 1);     // s.top() = -1 (assume)
            
            ans = max(ans , temp);
            
        }
        
        return ans;
    }
};