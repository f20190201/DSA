/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int len(ListNode* A){
    int count = 0;
    ListNode* curr = A;

    while(curr){
        count++;
        curr = curr->next;
    }

    return count;

}

ListNode* Solution::rotateRight(ListNode* A, int B) {
    int N = len(A);
    
    if(B % N == 0)
        return A;
    
    B = B % N;
    
    ListNode* fast = A;
    ListNode* slow = A;

    while(B--){
        fast = fast->next;
    }

    while(fast->next != NULL){
        fast = fast->next;
        slow = slow->next;
    }

    fast->next = A;

    ListNode* head = slow->next;

    slow->next = NULL;
    
    return head;

}
