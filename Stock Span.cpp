vector <int> calculateSpan(int arr[], int n)
    {
       
       stack<pair<int , int>>s;  //The top of this stack stores the left nearest smaller number. In case it doesn't, we pop it till it does. 
    vector<int>leftMin;             //Vector to store Left Nearest smaller number
    
    for(int i = 0; i<n; i++){
      
      if(s.empty()){
            s.push({arr[i] , i});           //if stack is empty, push the number
          leftMin.push_back(-1);            //no left nearest smaller number exists, push -1 into the vector
      }
      
      else if(!s.empty() && s.top().first > arr[i]){
            leftMin.push_back(s.top().second);        //if stack.top() < number , s.top() is the left nearest smaller number
          s.push({arr[i] , i});                       
      }
      
      else if(!s.empty() && s.top().first <= arr[i]){
       
        while(!s.empty() && s.top().first <= arr[i])    //if stack.top() > number, pop numbers until it becomes empty or a lesser number is found.
            s.pop();
    
      if(s.empty()){
            s.push({arr[i] , i});
          leftMin.push_back(-1);
      }
      
      else{
            leftMin.push_back(s.top().second);
            s.push({arr[i] , i});
      }
       
    }
        
        //At this point, leftMin[] stores the indexes of the nearest left greatest number. 
    }
    
  for(int i = 0; i<leftMin.size() ; i++)
        leftMin[i] = (i-leftMin[i]);
    
  
  return leftMin;}
