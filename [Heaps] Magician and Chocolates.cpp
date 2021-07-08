#define M ((int)1e9 + 7)
int Solution::nchoc(int A, vector<int> &B) {
    priority_queue<int> maxHeap;

    for(int i = 0 ; i < B.size() ; i++){
        maxHeap.push(B[i]);
    }
    int ans = 0;

    while(A--){
        
        if(maxHeap.size() == 0)
            return ans;
        
        auto top = maxHeap.top();
        maxHeap.pop();
        ans = (ans%M + top%M) % M;
        maxHeap.push(top / 2);
    }
    return (ans % M);

}
