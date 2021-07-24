class Solution {
public:
    map<char , string>mp;
    
    vector<string> letterCombinations(string digits) {
        mp.insert({'2' , "abc"});
        mp.insert({'3' , "def"});
        mp.insert({'4' , "ghi"});
        mp.insert({'5' , "jkl"});
        mp.insert({'6' , "mno"});
        mp.insert({'7' , "pqrs"});
        mp.insert({'8' , "tuv"});
        mp.insert({'9' , "wxyz"});
        
        if(digits.size() == 0)
            return {};
        
        vector<string> result , temp;
        
        if(digits.size() == 1){
        
            for(auto x : mp[digits[0]]){
                string s = "";
                result.push_back(s + x);
            }
            
            return result;
        }
            
        temp = letterCombinations(digits.substr(0 , digits.size() - 1));
        
        char letter = digits[digits.size() - 1];
        
        for(auto x : mp[letter]){
            
            for(auto words : temp){
                result.push_back(words + x);    
            }    
        }
        
        return result;
    }
};