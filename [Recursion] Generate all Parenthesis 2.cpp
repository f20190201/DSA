vector<string> res;

bool isValid(string s){
    stack<char>st;

    for(int i = 0 ; i < s.size() ; i++){
        
        if(s[i] == '('){
            st.push('(');
            continue;
        }

        else{
            if(st.empty())
                return 0;
            st.pop();
        }

    }

    return st.empty();
}

void solve(string &s , int n){
    
    if(n == 0){
        if(isValid(s)){
            res.push_back(s);
        }
        return;
    }

    s.push_back('(');
    solve(s , n - 1);
    s.pop_back();
    s.push_back(')');
    solve(s , n - 1);
    s.pop_back();

    return;
}

vector<string> Solution::generateParenthesis(int A) {
    res.clear();

    string s = "";
    solve(s , 2 * A);

    return res;

}
