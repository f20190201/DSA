A robot is located at the top-left corner of an A x B grid (marked ‘Start’ in the diagram below).
The robot can only move either down or right at any point in time. 
The robot is trying to reach the bottom-right corner of the grid (marked ‘Finish’ in the diagram below).
How many possible unique paths are there?


void DFS(int i , int j , int &count , int A , int B){
    if((i==(A-1)) and (j == (B-1))){
        count++;
        return;
    }
        if(i <= A-2)
            DFS(i+1 , j , count , A , B);
        if(j <= B-2)
            DFS(i , j+1 , count , A , B);

    return;
}


int Solution::uniquePaths(int A, int B) {
    // vector<vector<int>> visited(A , vector<int>(B , 0));

    int count = 0;

    DFS(0 , 0 , count , A , B);

    return count;




}
