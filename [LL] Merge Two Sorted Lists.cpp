/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    ListNode* result = NULL;

    if(!A)
        return B;
    if(!B)
        return A;

    if(A->val < B->val){
        result = A;
        result->next = mergeTwoLists(A->next , B);
    }
    else{
        result = B;
        result->next = mergeTwoLists(A , B->next);
    }
    return result;

}

---------------------------------------------------------------------------

ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {

if( A==NULL ) return B;

if( B==NULL) return A;


struct ListNode* a = A;
struct ListNode* b= B;
struct ListNode *prev= NULL;
if( A->val > B->val ) {
    return mergeTwoLists( B,A);
}
while( a &&b){
    
    if( a->val == b->val ){
        prev= a;
        a= a->next;
        prev->next = new ListNode ( b->val ) ;
        prev= prev->next;
        prev->next= a;
        b= b->next;
    }
    else if( a->val > b->val){
        prev->next = new ListNode( b->val);
        prev= prev->next;
        prev->next = a;
        b= b->next;
       // cout<<prev->val<<" "<<a->val<<endl;
    }
    else {
        prev= a;
        a= a->next;
    }
    
}
while( a== NULL && b){
    prev->next = new ListNode(b->val);
    prev= prev->next;
    b= b->next;
}

return A ;

}
