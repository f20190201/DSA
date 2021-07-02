/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* A) {
    if(!A or !(A->next))
        return A;
    
    ListNode* head = A->next;
    ListNode* remaining = head->next;

    head->next = A;
    A->next = swapPairs(remaining);

    return head;

}


--------------------------------------------------
  
  node* pairWiseSwap(node* head)
{
    // If linked list is empty or
    // there is only one node in list
    if (head == NULL || head->next == NULL)
        return head;
  
    // Initialize previous and current pointers
    node* prev = head;
    node* curr = head->next;
  
    head = curr; // Change head before proceeding
  
    // Traverse the list
    while (true) {
        node* next = curr->next;
        curr->next = prev; // Change next of
        // current as previous node
  
        // If next NULL or next is the last node
        if (next == NULL || next->next == NULL) {
            prev->next = next;
            break;
        }
  
        // Change next of previous to next of next
        prev->next = next->next;
  
        // Update previous and curr
        prev = next;
        curr = prev->next;
    }
    return head;
}
