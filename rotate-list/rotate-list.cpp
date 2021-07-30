/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int len(ListNode* A){
        int count = 0;
        
        while(A){
            A = A->next;
            count++;
        }
        
        return count;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        int n = len(head);
        
        if(n <= 1)
            return head;
        
        k = k % n;
        
        ListNode* curr = head;
        
        while(n - 1 - k){
            curr = curr->next;
            k++;
        }
        
        ListNode* curr1 = curr;
        ListNode* newHead = curr->next;
        
        if(newHead == NULL)
            return head;
        
        while(curr1->next)
            curr1 = curr1->next;
        
        curr1->next = head;
        
        curr->next = NULL;
        
        return newHead;
        
    }
};