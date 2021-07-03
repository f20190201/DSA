stack<int>s;
int minEle;
MinStack::MinStack() {
    while(!s.empty()){
        s.pop();
    }

}

void MinStack::push(int x) {
    if(s.empty()){
        s.push(x);
        minEle = x;
        return;
    }

    if(x < minEle){
        int y = 2*x - minEle;
        s.push(y);
        minEle = x;
    }
    else
        s.push(x);

}

void MinStack::pop() {
    if(s.empty())
        return;
    if(s.top() < minEle){
        int y = minEle;
        minEle = 2*y - s.top();
        s.pop();
        return;
    }

    else{
        s.pop();
        return;
    }
}

int MinStack::top() {
    if(s.empty())
        return -1;
    if(s.top() < minEle){
        return minEle;
    }

    else{
        return s.top();
    }
}

int MinStack::getMin() {
    if(s.empty())
        return -1;
    
    else
        return minEle;
}
