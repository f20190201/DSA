void dfs(vector<int> &A, vector<bool> &visited, int C,int u,vector<vector<int> > &adj, int &count,int good)
{
  //general Node
    if(good+A[u-1]>C)
    return ;
    
    //leaf Node
    if(adj[u].size()==1 && !visited[u] && C>=good+A[u-1])
    {count++;return;}
    
      //else go forward
    visited[u]=true;
    
    for(int i=0;i<adj[u].size();i++)
    {
        if(!visited[adj[u][i]])
        {
          dfs(A,visited,C,adj[u][i],adj,count,good+A[u-1]);  
            
        }
        
    }
    
 return ;   
}






int Solution::solve(vector<int> &A, vector<vector<int> > &B, int C) {
    int count = 0;
    vector<bool> visited(A.size()+1,false);
    vector<vector<int> > adj(A.size()+1);
    for(int i=0;i<B.size();i++)
    {
        adj[B[i][0]].push_back(B[i][1]);
        adj[B[i][1]].push_back(B[i][0]);
    }
    
  dfs(A,visited,C,1,adj,count,0);
  return count;
}
