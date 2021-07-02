// Make a vector containing the count of 0s and 1s

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* A) {
    if(!A or !(A->next))
        return A;
    
    vector<int> count(2);

    ListNode* curr = A;

    while(curr){
        count[curr->val]++;
        curr = curr->next; 
    }
    curr = A;

    for(int i = 0 ; i < count.size() ; i++){

        while(count[i]){
            curr->val = i;
            curr = curr->next;
            count[i]--;
        }

    }
    return A;
}
