/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

int Solution::lPalin(ListNode* A) {
ListNode *slow = A;
ListNode *fast = A;
ListNode *mid = NULL;

//1.Find Mid Node;

while(fast!=NULL && fast->next!=NULL)

{

slow = slow->next;

fast = fast->next->next;

}

//2. Store mid element

if(fast!=NULL)

{

mid = slow->next;//For odd List

}

else

{

mid = slow;//For even List

}

//3.Reverse right half part

ListNode *current = mid;
ListNode *next = NULL;
ListNode *prev = NULL;


while(current !=NULL)
{
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
}
//4. Tarverse Both  List
while(prev!=NULL)
{
    if(A->val!=prev->val)
    {
        return 0;//No Palindrome
    }
    A = A->next;
    prev = prev->next;
}

return 1; //Palindrome

}
