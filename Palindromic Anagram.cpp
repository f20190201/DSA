// A palindrome has to have all characters in even frequency except at most one character with odd frequency

// https://binarysearch.com/problems/Palindromic-Anagram

bool solve(string s) {
    unordered_map<char , int> mp;

    int n = s.size();

    for(int i = 0 ; i < n ; i++){
        mp[s[i]]++;
    }
    
    int oddCount = 0;

    for(auto it = mp.begin() ; it != mp.end() ; ++it){
    
        if(it->second % 2)
            oddCount++;    
    }

    if(oddCount >= 2)
        return 0;
    
    return 1;
}
