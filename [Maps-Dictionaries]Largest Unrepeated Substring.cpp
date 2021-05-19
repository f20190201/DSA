// The idea is to have a dictionary which contains the position of the last repeated occurence of each character.
// If the position of last repeated occurence is > start, then the repeated character is in the substring under investigation.
// In that case, we update start to the last repeated occurence, so as to include only a single occurence of it.

int LargestSubstring(string s){
    vector<int> dict(256 , -1);
    int start = 0;
    int answer = 0;
    for(int i = 0 ; i < s.size() ; i++){
        if(dict[s[i]] > start)
            start = dict[s[i]];
        dict[s[i]] = i;
        answer = max(answer , i - start);
    }
 return answer;   
} 
