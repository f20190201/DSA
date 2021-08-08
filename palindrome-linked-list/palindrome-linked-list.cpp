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
    
    ListNode* revLL(ListNode* A){
        ListNode* prev = NULL , *curr = A , *next;
        
        while(curr){
            next = curr->next;
            
            curr->next = prev;
            
            prev = curr;
            
            curr = next;
            
        }
        
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head , *fast = head;
        
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        // if number of nodes are odd, fast won't be NULL
        
        if(fast)
            slow = slow->next;
        
        
        ListNode* curr = revLL(slow);
        
        while(curr){
            if(head->val != curr->val)
                return 0;
            head = head->next;
            curr = curr->next;
        }
        
        return 1;
    }
};
