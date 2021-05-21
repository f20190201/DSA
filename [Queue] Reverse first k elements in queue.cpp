// Put first k elements in a stack
// Empty the stack into the original queue
// Put (size - k) elements into a temporary queue
// Empty the temporary queue into the original queue
// Both O(N)

queue<int> modifyQueue(queue<int> q, int k)
{
    
    int n = q.size();
    stack<int> s;
    queue<int> qu;
    
    for(int i = 0; i<k ; i++){
        s.push(q.front());
        q.pop();
    }
    
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    
    for(int i = 0; i<(n-k) ; i++){
        qu.push(q.front());
        q.pop();
    }
    
    while(!qu.empty()){
        q.push(qu.front());
        qu.pop();
    }
    
    return q;
}
