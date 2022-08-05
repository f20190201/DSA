class Solution {
public:
    int countDigits(int n){
        
        return floor(1 + log10(n));
        
    }
    
    int generateFirstNum(int digits){
        string s = "";
        
        for(int i = 1 ; i <= digits ; i++)
            s += to_string(i);
        
        return stoi(s);
    }
    
    int generateNextNum(int n){
        string s = to_string(n);
        
        for(int i = 0 ; i < s.size() ; i++)
            s[i] = char(int(s[i]) + 1);
        
        return stoi(s);
    }
    
    vector<int> sequentialDigits(int low, int high) {
        vector<int>result;
        
        int startDigits = countDigits(low) , endDigits = min(countDigits(high) , 9);
        
        int currDigits = startDigits , num = generateFirstNum(currDigits);
        
        while(num <= high){
            
            if(num >= low)
                result.push_back(num);
            
            if(num % 10 == 9){
                if(currDigits < 9)
                    num = generateFirstNum(++currDigits);
                else
                    break;
            }
            
            else
                num = generateNextNum(num);
            
        }
        
        return result;
    }
};