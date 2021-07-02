// Find out lastRev and last = lastRev->next
// Now put lastRev->next = NULL and reverse normally from head to lastRev
// Now increment the last node pointer to B-1 times
// Recursively call for last->next now
// Return the head of the new reversed list i.e. prev

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* A, int B) {
    if(!A)
        return A;

    //jump B-1 steps

    ListNode *last = NULL , *lastRev = A;

    for(int i = 0 ; i < B - 1 ; i++){
        lastRev = lastRev->next;
    }
    last = lastRev->next;
    lastRev->next = NULL;
    //reverse from A to lastRev

    ListNode *prev = NULL , *curr = A , *next;

    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    A->next = last;
    
    if(!last)
        return prev;

    for(int i = 0 ; i < B - 1 ; i++)
        last = last->next;

    last->next = solve(last->next , B);

    return prev;

}
