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


------------------------------------------------------------
// Use slow and fast ptr but move the slow ptr only after moving fast ptr B times, because we're holding back B positions from the middle

int printKthfrommid(struct Node* head_ref, int k)
{
    struct Node* slow = head_ref;
    struct Node* fast = head_ref;  // initializing fast and slow pointers
     
    for( int i = 0 ; i < k ; i++ )
     {
       if(fast && fast->next)
       {
         fast = fast->next->next;  // moving the fast pointer
       }
       else
       {
         return -1;   // If no such node exists, return -1
       }
     }
      
     while(fast && fast->next)
     {
       slow  = slow->next;
       fast  = fast->next->next;
     }
      
    return slow->data;
}
