vector<int> Solution::maxone(vector<int> &A, int B) {
    vector<int>result;
    int start = 0;
    int count = 0;
    int ans = 0;

    for(int i = 0 ; i < A.size() ; i++){
        
        if(A[i] == 0)
            count++;
        
        int initial = start;

        while(count > B){
            if(A[start] == 0)
                count--;
            start++;
        }
        
        if(i - start + 1 > ans){
            ans = (i - start + 1);
            result.clear();
            for(int j = initial ; j <= i ; j++)
                result.push_back(j);
        }


    }



return result;
}
