/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
  

ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    // cout<<"SUCCESS2"<<endl;
    ListNode* Aptr = A;
    // cout<<"SUCCESS3"<<endl;
    ListNode* Bptr = B;
    // cout<<"SUCCESS1"<<endl;
    int carry = 0;

    ListNode* sum = new ListNode(0);
    ListNode* head = sum;

    while(Aptr->val == 0 and Bptr->val == 0){
        Aptr = Aptr->next;
        Bptr = Bptr->next;
    }

    while(Aptr and Bptr){
        
        int data = Aptr->val + Bptr->val + carry;

        ListNode* temp = new ListNode(data % 10);
        
        sum->next = temp;

        sum = temp;

        carry = data / 10;

        Aptr = Aptr->next;
        Bptr = Bptr->next;
    }

    while(Bptr){
        int data = Bptr->val + carry;

        ListNode* temp = new ListNode(data % 10);
        
        sum->next = temp;

        sum = temp;

        carry = data / 10;

        Bptr = Bptr->next;
    }

    while(Aptr){
        int data = Aptr->val + carry;

        ListNode* temp = new ListNode(data % 10);
        
        sum->next = temp;

        sum = temp;

        carry = data / 10;

        Aptr = Aptr->next;
    }

    while(carry){

        ListNode* temp = new ListNode(carry % 10);
        
        sum->next = temp;

        sum = temp;

        carry = carry / 10;

    }

    return head->next;  

}
