// We always compare current with current->next
// If current->next is smaller, then we look for an element bigger than it in the left list
// For this, we take a pointer prev which points to NULL and start which would be the final head of the LL
// We increment prev till we find prev->next > curr->next (this is the element for which we're finding the right position)
// When we find the correct prev->next, we store it in temp and insert curr->next in between prev and prev->next
// We change prev->next to curr->next, then curr->next = curr->next->next(for proceeding with the iteration)
// Then we change prev->next->next = temp
// Finally we return start->next

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::insertionSortList(ListNode* A) {
    if(!A or !(A->next))
        return A;

    ListNode* curr = A , *prev ,  *start = new ListNode(0);
    
    start->next = curr;
    
    prev = start;

    while(curr){
        if((curr->next) and (curr->val > curr->next->val)){

            while((prev->next) and (prev->next->val < curr->next->val))
                prev = prev->next;
            
            ListNode* temp = prev->next;
            prev->next = curr->next;
            curr->next = curr->next->next;
            prev->next->next = temp;
            prev = start;
        }
        else
            curr = curr->next;

    }


    return start->next;

}
