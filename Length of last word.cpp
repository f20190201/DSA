int Solution::lengthOfLastWord(const string A) {
    stringstream s(A);
    string word;
    string result;

    while(s >> word){
        result = word;
    }
    
    return result.size();
    
}

----------------------------------------------------------------------------
  
  int Solution::lengthOfLastWord(const string A) {
    
    int cnt=0;
    int i=A.length()-1;
  
    while(A[i] == ' ') //looping from last and encountering a first alphanumeric character
        i--;
        
    for( ; i >= 0 && A[i] != ' ' ; i--) //from that point to the first space encountered
        cnt++;
    
    return cnt;
    

}
