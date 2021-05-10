int result;

int getMin(int arr[] , int n){
  
  stack<int>s;
  
  for(int i = 0; i<n; i++){
  
    // Push operation.   
    
    if(s.empty()){
        s.push(arr[i]);
        result = s.top();   }
    
    else if(arr[i] >= s.top())
     s.push(arr[i]);
    
    // If the current element is lesser than minimum, we insert (2*curr_ele - min_ele) into the stack, else we insert the current element as it is.
    
    else{
     s.push(2*arr[i] - result);
     result = arr[i];
    }
  
  }
  
  // Pop Operation
  
  if(s.empty())
        return -1;
  
  else if(s.top() >= result){
  s.pop();
  }
  
  else{
    int ans = result;
    result = 2*ans - s.top();
    s.pop();
    return ans;
  }
  
}
