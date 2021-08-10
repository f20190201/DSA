vector<string> result;
    
    int dx[4] = {1 , 0 , 0 , -1};
    int dy[4] = {0 , -1 , 1 , 0};
    string s = "DLRU";
    
    bool isValid(vector<vector<int>> &m , vector<vector<bool>> &visited , int i , int j){
        int N = m.size() , M = m[0].size();
        
        return (i >= 0 && i < N && j >= 0 && j < M && (!visited[i][j] && m[i][j] == 1));
        
    }
    
    bool solve(vector<vector<int>> &m , vector<vector<bool>> &visited , string str , int i , int j){
        
        if(i == m.size() - 1 && j == m[0].size() - 1){
            result.push_back(str);
            // return 1;
        }
        
        visited[i][j] = 1;
        
        for(int k = 0 ; k < 4 ; k++){
            
            str.push_back(s[k]);
            
            if(isValid(m , visited , i + dx[k] , j + dy[k]) && solve(m , visited , str , i + dx[k] , j + dy[k]))
                return 1;
            
            str.pop_back();
        }
        
        visited[i][j] = 0;
        
        return 0;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<vector<bool>> visited(n , vector<bool>(n , 0));
        
        result.clear();
        string str = "";
        
        if(m[0][0] == 0)
            return {};
            
        solve(m , visited , str , 0 , 0);
            
        return result;
    }
