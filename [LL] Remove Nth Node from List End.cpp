// Find position from front and remove

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

    while(A){
        count++;
        A = A->next;
    }
    // cout<<"**"<<count<<endl;
    return count;

}


ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    if(!B)
        return A;

    if(B >= len(A)){
        A = A->next;
        return A;
    }
    ListNode* curr = A;

    int d = len(A) - B - 1;

    while(d){
        curr = curr->next;
        d--;
    }

    curr->next = curr->next->next;

    return A;
}
