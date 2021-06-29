Validate if a given string is numeric.

Examples:

"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Return 0 / 1 ( 0 for false, 1 for true ) for this problem

Clarify the question using “See Expected Output”

Is 1u ( which may be a representation for unsigned integers valid?    For this problem, no.

Is 0.1e10 valid?      Yes

-01.1e-10?    Yes

Hexadecimal numbers like 0xFF?      Not for the purpose of this problem

3. (. not followed by a digit)?     No

Can exponent have decimal numbers? 3e0.1?     Not for this problem.

Is 1f ( floating point number with f as prefix ) valid?     Not for this problem.

How about 1000LL or 1000L ( C++ representation for long and long long numbers )?      Not for this problem.

How about integers preceded by 00 or 0? like 008?       Yes for this problem

       

int Solution::isNumber(const string A) {
    // if it is e, it must be followed by an integer
    // if x, invalid
    //if f, invalid
    //if L, invalid
    //
    int i = 0;
    while(A[i] == ' ')
        i++;
    
    if(i == A.size())
        return 0;

    int k = A.size() - 1;

    while(A[k] == ' ')
        k--;

    bool e_found = 0;

    for( ; i <= k ; i++){
        
        if(e_found and A[i] == '.')
            return 0;
        
        if(!isalnum(A[i])){
            //default return 0
            if(A[i] == '-'){
                if(!i)
                    continue;
                
                if(A[i - 1] == 'e')
                    continue;
            }
            if(A[i] == '.'){
                if((i != k) and (A[i + 1] >= '0' and A[i + 1] <= '9'))
                    continue;
                return 0;
            }
            else
                return 0;
        }

        if(isalnum(A[i])){
            if(A[i] == 'e')
                e_found = 1;
            
            if(A[i] == 'e' and (i == k))
                return 0;
            
            if(A[i] >= 'A' and A[i] <= 'Z')
                return 0;
            
            if((A[i] >= 'a' and A[i] <= 'z') and (A[i] != 'e'))
                return 0;
            
        }

    }
    return 1;

}
