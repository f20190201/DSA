class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> NGE(n , -1);
        
        stack<int>s;
        // Create a min stack before reach i = (n - 1)
        // After reaching i = (n - 1), there would already be a min stack waiting
        // At this point, start populating NGE array
        
        for(int i = 2 * n - 1 ; i >= 0 ; i--){
            
            while(!s.empty() && s.top() <= nums[i % n])
                s.pop();
            
            if(i < n){
                
                if(!s.empty())
                    NGE[i] = s.top();
                
            }
            
            s.push(nums[i % n]);
        }
        
        return NGE;
    }
};
