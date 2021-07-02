/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::subtract(ListNode* A) {
    if(!A or !(A->next))
        return A;
    
    vector<int> values;

    ListNode* fast = A , *slow = A;

    while(fast and (fast->next)){
        fast = fast->next->next;
        slow = slow->next;
    }

    ListNode* reference = slow;
    
    while(slow){
        values.push_back(slow->val);
        slow = slow->next;
    }

    reverse(values.begin() , values.end());

    ListNode* curr = A;
    int i = 0;

    while(curr != reference){
        curr->val = (values[i++] - curr->val);
        curr = curr->next;
   }

    return A;

}


------------------------------------------------------------
    
    
    
    ListNode* reverseList(ListNode* head) {
	ListNode* prev = NULL;
	ListNode* cur = head;
	ListNode* next;

	while (cur != NULL) {
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}

	return prev;
}

ListNode* Solution::subtract(ListNode* head) {

	// Zero or single node
	if (head == NULL || head->next == NULL)
		return head;

	ListNode* slow = head;
	ListNode* fast = head->next;

	while (fast->next != NULL && (fast->next)->next != NULL) {
		slow = slow->next;
		fast = (fast->next)->next;
	}

	// Now slow points to the last node to be updated i.e. n/2th node

	// Reverse the remaining list
	// Tail points to the last node of the original list but this list is now in reverse direction.
	ListNode* tail = reverseList(slow->next);


	// Keep updating values of the first half of the list till n/2th node i.e. till curHead reaches slow
	ListNode* curHead = head;
	ListNode* curTail = tail;
	while (true) {
		curHead->val = curTail->val - curHead->val;
		if (curHead == slow) {
			// First n/2 values have been updated.
			break;
		}
		curHead = curHead->next;
		curTail = curTail->next;
	}

	// Values have been updated now.

	// Now just join back the list that was reverse after the slow node i.e. while computing tail node.
	slow->next = reverseList(tail);

	return head;
}
