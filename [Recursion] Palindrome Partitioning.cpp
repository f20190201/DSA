// https://www.youtube.com/watch?v=wvaYrOp94k0

// We use the prefix of each string if its a palinddrome, and then recurse for rest of the string

vector<vector<string>> result;

bool isPalin(string s){
    int start = 0 , end = s.size() - 1;

    while(start < end){
        if(s[start] != s[end])
            return 0;
        start++;
        end--;
    }

    return 1;
}

void solve(string A , vector<string> &v){

    if(A.size() == 0){
        result.push_back(v);
        return;
    }

    for(int i = 0 ; i < A.size() ; i++){
        string prefix = A.substr(0 , i + 1);
        string ros = A.substr(i + 1);

        if(isPalin(prefix)){
            v.push_back(prefix);
            solve(ros , v);
            v.pop_back();
        }
    }
    return;
}

vector<vector<string> > Solution::partition(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    result.clear();
    
    vector<string> v;

    solve(A , v);

    return result;
}
