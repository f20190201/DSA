// We store the consecutive frequencies in a stack.
// If consective frequency of a particular character == B then we do not append it to our result

string Solution::solve(string A, int B) {
    string result = "";

    stack<pair<char , int>> s;

    for(int i = 0 ; i < A.size() ; i++){
        if(s.empty() or s.top().first != A[i])
            s.push({A[i] , 1});
        
        else{
            auto top = s.top();
            top.second++;
            s.pop();
            s.push({top.first , top.second});
        }
        
    }

    while(!s.empty()){
        auto top = s.top();
        s.pop();
        
        if(top.second == B)
            continue;
        
        while(top.second--)
            result += top.first;

    }
    reverse(result.begin() , result.end());
    return result;
}
