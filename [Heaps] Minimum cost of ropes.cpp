// make a minHeap and first fill it with all array elements
// In the next loop, pop 2 elements at a time and add their sum to minimum_price
// Push the sum of the two popped values into the minHeap.

long long minCost(long long arr[], long long n) {
        // Your code here
        priority_queue<long long , vector<long long> , greater<long long>> qmin;
        long long price = 0;
        
        for(long long i = 0 ; i < n ; i++)
            qmin.push(arr[i]);
        
        while(qmin.size() >= 2){
            
            long long first , second;
                
                first = qmin.top();
                qmin.pop();
                
                second = qmin.top();
                qmin.pop();
                
                price += (first + second);
                qmin.push(first + second);
            
            
        }
        return price;   
    }
