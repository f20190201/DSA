// Use a vector of pairs to store the start and end index of portions between tags
// For overlap, check if the ending of the latest set is more than or equal to start of current, if yes, then only update the ending of latest
// If no overlap, add a new pair

//https://binarysearch.com/problems/Embolden/solutions/3225892

string solve(string text, vector<string>& patterns) {
    int n = text.size();
    vector<pair<int , int>>v;

    for(int i = 0 ; i < n ; i++){
        for(auto word : patterns){

            if(word.size() <= (n - i) && (text.compare(i , word.size() , word) == 0)){
                if(v.size() == 0){
                    v.push_back({i , i + word.size() - 1});    
                }
                else{
                    if(v.back().second >= (i - 1)){
                        v.back().second = (i + word.size() - 1);
                    }
                    else
                        v.push_back({i , i + word.size() - 1});
                }
            }

        }
    }
    string ans = "";
    int index = 0;

    for(int i = 0 ; i < v.size() ; i++){
        ans += text.substr(index , v[i].first - index);
        
        ans += "<b>";

        ans += text.substr(v[i].first , v[i].second - v[i].first + 1);

        ans += "</b>";

        index = v[i].second + 1;

    }

    if(index < n)
        ans += text.substr(index);
    
    return ans;
}
