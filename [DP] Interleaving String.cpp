bool interLeaved(string A, string B, string C , int n , int m , int p){
    
    if(!m and !n and !p)
        return 1;
    
    if(p == 0)
        return 0;

    return (C[p - 1] == A[n - 1] and interLeaved(A , B , C , n - 1 , m , p - 1)) or 
                    (C[p - 1] == B[m - 1] and interLeaved(A , B , C , n , m - 1 , p - 1));
}

int Solution::isInterleave(string A, string B, string C) {
    int i = 0 , n = A.size() , j = 0 , m = B.size() , k = 0;
  
    return interLeaved(A , B , C , n , m , C.size());
    
    
}

------------------------------------------------------------------------------------------
  
  #include <iostream>
#include <string.h>
using namespace std;
 
// The main function that
// returns true if C is
// an interleaving of A
// and B, otherwise false.
bool isInterleaved(
    char* A, char* B, char* C)
{
    // Find lengths of the two strings
    int M = strlen(A), N = strlen(B);
 
    // Let us create a 2D table
    // to store solutions of
    // subproblems.  C[i][j] will
    // be true if C[0..i+j-1]
    // is an interleaving of
    // A[0..i-1] and B[0..j-1].
    bool IL[M + 1][N + 1];
 
    // Initialize all values as false.
    memset(IL, 0, sizeof(IL));
 
    // C can be an interleaving of
    // A and B only of the sum
    // of lengths of A & B is equal
    // to the length of C.
    if ((M + N) != strlen(C))
        return false;
 
    // Process all characters of A and B
    for (int i = 0; i <= M; ++i) {
        for (int j = 0; j <= N; ++j) {
            // two empty strings have an
            // empty string as interleaving
            if (i == 0 && j == 0)
                IL[i][j] = true;
 
            // A is empty
            else if (i == 0) {
                if (B[j - 1] == C[j - 1])
                    IL[i][j] = IL[i][j - 1];
            }
 
            // B is empty
            else if (j == 0) {
                if (A[i - 1] == C[i - 1])
                    IL[i][j] = IL[i - 1][j];
            }
 
            // Current character of C matches
            // with current character of A,
            // but doesn't match with current
            // character of B
            else if (
                A[i - 1] == C[i + j - 1]
                && B[j - 1] != C[i + j - 1])
                IL[i][j] = IL[i - 1][j];
 
            // Current character of C matches
            // with current character of B,
            // but doesn't match with current
            // character of A
            else if (
                A[i - 1] != C[i + j - 1]
                && B[j - 1] == C[i + j - 1])
                IL[i][j] = IL[i][j - 1];
 
            // Current character of C matches
            // with that of both A and B
            else if (
                A[i - 1] == C[i + j - 1]
                && B[j - 1] == C[i + j - 1])
                IL[i][j]
                    = (IL[i - 1][j]
                       || IL[i][j - 1]);
        }
    }
 
    return IL[M][N];
}
