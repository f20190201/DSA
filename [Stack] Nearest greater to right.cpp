vector<long long> nextLargerElement(vector<long long> arr, int n){
       
        stack<long long>s;
        vector<long long> v(n);
        for(int i = n-1 ; i>=0 ; i-- ){
         
          // We iterate in a reversed manner. The top of the stack conatins the greatest elemnent found till now. If the top of stack < arr[i], we pop it till the 
          //stack is either empty or the top of the stack > arr[i]
            if(s.empty()){
                s.push(arr[i]);
                v[i] = -1;
            }
            
            else if(!s.empty() && s.top() >= arr[i]){
                v[i] = (s.top());
                s.push(arr[i]);
            }
            
            else if(!s.empty() && s.top() <= arr[i]){
                while(!s.empty() && s.top() <= arr[i])
                    s.pop();
                    
                if(s.empty()){
                s.push(arr[i]);
                v[i] = -1;
            }
            
            else{
                v[i] = (s.top());
                s.push(arr[i]);
            }
                    
            }
            
            
                
        }
        // reverse(v.begin() , v.end());
        return v;
    }
