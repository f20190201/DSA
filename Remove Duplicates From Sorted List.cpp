/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode* curr = A;
    ListNode* newptr = A;

    if(!curr->next)
        return A;

    while(curr != NULL){
        curr = curr->next;

        if(!curr){
            newptr->next = NULL;
            break;
        }

        if(curr->val != newptr->val){
            newptr->next = curr;
            newptr = curr;
        }
    }
    return A;

}


--------------------------------------------------------------------
  
  
  
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
