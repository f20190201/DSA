// Count the number of words and total length of all words in the given vector
// Make all substrings of required length and compare each patch of word length with word count in the map.
// To account for duplicates and multiple occurences, we make a temporary map, same as general map.
// If a patch isn't found in original map or count of it in temp map is 0, we break out of the loop
// If a patch is found, we reduce the count in temp map and increment the word counter.
// If word counter == number of words in vector, then the string is an answer.

vector<int> Solution::findSubstring(string A, const vector<string> &B) {
    int word_length = B[0].size() , N = B.size();
    int characters = N * word_length;

    if(characters > A.size())
        return {};

    vector<int> result;

    map<string , int>mp;

    for(auto x : B)
        mp[x]++;

    for(int i = 0 ; i < A.size() - characters + 1 ; i++){
        
        map<string , int> temp = mp;
        int count = 0; 

        for(int j = 0 ; j < characters ; j += word_length){
            string s = A.substr(i + j , word_length);
            
            if(!mp.count(s) or temp[s] == 0)
                break;

            else{
                temp[s]--;
                count++;
            }
                
        }
        
        if(count == N){
            result.push_back(i);
        }

    }


    return result;
}
