// Keep pushing the elements into the stack till they are lesser than s.top()
// If we encounter an element > s.top(), keep popping till s.top() > A[i]
// Make the latest popped element as the root
// If root > A[i], return 0
// Idea is to find the first element in the right subtree, once we find it, we make sure that we do not find any further lesser elements

int Solution::solve(vector<int> &A) {
    stack<int>s;
    int root = INT_MIN;

    for(int i = 0 ; i < A.size() ; i++){

        while(!s.empty() and s.top() < A[i]){
            root = s.top();
            s.pop();
        }

        if(root > A[i])
            return 0;
        
        s.push(A[i]);
    }

    return 1;

}
