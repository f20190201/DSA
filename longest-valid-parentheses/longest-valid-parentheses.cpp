class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size() , count = 0 , ans = 0;
        
        for(int i = 0 ; i < n ; i++){
            count = 0;
            
            for(int j = i ; j < n ; j++){
                
                if(s[j] == '(')
                    count++;
                
                else
                    count--;
                
                if(!count)
                    ans = max(ans , j - i + 1);
                
                else if(count < 0)
                    break;
            }
        }
        
        return ans;
    }
};