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
        
        if(!n)
            return NULL;
        
        k = k % n;
        
        if(!k)
            return head;
        
        ListNode* fast = head , *slow = head;
        
        for(int i = 0 ; i < k ; i++)
            fast = fast->next;
        
        ListNode* end;
        
        while(fast->next){
            
            slow = slow->next;
            fast = fast->next;
        }
        
        
        ListNode* newHead = slow->next;
        
        slow->next = NULL;
        
        fast->next = head;
        
        return newHead;
    }
};