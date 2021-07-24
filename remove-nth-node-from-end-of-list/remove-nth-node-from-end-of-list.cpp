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
            count++;
            A = A->next;
        }
        return count;
        
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int dest = len(head) - n;
        
        if(len(head) == 1){
            if(n == 1)
                return NULL;
            return head;
        }
        
        ListNode* curr = head;
        
        if(dest == 0){
            head = head->next;
            return head;
        }
        
        if(dest == 1){
            head->next = head->next->next;
            return head;
        }
        
        while(dest > 1){
            curr = curr->next;
            dest--;
        }
        
        curr->next = curr->next->next;
        
        return head;
        
    }
};