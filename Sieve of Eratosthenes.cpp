vector<int> Solution::sieve(int A) {
    vector<int> serial(A+1);
    vector<bool> visited(A+1 , 0);

    for(int i = 2 ; i <= A ; i++){
        serial[i] = i;
    }

    for(int i = 2 ; i <= A ; i++){
        if(visited[i])
            continue;
        
        for(int j = 2*i ; j <= A ; j += i)
            visited[j] = 1;
    }

    vector<int> ans;

    for(int i = 2 ; i <= A ; i++){
        if(!visited[i])
            ans.push_back(i);
    }


    return ans;

}
