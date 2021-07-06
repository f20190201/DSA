// All n bit gray codes can be achieved by first appending "0" to n-1 bit gray codes and then "1" to n-1 bit gray codes and then reversing one and concatenating

vector<string> greyCode(int A){
    if(A == 1)
        return {"0" , "1"};
    
    vector<string> temp = greyCode(A - 1);

    vector<string> result;

    for(int i = 0 ; i < temp.size() ; i++)
        result.push_back('0' + temp[i]);
    
    for(int i = temp.size() - 1 ; i >= 0 ; i--)
        result.push_back('1' + temp[i]);

    return result;


}

vector<int> Solution::grayCode(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<string> temp = greyCode(A);

    vector<int> result;

    for(auto x: temp)
        result.push_back(stoi(x , 0 , 2));

    return result;


}


-------------------------------------------------------------------
  
  vector<int>ans;
    long long x = pow(2 , A) , i;

    for(i=0 ; i < x ; i++)
        {
        int j = i/2;
        ans.push_back(i^j);
        }

    return ans;
