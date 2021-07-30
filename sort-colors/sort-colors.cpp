class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0 , blue = nums.size() - 1;
        
        if(nums.size() == 1)
            return;
        
        for(int i = 0 ; i <= blue ; i++){
            
            if(nums[i] == 0){
                swap(nums[red] , nums[i]);
                red++;
            }
            
            else if(nums[i] == 2){
                
                swap(nums[i] , nums[blue]);
                blue--;
                i--;
            }
        }
        
        return;
    }
};

-----------------------------------------------------------------------------------------------------------------------------

void sortColors(int A[], int n) {
    int num0 = 0, num1 = 0, num2 = 0;
    
    for(int i = 0; i < n; i++) {
        if (A[i] == 0) ++num0;
        else if (A[i] == 1) ++num1;
        else if (A[i] == 2) ++num2;
    }
    
    for(int i = 0; i < num0; ++i) A[i] = 0;
    for(int i = 0; i < num1; ++i) A[num0+i] = 1;
    for(int i = 0; i < num2; ++i) A[num0+num1+i] = 2;
}
