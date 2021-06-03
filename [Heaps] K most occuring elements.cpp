// A function that returns the total sum frequency of top K most frequesnt elements
// We make a map which maps elements to their frequencies
// We make a minHeap and if size of minHeap becomes more than K, we pop elements
// After iterating through the whole map, we would now be left with the K most frequently occuring elements in the array.

int kMostFrequent(int arr[], int n, int k) 
    { 
    	// Your code here
    	map<int , int> mp;
    	
    	for(int i = 0 ; i < n ; i++)
    	    mp[arr[i]]++;
    	
    	priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> q;
    	
    	for(auto i : mp){
    	    q.push({i.second , i.first});
    	    
    	    if(q.size() > k)
    	        q.pop();
    	}
        int result = 0;
        
        while(q.size() != 0){
            result += q.top().first;
            q.pop();
        }
        return result;
        
    	
    } 
