// According to the rules of Sudoku, check for each row, column and box is they are valid by iterating

bool isValidRow(const vector<string> &A){
    int rows = A.size();
    int cols = A[0].size();
    map<char , int>mp;

    for(int i = 0 ; i < rows ; i++){
        
        for(int j = 0 ; j < cols ; j++){
            
            if(A[i][j] == '.')
                continue;

            if(!mp.count(A[i][j]))
                mp[A[i][j]]++;
            
            else
                return 0;
        }
        mp.clear();

    }

    return 1;

}

bool isValidColumn(const vector<string> &A){
    int rows = A.size();
    int cols = A[0].size();
    map<char , int>mp;

    for(int i = 0 ; i < cols ; i++){
        
        for(int j = 0 ; j < rows ; j++){
            
            if(A[j][i] == '.')
                continue;

            if(!mp.count(A[j][i]))
                mp[A[j][i]]++;
            
            else
                return 0;
        }
        mp.clear();

    }

    return 1;

}

bool isValidBox(const vector<string> &A){
    int rows = A.size();
    int cols = A[0].size();
    map<char , int>mp;

    for(int i = 0 ; i < rows ; i += 3){
        
        for(int j = 0 ; j < cols ; j += 3){
            
            for(int k = 0 ; k < 3 ; k++){
                for(int l = 0 ; l < 3 ; l++){
                    if(A[i + k][j + l] == '.')
                    continue;

                if(!mp.count(A[i + k][j + l]))
                    mp[A[i + k][j + l]]++;
            
                else
                    return 0;
                }
            }
            mp.clear();
        }

    }

    return 1;

}

int Solution::isValidSudoku(const vector<string> &A) {

    return (isValidBox(A) and isValidColumn(A) and isValidRow(A));

}
