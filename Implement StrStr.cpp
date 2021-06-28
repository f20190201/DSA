int Solution::strStr(const string A, const string B) {
   
    if(!A.size() or !B.size())
        return -1;
    if(B.size() > A.size())
        strStr(B , A);  
    
    int ptrA = 0 , ptrB = 0;

    for( ; ptrA < A.size() ; ptrA++){
        
        if(ptrB == B.size())
            break;
        
        if(A[ptrA] == B[ptrB])
            ptrB++;
        
        else{
            if(ptrB > 0)
                ptrA = ptrA - ptrB;
            ptrB = 0;
        }
            
    }

    if(ptrB < B.size())
        return -1;
    return
        ptrA - ptrB;

}

// The normal method would also work
