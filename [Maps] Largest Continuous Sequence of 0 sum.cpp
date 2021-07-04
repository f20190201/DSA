// We first use maps to store the maxLength of the 0 sum subarray
// We then use 2 pointer approach to find the subarray that comes first

vector<int> Solution::lszero(vector<int> &A) {
    map<int , int>mp;
    int maxLen = 0;
    vector<int> result;
    int sum = 0;

    for(int i = 0 ; i < A.size() ; i++){
        
        sum += A[i];

        if(sum == 0){
            mp[sum] = i;
            maxLen = i + 1;
        }
        
        if(!mp.count(sum))
            mp[sum] = i;
        
        else{
            maxLen = max(maxLen , i - mp[sum]);
        }

    }
    if(!maxLen)
        return {};

    int j = 0 , k = 0 , total = 0;

    while(j < A.size()){
        
        if((j - k + 1) < maxLen){
            total += A[j];
            j++;
            continue;
        }
        
        total += A[j];

        if(total == 0){
            break;
        }
        else{
            total -= A[k];
            k++;
            j++;
        }
    }

    for(int i = k ; i <= j ; i++)
        result.push_back(A[i]);
    
    return result;

}
