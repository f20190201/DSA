// We take 4 pointers.
// We initialise i and then calculate 3 sum for remaining
// We then initialise j and calculate 2 sum for remaining
// After calculating, we increment all pointers until we get different values from the latest entry into the result vector(to dispel duplicates)

vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
    vector<vector<int>> result;
    sort(A.begin() , A.end());
    int N = A.size();

    for(int i = 0 ; i < N - 3 ; i++){
        int target3 = B - A[i];

        for(int j = i + 1 ; j < N - 2 ; j++){
            int target2 = target3 - A[j];

            int low = j + 1 , high = N - 1;

            while(low < high){
                int sum = A[low] + A[high];

                if(sum == target2){
                    vector<int> quadruplet(4 , 0);
                    quadruplet[0] = A[i];
                    quadruplet[1] = A[j];
                    quadruplet[2] = A[low];
                    quadruplet[3] = A[high];
                    result.push_back(quadruplet);

                    while(low < high and A[low] == quadruplet[2])  low++;
                    while(low < high and A[high] == quadruplet[3])  high--;
                }

                else if(sum > target2)
                    high--;
                
                else
                    low++;

            } 
    
            while( j + 2 < N and A[j] == A[j + 1])  j++;

        }
        while( i + 3 < N and A[i] == A[i + 1])  i++;

    }

    return result;

}
