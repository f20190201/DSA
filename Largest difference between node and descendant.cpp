import java.util.*;

/**
 * public class Tree {
 *   int val;
 *   Tree left;
 *   Tree right;
 * }
 */
class Solution {
    int res = 0;
    public int solve(Tree root) {
        if (root == null)
            return 0;
        dfs(root);
        return res;
    }

    public Integer[] dfs(Tree root) {
        int cur = root.val;
        int smallest = root.val;
        int largest = root.val;

        if (root.left == null && root.right == null) {
            return new Integer[] {cur, cur};
        }
        if (root.left != null) {
            Integer[] left = dfs(root.left);
            smallest = Math.min(smallest, left[0]);
            largest = Math.max(largest, left[1]);
        }
        if (root.right != null) {
            Integer[] right = dfs(root.right);
            smallest = Math.min(smallest, right[0]);
            largest = Math.max(largest, right[1]);
        }

        res = Math.max(res, Math.abs(cur - largest));
        res = Math.max(res, Math.abs(cur - smallest));
        return new Integer[] {smallest, largest};
    }
}


------------------------------------------------------------------------------------------------------------
  
  

  int ans;
// vector<int> v{Min , Max}

vector<int> maxDiff(Tree* root){
    if(root == NULL){
        return {};
    }
    
    int x = root->val;
    
    if(root->left == NULL && root->right == NULL){
        // ans = max(ans , x);
        return {x , x};
    }

    vector<int> left = maxDiff(root->left);
    vector<int> right = maxDiff(root->right);

    //calculate potential answer
    int leftDiff , rightDiff;
    
    if(left.size() == 0){
        rightDiff = max(abs(right[0] - x) , abs(right[1] - x));
        ans = max(ans , rightDiff);
    }
    else if(right.size() == 0){
        leftDiff = max(abs(left[0] - x) , abs(left[1] - x));
        ans = max(ans , leftDiff);
    }
    else{
        leftDiff = max(abs(left[0] - x) , abs(left[1] - x));
        rightDiff = max(abs(right[0] - x) , abs(right[1] - x));
        ans = max(ans , max(leftDiff , rightDiff));
    }

    //send answer to recursion
    int maxVal , minVal;

    if(left.size() == 0){
        minVal = min(x , right[0]);
        maxVal = max(x , right[1]);
    }
    else if(right.size() == 0){
        minVal = min(x , left[0]);
        maxVal = max(x , left[1]);
    }
    else{
        minVal = min(x , min(left[0] , right[0]));
        maxVal = max(x , max(left[1] , right[1]));
    }

    return {minVal , maxVal};
    
}

int solve(Tree* root) {
    ans = 0;
    maxDiff(root);

    return ans;
}
