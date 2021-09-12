// https://www.youtube.com/watch?v=9mod_xRB-O0

static bool comp(pair< pair<int , int> , int> &a , pair< pair<int , int> , int> &b){
        int aa = a.first.first * a.first.second , bb = b.first.first * b.first.second;
        
        return (aa >= bb);
    }
    
    int maxHeight(int h[],int w[],int l[],int n)
    {
        vector<pair<pair<int , int> , int>> sizes;
        
        for(int i = 0 ; i < n ; i++){
            sizes.push_back({{max(h[i] , w[i]) , min(h[i] , w[i])} , l[i]});
            sizes.push_back({{max(w[i] , l[i]) , min(l[i] , w[i])} , h[i]});
            sizes.push_back({{max(h[i] , l[i]) , min(l[i] , h[i])} , w[i]});
        }
        
        sort(sizes.begin() , sizes.end() , comp);
        
        vector<int>maxH(3*n);
        int ans = 0;
        
        for(int i = 0 ; i < 3*n ; i++)
            maxH[i] = sizes[i].second;
        
        for(int i = 0 ; i < 3*n ; i++){
            
            int length = sizes[i].first.first , width = sizes[i].first.second , height = sizes[i].second;
            
            for(int j = 0 ; j <= i ; j++){
                
                int curr_l = sizes[j].first.first , curr_w = sizes[j].first.second;
                
                if(curr_l > length && curr_w > width && (maxH[i] < maxH[j] + height))
                    maxH[i] = maxH[j] + height;
                    
            }
        }
        
        for(int i = 0 ; i < 3*n ; i++)
            ans = max(ans, maxH[i]);
        
        return ans;
    }
