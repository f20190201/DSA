//Given a set of distinct integers, S, return all possible subsets.

//Note:

//Elements in a subset must be in non-descending order.
//The solution set must not contain duplicate subsets.
//Also, the subsets should be sorted in ascending ( lexicographic ) order.
//The list is not necessarily sorted.


void backtrack(vector<int> &A , int index ,vector<vector<int>> &ans , vector<int> &temp){

    ans.push_back(temp);

    for(int i=index;i<A.size();i++){

    temp.push_back(A[i]);

    backtrack(A,i+1,ans,temp);

    temp.pop_back();

    }

}


vector<vector<int> > Solution::subsets(vector<int> &A) {
   
    vector<vector<int>> ans;

    vector<int> temp;

    sort(A.begin(),A.end());

    backtrack(A,0,ans,temp);

    return ans;
}
