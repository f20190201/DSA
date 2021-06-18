class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return 0;
        string num = to_string(x);
        string rev = num;
        ::reverse(rev.begin() , rev.end());
        int newnum = stoll(rev);
        
        if(newnum == x)
            return 1;
        
        return 0;
        
    }
};