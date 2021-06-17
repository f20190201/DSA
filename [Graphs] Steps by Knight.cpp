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

------------------------------------------------------------------------------------------
	GFG SOLUTION
	
	// C++ program to find minimum steps to reach to
// specific cell in minimum moves by Knight
#include <bits/stdc++.h>
using namespace std;
  
// structure for storing a cell's data
struct cell {
    int x, y;
    int dis;
    cell() {}
    cell(int x, int y, int dis)
        : x(x), y(y), dis(dis)
    {
    }
};
  
// Utility method returns true if (x, y) lies
// inside Board
bool isInside(int x, int y, int N)
{
    if (x >= 1 && x <= N && y >= 1 && y <= N)
        return true;
    return false;
}
  
// Method returns minimum step
// to reach target position
int minStepToReachTarget(
    int knightPos[], int targetPos[],
    int N)
{
    // x and y direction, where a knight can move
    int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
    int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
  
    // queue for storing states of knight in board
    queue<cell> q;
  
    // push starting position of knight with 0 distance
    q.push(cell(knightPos[0], knightPos[1], 0));
  
    cell t;
    int x, y;
    bool visit[N + 1][N + 1];
  
    // make all cell unvisited
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            visit[i][j] = false;
  
    // visit starting state
    visit[knightPos[0]][knightPos[1]] = true;
  
    // loop untill we have one element in queue
    while (!q.empty()) {
        t = q.front();
        q.pop();
  
        // if current cell is equal to target cell,
        // return its distance
        if (t.x == targetPos[0] && t.y == targetPos[1])
            return t.dis;
  
        // loop for all reachable states
        for (int i = 0; i < 8; i++) {
            x = t.x + dx[i];
            y = t.y + dy[i];
  
            // If reachable state is not yet visited and
            // inside board, push that state into queue
            if (isInside(x, y, N) && !visit[x][y]) {
                visit[x][y] = true;
                q.push(cell(x, y, t.dis + 1));
            }
        }
    }
}
  
// Driver code to test above methods
int main()
{
    int N = 30;
    int knightPos[] = { 1, 1 };
    int targetPos[] = { 30, 30 };
    cout << minStepToReachTarget(knightPos, targetPos, N);
    return 0;
}
