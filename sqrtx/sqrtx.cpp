public int sqrt(int x) {
    if (x == 0)
        return 0;
    int left = 1, right = Integer.MAX_VALUE;
    while (true) {
        int mid = left + (right - left)/2;
        if (mid > x/mid) {
            right = mid - 1;
        } else {
            if (mid + 1 > x/(mid + 1))
                return mid;
            left = mid + 1;
        }
    }
}

------------------------------------------------------------------------------------

class Solution {
public:
    int mySqrt(int x) {
        
        for(long long i = 0 ; i <= x ; i++){
            if(i * i == x)
                return i;
            
            else if(i * i > x)
                return i - 1;
        }
        return -1;
    }
};
