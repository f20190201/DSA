// Make a frequency array that store the count of consecutive ones in that column, in a stream
// Sort the rows of freq array in decreasing order, this is essentially the column swapping process
// Iterate over the freq array and calculate the area - width would be index + 1 and height would be its value

int Solution::solve(vector<vector<int> > &A) {
    int n = A.size() , m = A[0].size();

    int freq[n][m];

    for(int i = 0 ; i < n ; i++){       
        for(int j = 0 ; j < m ; j++){
            
            if(i == 0){
                freq[i][j] = A[i][j];
                continue;
            }

            freq[i][j] = (A[i][j] == 0) ? 0 : freq[i - 1][j] + 1;

        }
    }

    for(int i = 0 ; i < n ; i++)
        sort(freq[i] , freq[i] + m , greater<int>());
    
    int res = 0;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){

            res = max(res , (freq[i][j] * (j + 1)));
        }
    }

    return res;

}
