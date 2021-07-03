// Make a deque whose front contains the maximum till now.
// Iterate for the first B elements and pop_back whatever is smaller than current(useless elements)

// For next (N - B) elements, iterate performing the same operations as before, but only after removing elements that are beyond the queue now(old elements)

vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    vector<int> result;
    deque<int>q;

    for(int i = 0 ; i < B ; i++){
        while(!q.empty() and A[q.back()] <= A[i])
            q.pop_back();
        
       q.push_back(i);
        
    }

    result.push_back(A[q.front()]);

    for(int i = B ; i < A.size() ; i++){
        
        while(!q.empty() and q.front() <= (i - B))
            q.pop_front();

        while(!q.empty() and A[q.back()] <= A[i])
            q.pop_back();

        q.push_back(i);

        result.push_back(A[q.front()]);

    }

    return result;

}
