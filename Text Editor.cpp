// Idea is to find a '-' preceded by a '<' , if this condition suffices, we pop the last 2 elements(if exist) from the new string

// https://binarysearch.com/problems/Text-Editor

string solve(string s) {
    if(s.size() == 0)
        return s;
    
    string res = "";

    res.push_back(s[0]);

    for(int i = 1 ; i < s.size() ; i++){
        if(s[i] != '-'){
            res.push_back(s[i]);
            continue;
        }

        if(s[i - 1] == '<'){
            res.pop_back();

            if(res.size())
                res.pop_back();
        }
        else
            res.push_back(s[i]);
    }

    return res;
}
