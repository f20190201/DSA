int Solution::bulbs(vector<int> &A) {

    int count = 0 , state = 0;

    for(int i = 0 ; i < A.size() ; i++){
        
        if(A[i]){

            if(state == 1){
            
                count++;
                state  = 0;

            }
        }

        else{

            if(state == 0){
            
                count++;
                state = 1;
                
            }
        }

    }
    return count;

}
