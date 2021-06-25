// It is the count of prime factors of 5 in the factorial of A

int Solution::trailingZeroes(int A) {
    if(!A)
        return 0;
    
    
    float count5 = 0;

    for(int i = 5 ; A / i >= 1 ; i = i * 5){

        count5 += (A / i);
    
    }


    return (count5);


}
