// Make a boolean initiated which checks if string parsing for a valid number has been initiated or not
// if not initiated, and if the character parsed is other than a digit or + or - , break the loop and return 0
// if not initiated and character parsed is + or - , then make initiated = 1 and move onto next character
// if not initiated and character parsed is a digit, then add it to the num variable

//if initiated and character parsed isn't a digit, break out of the loop, else add the digit to the num variable

int Solution::atoi(const string A) {
    int i = 0;

    int num = 0;
    bool initiated = 0;
    bool negative = 0;

    for(int i = 0 ; i < A.size() ; i++){
        
        if(!initiated){
            if(A[i] == '+'){
                initiated = 1;   
            }
            
            else if((A[i] != '-') and !(A[i] >= '0' and A[i] <= '9'))
                return 0;
            
            else if(A[i] == '-'){
                initiated = 1;
                negative = 1;
            }

            else{
                initiated = 1;
                num = num*10 + (A[i] - '0');
            }
            
        }

        else if(initiated){
            if(A[i] < '0' or A[i] > '9')
                break;
            else{
                if(num < INT_MAX/10)
                    num = num*10 + (A[i] - '0');
                else
                    num = INT_MAX;
            }   
        }

    }
    if(!initiated)
        return 0;
    
    if(negative){
        if(num == 0)
            return 0;
        else if(-num <= -INT_MAX)
            return INT_MIN;
        else
            return -num;
    }

    return num;


}


---------------------------------------------------
  
  
  class Solution {
    public:
        int atoi(const string &str) {
            int sign = 1, base = 0, i = 0;
            while (str[i] == ' ') { i++; }
            if (str[i] == '-' || str[i] == '+') {
                sign = (str[i++] == '-') ? -1 : 1; 
            }
            while (str[i] >= '0' && str[i] <= '9') {
                if (base >  INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7)) {
                    if (sign == 1) return INT_MAX;
                    else return INT_MIN;
                }
                base  = 10 * base + (str[i++] - '0');
            }
            return base * sign;
        }
};

