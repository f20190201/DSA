/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::subtract(ListNode* A) {
    if(!A or !(A->next))
        return A;
    
    vector<int> values;

    ListNode* fast = A , *slow = A;

    while(fast and (fast->next)){
        fast = fast->next->next;
        slow = slow->next;
    }

    ListNode* reference = slow;
    
    while(slow){
        values.push_back(slow->val);
        slow = slow->next;
    }

    reverse(values.begin() , values.end());

    ListNode* curr = A;
    int i = 0;

    while(curr != reference){
        curr->val = (values[i++] - curr->val);
        curr = curr->next;
   }

    return A;

}
