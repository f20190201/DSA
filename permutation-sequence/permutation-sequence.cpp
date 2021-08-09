class Solution {
public:
    string res;
    
    int fact(int n){
        int prod = 1;
        
        for(int i = 1 ; i <= n ; i++)
            prod = prod * i;
        
        return prod;
    }
    
    void solve(vector<char> &v , int n , int k){
        
        if(n == 0)
            return;
        
        int factN = fact(n - 1);
        int index = k / factN;
        
        res.push_back(v[index]);
        
        v.erase(v.begin() + index);
        
        solve(v , n - 1 , k % factN);
        
        return;
    }
    
    string getPermutation(int n, int k) {
        res = "";
        
        k = k - 1;    
        
        vector<char>v;
        
        for(char c = '1' ; c <= '9' ; c++)
            v.push_back(c);
        
        solve(v , n , k);
        
        return res;
    }
};