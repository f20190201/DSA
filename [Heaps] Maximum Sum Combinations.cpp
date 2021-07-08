vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    // #define int long long int
    int N = A.size();
    
    priority_queue<pair<int , pair<int , int>>>maxHeap;

    sort(A.begin() , A.end());
    sort(B.begin() , B.end());

    maxHeap.push({A[N - 1] + B[N - 1] , {N-1 , N-1}});

    set<pair<int , int>>s;
    vector<int> result;

    while(C--){
        auto top = maxHeap.top();
        result.push_back(top.first);
        maxHeap.pop();

        int i = top.second.first;
        int j = top.second.second;

        int sum = A[i - 1] + B[j];

        pair<int , int> p = {i - 1 , j};

        if(s.find(p) == s.end()){
            maxHeap.push({sum , p});
            s.insert(p);
        }
        sum = A[i] + B[j - 1];
        p = {i , j - 1};

        if(s.find(p) == s.end()){
            maxHeap.push({sum , p});
            s.insert(p);
        }


    }
    return result;
    
}


------------------------------------------------------------------------------------------------------------
  
  
  vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    int n=A.size();
    priority_queue<pair<int,pair<int,int>>>p;
    for(int i=0;i<n;i++)
    {
    p.push({A[n-1]+B[i],{n-1,i}});
    }
    vector<int>v;
    pair<int,pair<int,int>>q;
    while(v.size()<C)
    {
        q=p.top();
      int sum=q.first;
      pair<int,int>x=q.second;
      int i=q.second.first;
      int j=q.second.second;
      v.push_back(sum);
      p.pop();
      p.push({A[i-1]+B[j],{i-1,j}});
      
    }
    return v;
}

