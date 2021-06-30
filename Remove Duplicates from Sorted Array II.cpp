// This is when an element can occur at most 2 times

int index = 0 , n = A.size();

    for(int i = 0 ; i < n ; i++){
        
        if(i < n - 2 and (A[i] == A[i+2]))
            continue;
        
        else{
            A[index] = A[i];
            index++;
        }
    }
    return index;

}

--------------------------------------------
  // This is when an element can occur at most B times

int index = 0 , n = A.size();

    for(int i = 0 ; i < n ; i++){
        
        if(i < n - B and (A[i] == A[i+B]))
            continue;
        
        else{
            A[index] = A[i];
            index++;
        }
    }
    return index;

}
