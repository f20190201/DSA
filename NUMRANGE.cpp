// Make a sliding window with i as left pointer and j as right
// Add to sum until sum > C
// If sum > C, initialise sum = 0 and increment i and make j = i
// If sum <= C and >= B increment count
// If right pointer becomes equal to N, then increment i and make j = i

int Solution::numRange(vector<int> &A, int B, int C) {
    #define int long long int

    int i = 0 , j = 0;
    int sum = 0 , count = 0;

    int n = A.size();
    
    if(n == 1){
        if(A[0] >= B && A[0] <= C)
            return 1;
        
        return 0;
    }

    while(i < n){
        if(sum > C){
            sum = 0;
            i++;
            j = i;
        }
        else
            sum += A[j++];
        
        if(sum <= C and sum >= B)
            count++;
        
        if(j == n){
            sum = 0;
            i++;
            j = i;
        }

    }
    
    return count;

}
