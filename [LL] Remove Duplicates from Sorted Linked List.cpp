/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    map<int , int> mp;

    ListNode* curr = A;

    while(curr){
        mp[curr->val]++;
        curr = curr->next;
    }

    ListNode* prev = NULL;
    ListNode* start = NULL;
    curr = A;

    while(curr){
        if(mp[curr->val] != 1){
            curr = curr->next;
            continue;
        }
        if(!start){
            prev = curr;
            start = curr;
        }
        else{
            prev->next = curr;
            prev = curr;
        }
        curr = curr->next;
    }
    if(prev)
        prev->next = NULL;

    return start;

}
