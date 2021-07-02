// First reverse the first K nodes
// Now the head of this sub-list would become its tail
// This new tail(old head) would point towards the recursive return with next(or curr) being its head(or first) node
// We return the new head of the LL, i.e. prev

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A, int B) {
    if(!A or !(A->next))
        return A;
    
    ListNode* prev = NULL;
    ListNode* curr = A;
    ListNode* next;

    for(int i = 0 ; i < B  ; i++){
        next = curr->next;

        curr->next = prev;

        prev = curr;

        curr = next;
    }

    A->next = reverseList(next , B);

    return prev;
}
