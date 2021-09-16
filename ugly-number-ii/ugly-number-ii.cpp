class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>v;
        
        v.push_back(1);
        
        int i2 = 0 , i3 = 0 , i5 = 0;
        
        for(int i = 1 ; i < n ; i++){
            int minVal = min({2 * v[i2] , 3 * v[i3] , 5 * v[i5]});
            
            v.push_back(minVal);
            
            if(minVal == 2*v[i2])
                i2++;
            
            if(minVal == 3*v[i3])
                i3++;
            
            if(minVal == 5*v[i5])
                i5++;
        }
        for(auto x : v)
            cout<<x<<" ";
        return v.back();
    }
};