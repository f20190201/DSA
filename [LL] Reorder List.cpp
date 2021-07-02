// Push all elements into a stakc
// Now pop one by one and append curr->next to s.top() and make curr = curr-> old next
// At the end, make curr->next = NULL

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reorderList(ListNode* A) {
    ListNode* curr = A;
    stack<ListNode*>s;

    while(curr){
        s.push(curr);
        curr = curr->next;
    }

    int N = s.size();

    curr = A;

    for(int i = 0 ; i < N/2 ; i++){
        ListNode* temp = curr->next;

        ListNode* top = s.top();
        s.pop();

        curr->next = top;

        top->next = temp;

        curr = temp;

    }

    curr->next = NULL;

    return A;

}


-------------------------------------------------------
// Reverse the 2nd half of LL and add nodes one-by-one into the first half
  

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reorderList(ListNode* A) {
    ListNode* fast = A , *slow = A;

    while(fast and fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }

    ListNode* prev = NULL;
    ListNode* curr = slow;
    ListNode* next;

    while(curr){
        next = curr->next;

        curr->next = prev;

        prev = curr;

        curr = next;
    }

    ListNode* left = A , *right = prev;

    while(right->next){
        
        ListNode* temp1 = left->next;
        left->next = right;
        left = temp1;

        ListNode* temp2 = right->next;
        right->next = temp1;
        right = temp2;

    }

    return A;
       

}
