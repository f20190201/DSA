class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& A, int target) {
        
        vector<vector<int>> result;
        
        sort(A.begin() , A.end());
        
        for(int i = 0 ; i < A.size() - 1 ; i++){
            int t1 = target - A[i];
            
            for(int j = i + 1 ; j < A.size() - 1 ; j++){
                int t2 = t1 - A[j];
                
                int low = j + 1 , high = A.size() - 1;
                
                while(low < high){
                    int sum = A[low] + A[high];
                    
                    if(sum > t2)
                        high--;
                    
                    else if (sum < t2)
                        low++;
                    
                    else{
                        vector<int> quad(4);
                        quad[0] = A[i];
                        quad[1] = A[j];
                        quad[2] = A[low];
                        quad[3] = A[high];
                        
                        result.push_back(quad);
                        
                        while(low < A.size() && A[low] == quad[2])
                            low++;
                        
                        while(high < A.size() && A[high] == quad[3])
                            high--;
                    }
                }
                
                while(j < A.size() - 1 && A[j] == A[j + 1])
                    j++;
            }
            while(i < A.size() - 1 && A[i] == A[i + 1])
                    i++;
            
        }
        return result;
    }
};