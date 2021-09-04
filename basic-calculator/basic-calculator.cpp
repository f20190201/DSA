class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        st.push(1);
        
        int ans = 0 , num = 0 , flag = 1;
        
        for(int i = 0 ; i < s.size() ; i++){
            char ch = s[i];
            
            if(isdigit(ch)){
                num = num * 10 + (ch - '0');
                continue;
            }
            
            ans += num * flag * st.top();
            num = 0;
            
            if(ch == '+')
                flag = 1;
            
            else if(ch == '-')
                flag = -1;
            
            else if(ch == '('){
                st.push(st.top() * flag);
                flag = 1;
            }
            else if(ch == ')')
                st.pop();
        }
        ans += num * flag * st.top();
        return ans;
        
        
        // stack<int> op({1});
        // int total = 0, num = 0;
        // int isPositive = 1;
        // for (char c : s) {
        //     if (isdigit(c)) {
        //         num = num * 10 + (c - '0');
        //     } else {
        //         total += num * isPositive * op.top();
        //         num = 0;
        //         if (c == '+') isPositive = 1;
        //         if (c == '-') isPositive = -1;
        //         if (c == ')') op.pop();
        //         if (c == '(') {
        //             op.push(op.top() * isPositive);
        //             isPositive = 1;
        //         }
        //     }
        // }
        // total += num * isPositive * op.top();
        // return total;
    }
};