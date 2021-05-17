
// The idea is to maintain a deque whose 1st element is the largest number in the window

vector<int> MaxInArray(int arr[] , int n , int k){

    vector<int> answer;
    deque<int> q;
    
  // We pop elements in the deque till we find a number greater than our current number or the deque get emptied.
  
    for(int i = 0; i<k ; i++){
        while(!q.empty() && arr[q.back()] < arr[i])
            q.pop_back();
        q.push_back(i);
    }
    
    answer.push_back(arr[q.front()]);
    
 // We check if the maximum number in the window is the number that is to be excluded in the succeeding window or not. If yes, we pop that element out.
// We save the indexes of the maximum element in the deque not the actual numbers themselves.
  
    for(int i = k; i<n ; i++){
        if(q.front() == (i-k))
            q.pop_front();
        
        while(!q.empty() && arr[q.back()] < arr[i])
            q.pop_back();
        q.push_back(i);
        
        answer.push_back(arr[q.front()]);
    }
    
 return answer;   
} 
