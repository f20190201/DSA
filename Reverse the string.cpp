// First remove all the trailing and leading spaces
// Next remove also the middle spaces while looping through the string itself and store the word in vector
// Traverse the vector from the end and append it to the string.

string Solution::solve(string A) {
    int i = 0;
    int k = A.size() - 1;

    while(A[k] == ' ')
        k--;

    while(A[i] == ' ')
        i++;

    vector<string> result;

    for(int j = i ; j <= k ; j++){
        string word = "";
        
        while(A[j] == ' ')
            j++;

        while(j <= k and A[j] != ' '){
            word += A[j];
            j++;
        }
        result.push_back(word);
    }
    string ans = "";

    for(int i = result.size() - 1 ; i >= 0 ; i--){
        ans += result[i];
        ans += ' ';
    }
    return ans.substr(0 , ans.size() - 1);

}
