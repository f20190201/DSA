string Solution::simplifyPath(string path) {
    vector<string>v;
        int i;
        int n=path.size();
        for(i=0;i<n;i++)
        {
            string x;
            if(path[i]=='/')
                continue;
            else 
            {
                while(i<n&&path[i]!='/')
                    x+=path[i++];
                if(x==".")
                {
                    
                }
                else if(x=="..")
                {
                    if(v.size()>=1)
                    {
                        v.pop_back();
                    }
                }
                else
                {
                    v.push_back(x);
                }
            }
        }
        string ans;
        for(int i=0;i<v.size();i++)
        {
        
            ans+='/';
            ans+=v[i];
        }
        if(ans.size()==0)
            return "/";
        return ans;
    
    

}

------------------------------------------------------------
Time Complexity Failed

string Solution::simplifyPath(string A) {
    stack<string>s;

    // for(int i = 0 ; i < A.size() ; i++)
    //     A[i] = ((A[i] == '/') ? ' ' : A[i]);
    
    stringstream ss(A);
    string word;


    while(getline(ss , word , '/')){
        // cout<<word<<endl;
        if(word == "." or !word.size())
            continue;

        if(word == ".."){
            if(!s.empty())
                s.pop();
        }

        else
            s.push(word);
    }

    string result = "";

    while(!s.empty()){
        string slash("/");
        // string temp = ;
        result = slash.append(s.top()).append(result);
        s.pop();
    }


    return ((result.size() == 0) ? "/" : result);

}





