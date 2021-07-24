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
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(len(l1) < len(l2))
            return addTwoNumbers(l2 , l1);
        
        int carry = 0;
        
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        
        while(curr1){
            int sum = 0;
            if(curr2){
                sum = carry + curr1->val + curr2->val;
                curr2 = curr2->next;
            }
            else
                sum = carry + curr1->val;
            
            curr1->val = sum % 10;
            carry = sum / 10;
            
            curr1 = curr1->next;
        }
        
        if(carry){
            curr1 = l1;
            
            while(curr1->next)
                curr1 = curr1->next;
            
            ListNode* temp = new ListNode(carry);
            curr1->next = temp;
            
        }
        
        return l1;
    }
};