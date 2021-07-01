We advance by the difference of the lengths of the LLs.
Now we are equidistant from the intersection point
We loop till both the nodes become equal

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int len(ListNode* A){
    ListNode* temp = A;
    int d = 0;

    while(temp){
        temp = temp->next;
        d++;
    }
    return d;
}

ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(len(A) > len(B))
        return getIntersectionNode(B, A);
    
    int diff = len(B) - len(A);
    
    ListNode* temp1 = A;
    ListNode* temp2 = B;

    while(diff){
        temp2 = temp2->next;
        diff--;
    }

    while(temp1 != temp2){
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return temp1;  

}
