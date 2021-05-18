int RainWater(int arr[] , int n){
    int answer = 0;
    stack<int> st;
    
    for(int i = 0 ; i < n ; i++){
        while(!st.empty() && arr[st.top()] < arr[i]){
            int current = st.top();
            st.pop();
            
            if(!st.empty()){
                int length = i - st.top() - 1;
                answer += (min(arr[st.top()] , arr[i]) - arr[current]) * length;
            }
            
        }
            
        st.push(i);
    }
    
 return answer;   
} 
