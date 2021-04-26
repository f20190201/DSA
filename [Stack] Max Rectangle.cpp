int MaxArea(vector<int>arr , int n){
    
    stack<pair<int , int>>s;  //The top of this stack stores the left nearest smaller number. In case it doesn't, we pop it till it does. 
    vector<int>leftMin;             //Vector to store Left Nearest smaller number
    
    for(int i = 0; i<n; i++){
      
      if(s.empty()){
            s.push({arr[i] , i});           //if stack is empty, push the number
          leftMin.push_back(-1);            //no left nearest smaller number exists, push -1 into the vector
      }
      
      else if(!s.empty() && s.top().first < arr[i]){
            leftMin.push_back(s.top().second);        //if stack.top() < number , s.top() is the left nearest smaller number
          s.push({arr[i] , i});                       
      }
      
      else if(!s.empty() && s.top().first >= arr[i]){
       
        while(!s.empty() && s.top().first >= arr[i])    //if stack.top() > number, pop numbers until it becomes empty or a lesser number is found.
            s.pop();
    
      if(s.empty()){
            s.push({arr[i] , i});
          leftMin.push_back(-1);
      }
      
      else{
            leftMin.push_back(s.top().second);
            s.push({arr[i] , i});
      }
      
    }}
    
    vector<int> rightMin;             //Vector to store the right nearest smaller number
    stack<pair<int , int>> s1;  //The top of this stack stores the right nearest smaller number. In case it doesn't, we pop it till it does.
    
    for(int i = n-1; i>=0; i--){
      
      if(s1.empty()){
            s1.push({arr[i] , i});
          rightMin.push_back(n);
      }
      
      if(!s1.empty() && s1.top().first < arr[i]){
            rightMin.push_back(s1.top().second);
            s1.push({arr[i] , i});
      }
      
      else if(!s1.empty() && s1.top().first >= arr[i]){
       
        while(!s1.empty() && s1.top().first >= arr[i])
            s1.pop();
    
      if(s1.empty()){
            s1.push({arr[i] , i});
          rightMin.push_back(n);
      }
      
      else{
            rightMin.push_back(s1.top().second);
            s1.push({arr[i] , i});
      }
      
    }
      
    }
    
    reverse(rightMin.begin() , rightMin.end());
    
    int result = INT_MIN;
    
    for(int i = 0; i<n ; i++){
        int area = (rightMin[i] - leftMin[i] - 1)*arr[i];
        result = max(area , result);
    }
    
    
    return result;
}


class Solution{
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        // It creates a histogram of each row in the @d matrix and computes the area of that histogram. Max of these over all rows is taken.
        int ans = INT_MIN;
        
        
        vector<int> histogram;
        for(int i = 0; i<m ; i++)
            histogram.push_back(M[0][i]);
            
            ans = MaxArea(histogram , m);
            //If the matrix entry is 0, make the histogram building height 0. If it is 1, add 1 to the existing histogram building height.
        for(int rows = 1; rows<n ; rows++){
            for(int cols = 0; cols<m ; cols++){
                if(M[rows][cols])
                    histogram[cols] += M[rows][cols];
                else
                    histogram[cols] = 0;
            }
            int arrr = MaxArea(histogram , m);
            ans = max(arrr,ans);
        }
        
    return ans;
    }
