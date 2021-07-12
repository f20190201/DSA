class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n <= 1)
            return n;
        
        vector<int> result(n + 1);
        
        result[1] = 1;
        
        for(int i = 1 ; i <= n ; i++){
            
            if(2 <= 2*i and 2*i <= n)
                result[2*i] = result[i];
            
            if(2 <= (2*i + 1) and (2*i + 1) <= n)
                result[2*i + 1] = result[i] + result[i + 1];
        }
        
        for(auto x : result)
            cout<<x<<" , ";
        cout<<endl;
        
        return *max_element(result.begin() , result.end());
    }
};