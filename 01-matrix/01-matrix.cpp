class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        vector<vector<int>>result(mat.size() , vector<int>(mat[0].size() , INT_MAX));
        
            
       queue<pair<int , int>> q;
        
        for(int i = 0 ; i < mat.size() ; i++){
            for(int j = 0 ; j < mat[0].size() ; j++){
                if(!mat[i][j]){
                    result[i][j] = 0;
                    q.push({i , j});
                }
            }
        }
        
        
        // ((x + rownbr[k]) >= 0) and ((x + rownbr[k]) < mat[0].size()) and ((y + colnbr[k]) >= 0) and ((y + colnbr[k]) < mat.size())
        int rownbr[] = {-1 , 0 , 0 , 1};
        int colnbr[] = { 0 , -1 , 1 , 0};
        
        while(!q.empty()){
            auto top = q.front();
            int x = top.first;
            int y = top.second;
            q.pop();
            
            for(int k = 0 ; k < 4 ; ++k){
                int x_cord = (x + rownbr[k]);
                int y_cord = (y + colnbr[k]);
                
                if((x_cord >= 0) and (x_cord < mat.size()) and (y_cord >= 0) and (y_cord < mat[0].size())){
                    
                    if(result[x_cord][y_cord] > (1 + result[x][y])){
                        result[x_cord][y_cord] = (result[x][y] + 1);
                        q.push({x_cord , y_cord});
                    }
                    
                }
            }
        }
        
        return result;
    }
};