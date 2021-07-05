// Iterate for each point and check every other point that lies on the same line
// Take care of same points specially. Declare a different variable to keep count of same points

int Solution::maxPoints(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(!A.size())
        return 0;

    map<pair<int , int> , int>mp;
    int N = A.size() , maxPoints = 0;

    for(int i = 0 ; i < N ; i++){
        int x1 = A[i] , y1 = B[i];

        int localMax = 0 , same = 1;

        for(int j = i + 1 ; j < N ; j++){
            int x2 = A[j] , y2 = B[j];

            int diffX = x1 - x2 , diffY = y1 - y2;

            
            if(!diffX and !diffY){
                same++;
                continue;
            }

            int HCF = __gcd(diffX , diffY);

            mp[{diffX / HCF , diffY / HCF}]++;

            localMax = max(localMax , mp[{diffX / HCF , diffY / HCF}]);

        }
        
        localMax += same; 
        
        maxPoints = max(localMax , maxPoints);
        mp.clear();

    }
    return maxPoints;
}
