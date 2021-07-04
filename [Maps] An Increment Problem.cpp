// We need to increment the first instance of the current element in a stream.
// When we change the first instance of an element x, the changed element becomes the first instance of x+1 and the current element becomes the new first instance of x
// If we encounter a new element, we push it into the map along with its index.
// Map stores the element as key with its first instance as value
// When we encounter the second instance of x, we first increase the value of its first instance by 1
// We then make the first instance of (x + 1) as the first instance of x
// We then make first instance of x as the current element index

vector<int> Solution::solve(vector<int> &A) {
    map<int , int>mp;
    int N = A.size();
    
    for(int i = 0 ; i < A.size() ; i++){
        
        if(mp.find(A[i]) == mp.end())
            mp[A[i]] = i;

        else{
            A[mp[A[i]]]++;
            
            mp[A[i] + 1] = mp[A[i]];
            
            mp[A[i]] = i;
        }

    }

    return A;
}
