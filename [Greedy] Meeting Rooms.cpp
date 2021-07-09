int Solution::solve(vector<vector<int> > &A) {
    if(!A.size())
        return 0;
    
    sort(A.begin() , A.end());
    int count = 1;
    priority_queue<int , vector<int> , greater<int>> minHeap;

    minHeap.push(A[0][1]);
    
    for(int i = 1 ; i < A.size() ; i++){
        if(A[i][0] < minHeap.top()){
            count++;
        }
        else{
            minHeap.pop();
        }
        minHeap.push(A[i][1]);
    }

    return count;
}

------------------------------------------------------------------------------------------------
  
  int Solution::solve(vector<vector<int> > &A) {
    
     vector<pair<int,int>> answer;
    
  
    
    for(int i=0;i<A.size();i++){
        answer.push_back(make_pair(A[i][0],1));
        answer.push_back(make_pair(A[i][1],0));


    }
    
    sort(answer.begin(),answer.end());
    

    
    int curr_rooms=0, max_rooms=0;
    for(pair<int,int> x:answer){
        if(x.second==1) curr_rooms++;
        if(x.second==0) curr_rooms--;
        
        if(max_rooms<curr_rooms) max_rooms=curr_rooms;
    }
    
    // for(auto x : answer) cout<<x.first<<" "<<x.second<<endl;

    
    
    return max_rooms;
    
}


--------------------------------------------------------------------------------------------------------------
  
  
  int Solution::solve(vector<vector<int> > &a) {
    vector<int>v1;
    vector<int>v2;
    int ans,i,n=a.size();
    for(i=0;i<n;i++)
    {
        v1.push_back(a[i][0]);
        v2.push_back(a[i][1]);
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    ans=0;
    int k=0,j=0;
    for(i=0;i<n;i++)
    {
       if(v1[k]<v2[j])
      {
                ans++;
                k++;
      }
      else
     {
      k++;
      j++;
     }
    }
    return ans;
}
