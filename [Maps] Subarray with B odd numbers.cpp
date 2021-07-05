// Make a prefix array or a map that contains the number of odd elements till that points. Check for B - number_of_odd_elements in the array and add to ans.

int Solution::solve(vector<int> &A, int B) {
    map<int , int>mp;
    int ans = 0 , num = 0;

    for(int i = 0 ; i < A.size() ; i++){
        num += (A[i] % 2 != 0);

        if(num == B)
            ans++;
        // mp[count] = i;
        if(mp.count(num - B)){
                ans += mp[num - B];
        }
        mp[num]++;
        
    }
    return ans;


}
