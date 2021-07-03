int operation(string x , int num2 , int num1){
    if(x == "+")
        return (num1 + num2);
    if(x == "-")
        return (num2 - num1);
    if(x == "/")
        return (num2 / num1);
    if(x == "*")
        return (num1 * num2);
}


int Solution::evalRPN(vector<string> &A) {
    stack<int>s;
    
    for(auto x:A){
        if((x == "+") or (x == "-") or (x == "*") or (x == "/")){
            int num1 = (s.top());
            s.pop();
            int num2 = (s.top());
            s.pop();
            int result = operation(x , num2 , num1);
            s.push(result);
        }
        else
            s.push(stoi(x));
    }
    return s.top();

}
