vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
    int rows = A.size();
    int cols = A[0].size();
    if(rows == 1 and cols == 1)
        return{A[0][0]};

    int rightrow = 0; // pointer which prints a row from left to right
    int bottomcolumn = cols-1; // pointer which prints a column from top to bottom
    int leftrow = rows-1; // pointer which prints a row from right to left
    int topcolumn = 0; // pointer which prints a column from bottom to top
    vector<int>result;

    char flag = 'r'; // flag that keeps a track of which pointer to be executed next

    while(rightrow <= leftrow and bottomcolumn >= topcolumn){
        if(flag == 'r'){
            for(int i = topcolumn ; i <= bottomcolumn ; i++)
                result.push_back(A[rightrow][i]);
            rightrow++;
            flag = 'b';
        }

        else if(flag == 'b'){
            for(int i = rightrow ; i <= leftrow ; i++)
                result.push_back(A[i][bottomcolumn]);
            bottomcolumn--;
            flag = 'l';
        }

        else if(flag == 'l'){
            for(int i = bottomcolumn ; i >= topcolumn ; i--)
                result.push_back(A[leftrow][i]);
            leftrow--;
            flag = 't';
        }

        if(flag == 't'){
            for(int i = leftrow ; i >= rightrow ; i--)
                result.push_back(A[i][topcolumn]);
            topcolumn++;
            flag = 'r';
        }
    }
    return result;


}
