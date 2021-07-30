class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string , vector<int>>mp;
        
        for(int i = 0 ; i < strs.size() ; i++){
            string word = strs[i];
            sort(word.begin() , word.end());
            
           mp[word].push_back(i);
        }
        
        vector<vector<string>> result;
        
        for(auto it = mp.begin() ; it != mp.end() ; ++it){
            vector<string>temp;
            
            for(auto i : it->second)
                temp.push_back(strs[i]);
            
            result.push_back(temp);
        }
        
        return result;
        
    }
};