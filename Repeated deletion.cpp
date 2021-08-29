// Create a stack and push only those elements that do not occur consecutively.
// Pop elements if the current element is same as the top of the stack
// https://binarysearch.com/problems/Repeated-Deletion

string solve(string s) {
    stack<char> st;

    for(int i = 0 ; i < s.size() ; i++){
        
        if(st.empty() || (st.top() != s[i])){
            st.push(s[i]);
            continue;
        }

        while(s[i] == st.top())
            i++;
        
        st.pop();
        i--;
    }

    string res = "";

    while(!st.empty()){
        res = st.top() + res;

        st.pop();
    }

    return res;
}
