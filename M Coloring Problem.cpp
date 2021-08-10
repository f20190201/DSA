// https://www.youtube.com/watch?v=wuVwUK25Rfc&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=61&t=7s

bool isSafe(int node , int colour[] , bool graph[101][101] , int N , int i){
    
    for(int k = 0 ; k < N ; k++){
        if(k != node && graph[k][node] == 1 && colour[k] == i)
            return 0;
    }
    
    return 1;
}


bool solve(int node , int colour[] , int m , int N , bool graph[101][101]){
    if(node == N)
        return 1;
    
    for(int i = 1 ; i <= m ; i++){
        if(isSafe(node , colour , graph , N , i)){
            colour[node] = i;
            
            if(solve(node + 1 , colour , m , N , graph))
                return 1;
            
            colour[node] = 0;
        }
            
    }
    
    return 0;
}

bool graphColoring(bool graph[101][101], int m, int N)
{
    // your code here
    int colour[N] = {0};
    
    if(solve(0 , colour , m , N , graph))
        return 1;
        
    return 0;
}
