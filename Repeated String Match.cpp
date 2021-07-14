// For B to be a substring of A, we multply A as many times to make its length greater than B
// We check if the increased A contains B, if not, we increase it once more, if not, we return -1

bool isSub(string s1 , string s2){  //Is s2 a substring of s1
        int n = s1.size() , m = s2.size();
        
        for(int i = 0 ; i < n - m + 1 ; i++){
            
            int j;
            
            for(j = 0 ; j < m ; j++){
                
                if(s1[i + j] != s2[j])
                    break;
            }
            
            if(j == m)
                return 1;
        }
        
        return 0;
        
    }
    
    
    int repeatedStringMatch(string A, string B) 
    {
        // Your code goes here
        int count = 1;
        string s = A;
        
        while(s.size() < B.size()){
            s = s.append(A);
            count++;
        }
        
        if(isSub(s , B))
            return count;
        
        if(isSub(s + A , B))
            return count + 1;
        
        return -1;
        
    }
