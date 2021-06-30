// For 3 color, we run the loop 3 times
// In each loop, we sort the color with the current lowest priority

void Solution::sortColors(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int index = 0 , n = A.size();
    // For red
    for(int i = 0 ; i < n ; i++){
        if(A[i] == 0){
            swap(A[index] , A[i]);
            index++;
        }
    }

    for(int i = 0 ; i < n ; i++){
        if(A[i] == 1){
            swap(A[index] , A[i]);
            index++;
        }
    }

    for(int i = 0 ; i < n ; i++){
        if(A[i] == 2){
            swap(A[index] , A[i]);
            index++;
        }
    }
    return;

}

----------------------------------------------------
  
  
 void Solution::sortColors(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int red =0, blue =A.size()-1, color = 0;
    while(color <= blue)//we arrange 0's and 2's, 1's will already be in place
    {
        if(A[color]==0)
        {
            swap(A[red++],A[color++]);
        }
        else if(A[color]==2)
        {
            swap(A[blue--],A[color]);
        }
        else
        {
            color++;
        }
    }
}
