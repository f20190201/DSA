static bool compare(struct Job a , struct Job b){
        return a.profit > b.profit;
    }
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        int tasks = 0 , profit = 0;
        
        sort(arr , arr + n , compare);
        
        bool slots[n] = {0};
        
        for(int i = 0 ; i < n ; i++){
            int j = min(arr[i].dead , n);
            
            if(slots[j-1] == 0){
                slots[j-1] = 1;
                profit += arr[i].profit;
                tasks++;
                continue;
            }
            
            else{
                j--;
            while(slots[j] != 0 && (j >= 0))
                j--;
            if(j == -1)
                continue;
            else{
                slots[j] = 1;
                profit += arr[i].profit;
                tasks++;
            }
                
            }
            
        }
        return {tasks,profit};
        
    } 
