/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(head == NULL)
            return NULL;
        
        Node* curr = head;
        
        while(curr){
            Node* next = curr->next;
            
            Node* temp = new Node(curr->val);
            
            curr->next = temp;
            
            temp->next = next;
            
            curr = next;
        }
        
        curr = head;
        
        while(curr){
            
            curr->next->random = (curr->random == NULL) ? NULL : curr->random->next;
            
            curr = curr->next->next;
        }
        
        Node* copy = head->next;
        Node* original = head;
        
        curr = copy;
        
        while(original && copy){
            
            original->next = original->next->next;
            
            copy->next = (copy->next == NULL) ? NULL : copy->next->next;
            
            original = original->next;
            
            copy = copy->next;
        }
        
        return curr;
    }
};