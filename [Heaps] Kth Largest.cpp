// Maintain a minHeap and push elements one-by-one.
// When size > k, pop the (k+1)th element
// After the array is traversed, root would be the Kth largest element

int KthLargest(int arr[], int n, int k) {
        // Your code here
        priority_queue<int , vector<int> , greater<int>> qmin;
        for(int i = 0 ; i < n ; i++){
            qmin.push(arr[i]);
            
            if(qmin.size() > k)
                qmin.pop();
        }
        return qmin.top();
        
    }
