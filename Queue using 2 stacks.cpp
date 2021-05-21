// Push is O(1) and pop is O(N)
// We keep s1 as the main stack where we push elements. 
// We transfer elements to s2 only when it is empty and we need to pop. We transfer elements to s2 till s1 is empty and then pop from there. [For reversing the order]
// If s2 isn't empty and pop is called, we simply return s2.top()

stack<int> s1;
stack<int> s2;
void StackQueue :: push(int x)
{
    
    s1.push(x);
    return;
}


int StackQueue :: pop()
{
        // Your Code   
        if(s1.empty() && s2.empty())
            return -1;
            
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        
        if(!s2.empty()){
            int result = s2.top();
            s2.pop();
            return result;
        }
}
