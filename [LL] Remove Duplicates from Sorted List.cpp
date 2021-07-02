ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode *prev = A;
    ListNode *curr = A->next;
    
    while(curr != NULL){
        if(prev->val == curr->val){
            prev->next = curr->next;
            curr = curr->next;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
    return A;
}


---------------------------------------------------------------------------
  
  
  ListNode* Solution::deleteDuplicates(ListNode* A) {
        if(A == NULL || A->next == NULL)return A;
        if(A->val == A->next->val){ // skip this node
            return deleteDuplicates(A->next);
        }
        else{ // attach this node to rest of the list
            A->next = deleteDuplicates(A->next);
            return A;
        }
    }
