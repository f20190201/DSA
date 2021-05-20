// Idea is to keep q1 as the main queue. Push operation is costly in O(N) and pop is O(1).

// For push, we insert the element in q2 and then pop all the elements from q1 to q2. We then swap q1 and q2. 
// For pop, we just pop the first element of q1.

//Function to push an element into stack using two queues.
void QueueStack :: push(int x)
{
        // Your Code
        q2.push(x);
        
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        q1.swap(q2);
        return;
}

//Function to pop an element from stack using two queues. 
int QueueStack :: pop()
{
        // Your Code 
        if(q1.size() == 0)
            return -1;
        int ans = q1.front();
        q1.pop();
        return ans;
        
}
