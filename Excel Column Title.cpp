string Solution::convertToTitle(int A) {
    string result = "";
    if(A == 1)
        return "A";
    while(A){
        // cout<<char(((A%26) == 0 ? 26 : (A%26)) + 64)<<"\t";
        result += char((A-1)%26 + 65);
        A = (A - 1) / 26;
        
    }
    reverse(result.begin() , result.end());
    return result;

}
