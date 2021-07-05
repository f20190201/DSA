string Solution::minWindow(string A, string B) {
    map<char , int>mp_pattern;
    map<char , int>mp_string;

    int N = A.size();

    for(int i = 0 ; i < B.size() ; i++){
        mp_pattern[B[i]]++;
    }

    int start_index = -1 , start = 0 , minLen = INT_MAX , count = 0;

    for(int i = 0 ; i < A.size() ; i++){
        mp_string[A[i]]++;

        if(mp_string[A[i]] <= mp_pattern[A[i]])
            count++;
        
        if(count == B.size()){
            
            while(mp_string[A[start]] > mp_pattern[A[start]] or mp_pattern[A[start]] == 0){
            
                if(mp_string[A[start]] > mp_pattern[A[start]])
                    mp_string[A[start]]--;
                    start++;
            }

            if(i - start + 1 < minLen){
                minLen = i - start + 1;
                start_index = start;
            }

        }

    }

    if(start_index == -1)
        return "";
    return A.substr(start_index , minLen);



}
