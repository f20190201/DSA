class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& dict) {
        
        unordered_map<string , int> mp;
        
        for(auto word : dict)
            mp[word]++;
        
        queue<string>q;
        q.push(beginWord);
        
        int ans = 1;
        
        while(!q.empty()){
            int n = q.size();
            
            while(n--){
                string word = q.front();
                q.pop();
                
                if(word == endWord)
                    return ans;
                
                mp.erase(word);
                
                //check for each one - letter change in word
                
                for(int i = 0 ; i < word.size() ; i++){
                    char c = word[i];
                    
                    for(int j = 0 ; j < 26 ; j++){
                        word[i] = 'a' + j;
                        
                        if(mp.count(word))
                            q.push(word);
                    }
                    word[i] = c;
                }
            }
            
            ans++;
        }
        
        return 0;
        
    }
};