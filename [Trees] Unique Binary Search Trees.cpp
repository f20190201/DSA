/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<TreeNode*> BST(int start , int end){
    
    vector<TreeNode*> list;

    if(start > end){
        list.push_back(NULL);
        return list;
    }

    for(int i = start ; i <= end ; i++){
        
        vector<TreeNode*> left = BST(start , i - 1);
        vector<TreeNode*> right = BST(i + 1 , end);

        for(int j = 0 ; j < left.size() ; j++){
            TreeNode* l = left[j];

            for(int k = 0 ; k < right.size() ; k++){
                TreeNode* r = right[k];

                TreeNode* head = new TreeNode(i);

                head->left = l;
                head->right = r;

                list.push_back(head);
            }
        }
    }
        
    return list;

}

vector<TreeNode*> Solution::generateTrees(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    return BST(1 , A);

}
