// Set 2 pointers i and j
// Loop them until one of them reaches its end
// If A[i] < B[j], advance i and vice versa
// If both are equal, append the value to result vector and advance both

vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
    vector<int> result;

    int i = 0 , j = 0;

    while(i < A.size() and j < B.size()){
        if(A[i] == B[j]){
            result.push_back(A[i]);
            i++;
            j++;
        }
        else if(A[i] < B[j])
            i++;
        
        else 
            j++;

    }
    
    return result;

}
