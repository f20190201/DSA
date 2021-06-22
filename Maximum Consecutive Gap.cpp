//Make buckets of average interval length and compare the max_val of one bucket to min_val of next bucket
// Interval length = (max_el - min_el) / (n-1)
// No. of buckets = (n-1)
// Magic formula for calculating in which bucket the element will fall = (num - min)/(interval length)
// Make 2 buckets(vectors) - one for storing max of that particular range and other for storing min of that particular range
// We do not put max_el or min_el into the buckets
// We make a variable prev that stores the max of the previous NOT EMPTY bucket.


int Solution::maximumGap(const vector<int> &A) {
    if(A.size() < 2)
        return 0;
    int n = A.size();
    int max_el = INT_MIN , min_el = INT_MAX;
    

    for(int i = 0 ; i < n ; i++){
        max_el = max(A[i] , max_el);
        min_el = min(A[i] , min_el);
    }
    
    

    int interval = ceil((float)(max_el - min_el)/(float)(n-1));

    vector<int>bucketMax(n-1 , INT_MIN);
    vector<int>bucketMin(n-1 , INT_MAX);

    for(int i = 0 ; i < n ; i++){
        if(A[i] == max_el or A[i] == min_el) continue;
        
        int bucketNum = (A[i] - min_el)/interval;

        bucketMax[bucketNum] = max(A[i] , bucketMax[bucketNum]);
        bucketMin[bucketNum] = min(A[i] , bucketMin[bucketNum]);

    }
    int prev = min_el;
    int ans = 0;

    for(int i = 0 ; i < bucketMin.size() ; i++){
        if(bucketMax[i] == INT_MIN) continue;

        ans = max(ans , bucketMin[i] - prev);

        prev = bucketMax[i];

    }

    ans = max(ans , max_el - prev);

    return ans;
    

}
