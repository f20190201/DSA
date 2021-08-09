int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	vector<pair<int, int>>v;
    	priority_queue<int , vector<int> , greater<int>> minHeap;
    	
    	for(int i = 0 ; i < n ; i++)
    	    v.push_back({arr[i] , dep[i]});
    	    
    	sort(v.begin() , v.end());
        
        int count = 1;
        minHeap.push(v[0].second);
                
        for(int i = 1 ; i < n ; i++){
            
            if(v[i].first <= minHeap.top()){
                count++;
                minHeap.push(v[i].second);
                
                continue;
            }
            
            minHeap.pop();
            minHeap.push(v[i].second);
        }
        
        return count;
    }


----------------------------------------------------------------------------------------

// https://www.youtube.com/watch?v=dxVcMDI7vyI&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=47
  
  int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	sort(arr , arr + n);
    	sort(dep , dep + n);
    	
    	int i = 1 , j = 0;
    	
    	int count = 0 , temp = 1;
    	
    	while(i < n && j < n){
    	    
    	    if(arr[i] <= dep[j]){
    	        temp++;
    	        count = max(count , temp);
    	        i++;
    	    }
    	    
    	    else{
    	        temp--;
    	        j++;
    	    }
    	}
    	
    	return count;
    }
