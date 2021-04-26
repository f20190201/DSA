long long getMaxArea(long long arr[], int n){
    
   
    stack<pair<long long , long long>>s;  //The top of this stack stores the left nearest smaller number. In case it doesn't, we pop it till it does. 
    vector<long long>leftMin;             //Vector to store Left Nearest smaller number
    
    for(long long i = 0; i<n; i++){
      
      if(s.empty()){
            s.push({arr[i] , i});           //if stack is empty, push the number
          leftMin.push_back(-1);            //no left nearest smaller number exists, push -1 into the vector
      }
      
      else if(!s.empty() && s.top().first < arr[i]){
            leftMin.push_back(s.top().second);        //if stack.top() < number , s.top() is the left nearest smaller number
          s.push({arr[i] , i});                       
      }
      
      else if(!s.empty() && s.top().first >= arr[i]){
       
        while(!s.empty() && s.top().first >= arr[i])    //if stack.top() > number, pop numbers until it becomes empty or a lesser number is found.
            s.pop();
    
      if(s.empty()){
            s.push({arr[i] , i});
          leftMin.push_back(-1);
      }
      
      else{
            leftMin.push_back(s.top().second);
            s.push({arr[i] , i});
      }
      
    }}
    
    vector<long long> rightMin;             //Vector to store the right nearest smaller number
    stack<pair<long long , long long>> s1;  //The top of this stack stores the right nearest smaller number. In case it doesn't, we pop it till it does.
    
    for(long long i = n-1; i>=0; i--){
      
      if(s1.empty()){
            s1.push({arr[i] , i});
          rightMin.push_back(n);
      }
      
      if(!s1.empty() && s1.top().first < arr[i]){
            rightMin.push_back(s1.top().second);
            s1.push({arr[i] , i});
      }
      
      else if(!s1.empty() && s1.top().first >= arr[i]){
       
        while(!s1.empty() && s1.top().first >= arr[i])
            s1.pop();
    
      if(s1.empty()){
            s1.push({arr[i] , i});
          rightMin.push_back(n);
      }
      
      else{
            rightMin.push_back(s1.top().second);
            s1.push({arr[i] , i});
      }
      
    }
      
    }
    
    reverse(rightMin.begin() , rightMin.end());
    
    long long result = LLONG_MIN;
    
    for(long long i = 0; i<n ; i++){
        long long area = (rightMin[i] - leftMin[i] - 1)*arr[i];
        result = max(area , result);
    }
    
    
    return result;
        
        
        
        
}
