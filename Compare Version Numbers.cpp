// Idea is to create a vector which contains the number between the dots
// Compare respective elements of the two vectors.
// If one of the vector is out of range, consider its element to be "0"

string leadingRemove(string s){
    int i = 0;

    while(i < s.size() and s[i] == '0'){
        i++;
    }
    if(i == s.size())
        return "0";

    return s.substr(i);
}


int Solution::compareVersion(string A, string B) {
    int m = A.size() , n = B.size();

// Replacing dots with spaces so as to use stringstream for easy splitting int vector
  
    for(int i = 0 ; i < m ; i++){
        if(A[i] == '.')
            A[i] = ' ';
    }

    for(int i = 0 ; i < n ; i++){
        if(B[i] == '.')
            B[i] = ' ';
    }

    vector<string> A1 , B1;

    stringstream s1(A);
    stringstream s2(B);
    string word;

    while(s1 >> word){
        A1.push_back(word);
    }
    
    word = "";

    while(s2 >> word)
        B1.push_back(word);

    int i = 0;

    while(i < max(A1.size() , B1.size())){
        string a_comp = (i >= A1.size()) ? "0" : A1[i];
        string b_comp = (i >= B1.size()) ? "0" : B1[i];

        a_comp = leadingRemove(a_comp);
        b_comp = leadingRemove(b_comp);

        if(a_comp.size() > b_comp.size())
            return 1;
        if(a_comp.size() < b_comp.size())
            return -1;

        if(a_comp < b_comp)
            return -1;
        else if(a_comp > b_comp)
            return 1;

        i++;
    }
    return 0;

}
