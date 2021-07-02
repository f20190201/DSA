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

int Solution::solve(ListNode* A, int B) {
    int N = len(A);

    if(B > (N/2))
        return -1;
    int mid = (N/2) + 1;

    int pos = mid - B - 1;

    ListNode* result = A;

    while(pos){
        result = result->next;
        pos--;
    }

    return result->val;

}
