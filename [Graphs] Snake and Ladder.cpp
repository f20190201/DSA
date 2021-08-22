// Moves array contains values of end of ladder or tail of snake(if any) else it contains -1
// Every box in board can be considered as a vertex which is connected to next 6 at least, and ladder/snake(if any)
// We run a BFS and and insert adjacent elements into the queue with dist = curr_dist + 1 and vertex as vertex(if no snake/ladder) else moves[vertex]

struct qEntry{
        int v;
        int dist;
    };
    int minThrow(int N, int arr[]){
        // code here
        vector<bool> visited(30 , 0);
        vector<int> moves(30 , -1);
        
        for(int i = 0 ; i < 2 * N ; i += 2){
            moves[arr[i] - 1] = arr[i + 1] - 1;
        }
        
        queue<qEntry>q;
        
        visited[0] = 1;
        
        qEntry top;
        top.v = 0;
        top.dist = 0;
        
        q.push(top);
        
        while(!q.empty()){
            
            top = q.front();
            q.pop();
            
            int vertex = top.v;
            
            if(vertex == 29)
                break;
            
            for(int i = vertex + 1 ; i <= vertex + 6 && (i <= 29) ; i++){
                
                if(visited[i] == 1)
                    continue;
                
                qEntry s;
                
                visited[i] = 1;
                s.dist = top.dist + 1;
                
                if(moves[i] == -1)
                    s.v = i;
                else
                    s.v = moves[i];
                
                q.push(s);
            }
        }
        
        return top.dist;
    }
