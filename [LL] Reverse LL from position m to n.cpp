// Take 4 pointers - before the first node to be reversed, the first node to be reversed, the last node to be reversed and node after last node to be reversed
// set the last node to be reversed->next as NULL
// Now reverse from first node to be reversed to last node to be reversed normally
// If start was the head, then make head = prev(head of the reversed LL) else put start->next = prev
// Make first node to be reversed->next = node after last node to be reversed
// Return head

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseBetween(ListNode* A, int m, int n) {

    if(m == n)
        return A;
    
    ListNode *curr = A , *start = NULL , *end = NULL , *startRev = NULL , *endRev = NULL;
    int i = 1;

    while(i <= n){
        if(i < m)
            start = curr;

        else if(i == m)
            startRev = curr;
        
        else if(i == n){
            endRev = curr;
            end = endRev->next;
        }
        curr = curr->next;
        i++;
    }

    endRev->next = NULL;

    ListNode* prev = NULL , *current = startRev , *next;

    while(current){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    if(!start)
        A = prev;
    else
        start->next = prev;

    startRev->next = end;

    return A;

}
