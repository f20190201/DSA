// We make a prefix array that contains cumulative XOR of all elements till that point
// We find B^prefix[i] in the map, if exists, we add its count t the answer
// If prefix[i] itself is B, we add 1 to result
// In all cases, we increment count of prefix[i]

int Solution::solve(vector<int> &A, int B) {

vector<int> prefix(A.size());

prefix[0] = A[0];

for(int i = 1 ; i < A.size() ; i++){
    prefix[i] = A[i]^prefix[i - 1];
}

map<int , int> mp;
int result = 0;

for(int i = 0 ; i < A.size() ; i++){
    
    mp[prefix[i]]++;
    
    if(mp.find(prefix[i]^B) != mp.end())
        result += mp[prefix[i]^B];

    if(prefix[i] == B)
        result++;

}
return result;

}
