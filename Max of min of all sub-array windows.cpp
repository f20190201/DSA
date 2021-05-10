vector <int> maxOfMin(int arr[], int n)
    {
       
        vector<int>leftMin(n , -1);
        vector<int> rightMin(n , n);
        
  // Nearest smaller to left and right are contained in leftMin and rightMin array respectively.
  
        stack<int>s;
        
        for(int i = 0; i<n; i++){
            
            while(!s.empty() && (arr[s.top()] >= arr[i]))
                s.pop();
                
            if(!s.empty())
                leftMin[i] = s.top();
                
            s.push(i);
        }
        
        while(!s.empty())
            s.pop();
            
        for(int i = n-1; i>=0; i--){
            
            while(!s.empty() && (arr[s.top()] >= arr[i]))
                s.pop();
                
            if(!s.empty())
                rightMin[i] = s.top();
                
            s.push(i);
        }
        
        
            
        vector<int> result(n+1 , 0);
        
  // Comparing arr[i] with existing values in resuilt[i] and finding the max.
  
        for(int i = 0; i<n; i++){
            int window = rightMin[i] - leftMin[i] - 1;
            result[window] = max(result[window] , arr[i]);
        }
        
  // For the indexes with no direct answer, we compare it with the next element in the array.
  
        for(int i = n-1; i>=1; i--){
            result[i] = max(result[i] , result[i+1]);
        }
        
    // Removal of window of length = 0  
  
        result.erase(result.begin());
        return result;
    }
