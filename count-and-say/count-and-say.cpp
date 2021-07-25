class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)
            return "1";
        
        string s = countAndSay(n - 1);
        string str = "";
        int start = 0 , i = 0 , count = 0;
        
        while(i < s.size()){
            
            while(s[i] == s[start]){
                count++;
                i++;
            }
            str += (to_string(count));
            str += (s[start]);
            
            count = 0;
            start = i;
        }
        
        return str;
    }
};