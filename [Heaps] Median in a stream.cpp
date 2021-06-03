// We make two heaps, maxHeap and minHeap
// maxHeap contains the lower half of element and minHeap the upper half (of the sorted array)
// For insert function, if sizes are equal, then check if x < maxHeap.top(), if true, then insert in maxHeap else in minHeap
// If maxHeap.size() > minHeap.size(), if x>maxHeap.top(), push to minHeap.
// Else, balance the heaps by transferring the root of maxHeap to minHeap and then pushing x to maxHeap.
// Do the corresponding if maxHeap.size() < minHeap.size()

priority_queue<int , vector<int> , greater<int>> qmin;
    priority_queue<int> qmax;
    
    
    void insertHeap(int &x)
    {
        if(qmin.size() == qmax.size()){
            if(qmin.size() == 0){
                qmax.push(x);
                return;
            }
            
            if(x < qmax.top())
                qmax.push(x);
            
            else    
                qmin.push(x);
        }
        
        else{
            
            if(qmax.size() > qmin.size()){
                if(x >= qmax.top())
                    qmin.push(x);
                
            
                
                else{
                    int temp = qmax.top();
                    qmax.pop();
                    qmax.push(x);
                    qmin.push(temp);
                }
            }
            else{
                if(qmin.size() > qmax.size()){
                if(x <= qmin.top())
                    qmax.push(x);
        
                else{
                    int temp = qmin.top();
                    qmin.pop();
                    qmin.push(x);
                    qmax.push(temp);
                }
            }
            }
                
        }
            
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        
    }
    
    //Function to return Median.
    double getMedian()
    {
        if(qmin.size() == qmax.size())
            return ((qmin.top() + qmax.top()) / 2);
        
        return (qmin.size() > qmax.size()) ? qmin.top() : qmax.top();
    }
