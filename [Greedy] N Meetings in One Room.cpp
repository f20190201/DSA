// Sort according to increasing end times
// Increase count only if start of current meeting is greater than end of prevois
// Update end as max of end of current and end of previous

int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int , int>> v;
        
        for(int i = 0 ; i < n ; i++)
            v.push_back({end[i] , start[i]});
        
        sort(v.begin() , v.end());
        
        int count = 1 , curr_end = v[0].first;
        
        for(int i = 1 ; i < n ; i++){
            
            if(v[i].second > curr_end){
                count++;
                curr_end = max(curr_end , v[i].first);
            }
            
        }
        
        return count;
    }
