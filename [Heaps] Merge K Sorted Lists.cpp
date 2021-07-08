/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    ListNode* curr;
    priority_queue<int , vector<int> , greater<int>> minHeap;

    for(auto x : A){
        ListNode* curr = x;

        while(curr){
            minHeap.push(curr->val);
            curr = curr->next;
        }

    }

    ListNode* start , *temp = new ListNode(-1);
    
    start = temp;

    while(minHeap.size()){
        ListNode* temp1 = new ListNode(minHeap.top());
        minHeap.pop();
        temp->next = temp1;
        temp = temp1;
    }
    temp->next = NULL;

    return start->next;
}


---------------------------------------------------------------------------------------------------------
  
  class Solution {
public:

        struct CompareNode {
                bool operator()(ListNode* const & p1, ListNode* const & p2) {
                        // return "true" if "p1" is ordered before "p2", for example:
                        return p1->val > p2->val;
                }
        };
    ListNode *mergeKLists(vector<ListNode *> &lists) {
            ListNode* dummy = new ListNode(0);
            ListNode* tail = dummy;

            priority_queue<ListNode*,vector<ListNode*>,CompareNode> queue;

            for (int i = 0; i < lists.size(); i++) {
                    if (lists[i] != NULL) {
                            queue.push(lists[i]);
                    }
            }

            while (!queue.empty()) {
                    tail->next = queue.top();
                    queue.pop();
                    tail = tail->next;

                    if (tail->next) {
                            queue.push(tail->next);
                    }
            }

            return dummy->next;
    } }; ```
