vector<vector<int> > Solution::threeSum(vector<int> &A) {

    sort(A.begin() , A.end());
    vector<vector<int>> result;
    int N = A.size();

    for(int i = 0 ; i < N - 2 ; i++){
        
        int start = i + 1 , end = N - 1;

        while(start < end){
            long long int sum = 0LL + A[i] + A[start] + A[end];

            if(sum == 0){
                vector<int> trio(3 , 0);
                
                trio[0] = A[i];
                trio[1] = A[start];
                trio[2] = A[end];

                result.push_back(trio);

                while(start < end and A[start] == trio[1])
                    start++;
                
                while(start < end and A[end] == trio[2])
                    end--;
            }

            else if(sum > 0)
                end--;
            
            else    
                start++;

        }

        while(i < N - 2 and A[i] == A[i + 1])
            i++;

    }
    return result;

}
