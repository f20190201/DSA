//Check whether given sum is greater than 9*n.
//If it is greater return -1 because maximum achievable sum is 9*n.
//Run a loop n times.
//In each iteration check if sum is greater than 9. Add 9 to final string if sum is greater or add sum.
//Update the sum
//Return the final string. 


string largestNumber(int n, int sum)
    {
        // Your code here
        string result = "";
        
        //int curr_digit = 9;
        
        if(sum >(9*n))
            return "-1";
        
        for(int i = 0 ; i < n ; i++){
            if(sum > 9){
                result += '9';
                sum -= 9;
            }
            
            else{
                result += to_string(sum);
                sum = 0;
            }
        }
        // while(result.size() != n)
        //     result += '0';
        
        return result;
    }
