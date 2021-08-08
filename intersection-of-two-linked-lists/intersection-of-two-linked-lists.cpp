/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
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
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(len(headA) < len(headB))
            return getIntersectionNode(headB, headA);
        
        int diff = len(headA) - len(headB);
        
        ListNode* curr = headA;
        
        while(diff){
            headA = headA->next;
            diff--;
        }
        
        ListNode* ans = NULL;
        
        while(headA && headB){
            
            if(headA == headB){
                ans = headA;
                return ans;
            }
            headA = headA->next;
            headB = headB->next;
        }
        
        
        return ans;
    }
};