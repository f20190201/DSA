class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //string::npos
            
        if(!strs.size())
            return "";
        
        string result = strs[0];
        
        for(int i = 1 ; i < strs.size() ; i++){
            while(strs[i].find(result) != 0){
                if(result == "")
                    return "";
                result = result.substr(0 , result.size() - 1);
                
            }
            
        }
        return result;
    }
};