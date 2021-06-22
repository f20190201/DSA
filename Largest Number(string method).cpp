// Make a comparator function that appends one string to other and compares
// It returns whichever is the smallest/largest

bool comp(string s1 , string s2){
    string s1s2 = s1.append(s2);
    string s2s1 = s2.append(s1);

    return (s1s2 > s2s1) ? 0 : 1;
}

string Solution::largestNumber(const vector<int> &A) {
    vector<string> v;
    string result = "";
    for(auto x: A)
        v.push_back(to_string(x));
    
    sort(v.begin(), v.end() , comp);

    for(int i = v.size() - 1 ; i >= 0 ; i--)
        result+=v[i];
    bool flag = 0;

 // If all elements are 0 then resturn only one 0
    for(char s : result){
        if(s != '0')
            flag = 1;
    }

    if(!flag)
        return "0";
   
    return result;
}
