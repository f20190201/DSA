// We make two LLs, smaller and greater
// If an element is smaller than B we append it to smaller and same for greater
// Finally we append the tail of the smaller to head of greater and return head of smaller

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int B) {
    ListNode* temp1 = new ListNode(0);
    ListNode* temp2 = new ListNode(0);
    ListNode* smaller = temp1 , *greater = temp2;

    while(A){
        if(A->val < B){
            smaller->next = A;
            smaller = smaller->next;

        }

        else{
            greater->next = A;
            greater = greater->next;
        }

        A = A->next;
    }

    smaller->next = temp2->next;
    greater->next = NULL;

    return temp1->next;

}
