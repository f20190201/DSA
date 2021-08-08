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
    // as soon as the number of nodes left becomes less than k, return head.
    
    int len(ListNode* A){
        int count = 0;
        
        while(A){
            A = A->next;
            count++;
        }
        return count;
    }
    
    ListNode* revK(ListNode* head, int k , int num){
        
        if(num < k)
            return head;
        
        ListNode* curr = head , *prev = NULL , *next;
        
        for(int i = 0 ; i < k ; i++){
            
            next = curr->next;
            
            curr->next = prev;
            
            prev = curr;
            
            curr = next;
        }
        
        head->next = revK(curr , k , num - k);
        
        return prev;    
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        int num = len(head);
        
        return revK(head , k , num);
    }
};