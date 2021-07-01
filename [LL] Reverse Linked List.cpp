

ListNode* Solution::reverseList(ListNode* A) {
    ListNode* curr = A;
    ListNode* prev = NULL;
    ListNode* next;
    
    if(!curr or !(curr->next))
        return A;
    
    while(curr != NULL){
        next = curr->next;

        curr->next = prev;

        prev = curr;

        curr = next;
    }

    return prev;

}
