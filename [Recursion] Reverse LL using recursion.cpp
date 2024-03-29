// https://www.youtube.com/watch?v=KYH83T4q6Vs

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A) {
    
    if(A->next == NULL)
        return A;

    ListNode* head = reverseList(A->next);

    ListNode* temp = A->next;

    temp->next = A;

    A->next = NULL;

    return head;


}
