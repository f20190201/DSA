int Solution::sqrt(int A) {
    long long prev;
    long long i = A;
    while(i*i > A){
        prev = i;
        i /= 2;
    }
    // cout<<i<<"  "<<prev<<endl;
    if(i*i == A)
        return i;

    for(long long j = i ; j <= prev ; j++){
        if(j*j <= A and (j+1)*(j+1) > A)
            return j;
    }

}

--------------------------------------------------------------------
  
  
  Note: r * r will overflow if not done carefully. So instead, we eliminate the multiplcation and resort to a little bit of division.

Refer to the following solution:

class Solution {
    public:
        int sqrt(int x) {
            if (x == 0) return 0;
            int start = 1, end = x, ans;
            while (start <= end) {
                int mid = (start + end) / 2;
                if (mid <= x / mid) {
                    start = mid + 1;
                    ans = mid;
                } else {
                    end = mid - 1;
                }
            }
            return ans;
        }
};
