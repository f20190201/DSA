// https://www.youtube.com/watch?v=SK2ypa7poKg

#define M 10000003
int Solution::seats(string A) {
   vector<int> pos;

    for(int i = 0 ; i < A.size() ; i++){
        if(A[i] == 'x')
            pos.push_back(i);
    }
    if(!pos.size())
        return 0;

    int mid = pos.size() / 2 , count = 0 , centre = pos[mid];

    for(int i = 0 ; i < pos.size() ; i++){
        count = (count % M) + (abs(pos[i] - (centre - mid + i)) % M);
    }

    return (count%M);
}
