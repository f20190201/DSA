// Nth natural number after removing all numbers containing digit x is representation of N in base x

class Solution{
	public:
    	long long findNth(long long N)
    {
        // code here.
        string ans = "";
        long long rem = 0;
        
        while(N){
            rem = N % 9;
            N = N / 9;
            
            ans += to_string(rem);
        }
        reverse(ans.begin() , ans.end());
        return stoll(ans);
    }
};
