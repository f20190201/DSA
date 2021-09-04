class Solution {
public:
    int dx[4] = {-1 , 1 , 0 , 0};
    int dy[4] = {0 , 0 , -1 , 1};
    
    bool isValid(vector<vector<int>>& grid , int i , int j){
        int n = grid.size() , m = grid[0].size();
        
        return (i >= 0 && i < n && j >= 0 && j < m);
    }
    
    int DFS(vector<vector<int>>& grid , int i , int j , int index){
        grid[i][j] = index;
        int area = 1;
        
        for(int k = 0 ; k < 4 ; k++){
            int X = i + dx[k] , Y = j + dy[k];
            
            if(isValid(grid , X , Y) && grid[X][Y] == 1){
                area += DFS(grid , X , Y , index);
            }
        }
        
        return area;
        
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        unordered_map<int , int> mp;
        
        int index = 2 , n = grid.size() , m = grid[0].size();
        int res = 0;
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                
                if(grid[i][j] == 1){
                    
                    mp[index] = DFS(grid , i , j , index);
                    res = max(res , mp[index]);
                    index++;
                }
            }
        }
        
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                
                if(grid[i][j] == 0){
                    unordered_set<int> s;
                    int curr = 1;

                    for(int k = 0 ; k < 4 ; k++){

                        int X = i + dx[k] , Y = j + dy[k];

                        if(isValid(grid , X , Y)){

                            index = grid[X][Y];

                            if(index >= 2 && s.count(index) == 0){
                                s.insert(index);
                                curr += mp[index];
                            }
                        }
                    }
                    res = max(res , curr);
                }
            }
        }
        
        return res;
    }
    
    
    
};




// int N;
//     int largestIsland(vector<vector<int>>& grid) {
//         N = grid.size();
//         //DFS every island and give it an index of island
//         int index = 2, res = 0;
//         unordered_map <int, int>area;
//         for (int x = 0; x < N; ++x) {
//             for (int y = 0; y < N; ++y) {
//                 if (grid[x][y] == 1) {
//                     area[index] = dfs(grid, x, y, index);
//                     res = max(res, area[index++]);
//                 }
//             }
//         }
//         //traverse every 0 cell and count biggest island it can conntect
//         for (int x = 0; x < N; ++x)
//             for (int y = 0; y < N; ++y)
//                 if (grid[x][y] == 0) {
//                     unordered_set<int> seen = {};
//                     int cur = 1;
//                     for (auto p : move(x, y)) {
//                         index = grid[p.first][p.second];
//                         if (index > 1 && seen.count(index) == 0) {
//                             seen.insert(index);
//                             cur += area[index];
//                         }
//                     }
//                     res = max(res, cur);
//                 }
//         return res;
//     }

//     vector<pair<int, int>> move(int x, int y) {
//         vector<pair<int, int>> res;
//         for (auto p : vector<vector<int>> {{1, 0}, { -1, 0}, {0, 1}, {0, -1}}) {
//             if (valid(x + p[0], y + p[1]))
//                 res.push_back(make_pair(x + p[0], y + p[1]));
//         }
//         return res;
//     }

//     int valid(int x, int y) {
//         return 0 <= x && x < N && 0 <= y && y < N;
//     }

//     int dfs(vector<vector<int>>& grid, int x, int y, int index) {
//         int area = 0;
//         grid[x][y] = index;
//         for (auto p : move(x, y))
//             if (grid[p.first][p.second] == 1)
//                 area += dfs(grid, p.first, p.second, index);
//         return area + 1;
//     }