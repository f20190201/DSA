// We use BFS here.
// A knight has 8 ways to move and all of them are accounted for.
// The chessboard itself is being assumed as the visited array.
// The value of a block is (1 + value of previous block)

int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    int x1 = KnightPos[0];
	    int x2 = TargetPos[0];
	    int y1 = KnightPos[1];
	    int y2 = TargetPos[1];
	    if(x1==x2 and y1==y2)
	        return 0;
	    
	    int arr[N][N] = {0};
	    //(x-2, y-1) , (x-2, y+1) , (x-1, y-2) , (x-1, y+2) 
	    //(x+2, y-1) , (x+2, y+1) , (x+1, y-2) , (x+1, y+2)
	    
	    queue<pair<int , int>> q;
	    
	    q.push({x1-1 , y1-1});
	    arr[x1-1][y1-1] = 1;
	    
	    while(!q.empty()){
	        auto pos = q.front();
	        int x = pos.first;
	        int y = pos.second;
	        q.pop();
	        if((x2 == (x+1)) and (y2 == (y+1)))
	            return arr[x][y]-1;
	        //(x-2,y-1)
	        if((x-2)>=0 and (x-2) < N and (y-1) >= 0 and (y-1) < N and (arr[x-2][y-1] == 0)){
	            q.push({x-2 , y-1});
	            arr[x-2][y-1] = 1 + arr[x][y];
	        }
	        //(x-2,y+1)
	        if((x-2)>=0 and (x-2) < N and (y+1) >= 0 and (y+1) < N and (arr[x-2][y+1] == 0)){
	            q.push({x-2 , y+1});
	            arr[x-2][y+1] = 1 + arr[x][y];
	        }
	        //(x-1,y-2)
	        if((x-1)>=0 and (x-1) < N and (y-2) >= 0 and (y-2) < N and (arr[x-1][y-2] == 0)){
	            q.push({x-1 , y-2});
	            arr[x-1][y-2] = 1 + arr[x][y];
	        }
	        //(x-1,y+2)
	        if((x-1)>=0 and (x-1) < N and (y+2) >= 0 and (y+2) < N and (arr[x-1][y+2] == 0)){
	            q.push({x-1 , y+2});
	            arr[x-1][y+2] = 1 + arr[x][y];
	        }
	        //(x+2, y-1) 
	        if((x+2)>=0 and (x+2) < N and (y-1) >= 0 and (y-1) < N and (arr[x+2][y-1] == 0)){
	            q.push({x+2 , y-1});
	            arr[x+2][y-1] = 1 + arr[x][y];
	        }
	        //, (x+2, y+1) 
	        if((x+2)>=0 and (x+2) < N and (y+1) >= 0 and (y+1) < N and (arr[x+2][y+1] == 0)){
	            q.push({x+2 , y+1});
	            arr[x+2][y+1] = 1 + arr[x][y];
	        }
	        //, (x+1, y-2) 
	        if((x+1)>=0 and (x+1) < N and (y-2) >= 0 and (y-2) < N and (arr[x+1][y-2] == 0)){
	            q.push({x+1 , y-2});
	            arr[x+1][y-2] = 1 + arr[x][y];
	        }
	        //, (x+1, y+2)
	        if((x+1)>=0 and (x+1) < N and (y+2) >= 0 and (y+2) < N and (arr[x+1][y+2] == 0)){
	            q.push({x+1 , y+2});
	            arr[x+1][y+2] = 1 + arr[x][y];
	        }
	            
	    }
	    return arr[x2-1][y2-1]-1;
	}
