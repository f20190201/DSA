int to_int(string A){
    int ans = 0;
    int mul = 1;

    for(int i = 31 ; i >= 0 ; i--){
        ans += mul*(A[i] - '0');
        mul *= 2;
    }
    return ans;

}

string to_binary(unsigned int A){
    string ans = "";

    while(A){
        ans = to_string(A % 2) + ans;
        A = A / 2;
    }

    while(ans.size() != 32){
        ans = '0' + ans;
    }

    return ans;
}


unsigned int Solution::reverse(unsigned int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    string B = to_binary(A);

    string C = "";

    int i = 31;

    while(i >= 0){
        C += B[i];
        i--;
    }

    int result = to_int(C);

    return result;
    


}

----------------------------------------------------------------------------
  
  unsigned int Solution::reverse(unsigned int A) {
    unsigned int B = 0; //B will hold the reversed number
    for(int i=0;i<32;i++){  //Iterating on all bit positions
        int k = A & 1;      //Extracting the rightmost bit from A (the ith bit in original number)
        B <<= 1;            //Shifting B to left (rightmost bit becomes 0)
        B |= k;             //Adding the extracted bit
        A >>= 1;            //Now the (i+1)st bit shifts to the rightmost position in A
    }
    return B;
}

