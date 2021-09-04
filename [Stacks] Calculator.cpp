int comp(char a , char b){
    int aa = (a == '+' || a == '-') ? 1 : 2;
    int bb = (b == '+' || b == '-') ? 1 : 2;

    return aa - bb;
    // returns +ve if 1st argument is higher in priority as compared to 2nd
}

int calculate(stack<int> & nums , stack<char>& op){
    int b = nums.top();
    nums.pop();
    int a = nums.top();
    nums.pop();
    char c = op.top();
    op.pop();

    if(c == '+')
        return (a + b);
    
    if(c == '-')
        return (a - b);
    
    if(c == '*')
        return (a * b);
    
    if(c == '/')
        return (int)floor(1.0 * a / b);
    
    return -1;
}


int solve(string s) {
    stack<int> nums;
    stack<char>op;

    int i = 0 , j = 0 , n = s.size();

    while(j < n){
        
        if(s[j] == '-')
            j++;
        
        while(j < n && isdigit(s[j]))
            j++;
        
        nums.push(stoi(s.substr(i , j - i)));

        if(j == n){
            
            while(!op.empty())
                nums.push(calculate(nums , op));
            
            break;
        }

        if(op.empty() || comp(s[j] , op.top()) > 0)
            op.push(s[j]);
        
        else{
            while(!op.empty() && comp(s[j] , op.top()) <= 0)
                nums.push(calculate(nums , op));
            
            op.push(s[j]);
        }

        j++;
        i = j;
    }

    return nums.top();    
}
