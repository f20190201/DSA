class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& A, int target) {
        vector<vector<int>> result;
        
        sort(A.begin() , A.end());
        
        for(int i = 0 ; i < A.size() ; i++){
            int t1 = target - A[i];
            
            for(int j = i + 1 ; j < A.size() ; j++){
                int t2 = t1 - A[j];
                
                int l = j + 1 , r = A.size() - 1;
                
                while(l < r){
                    int sum = A[l] + A[r];
                    
                    if(sum > t2)
                        r--;
                    else if(sum < t2)
                        l++;
                    
                    else{
                        vector<int> temp(4);
                        temp[0] = A[i];
                        temp[1] = A[j];
                        temp[2] = A[l];
                        temp[3] = A[r];
                        result.push_back(temp);
                        
                        while(l < r and A[l] == temp[2])
                            l++;
                        while(l < r and A[r] == temp[3])
                            r--;
                    }
                        
                }
                while(j + 1 < A.size() and A[j] == A[j + 1])
                    j++;
            }
            
            while(i + 1 < A.size() and A[i] == A[i + 1])
                i++;
        }
        return result;
    }
};