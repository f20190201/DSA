// Use a vector or a stack(preferred) to store the values of even nodes and then iterate over LL once again to reverse the values

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* Solution::solve(ListNode* A) {
    
    int count = 1;
    vector<int>v;

    ListNode* curr = A;

    while(curr){
        if(count % 2 == 0)
            v.push_back(curr->val);
        
        curr = curr->next;
        count++;
    }

    reverse(v.begin() , v.end());
    int i = 0;
    count = 1;
    curr = A;

    while(curr){
        if(count % 2 == 0)
            curr->val = v[i++];
        
        curr = curr->next;
        count++;
    }
    return A;

}
