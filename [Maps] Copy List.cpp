// Refer to https://www.youtube.com/watch?v=_v8O9TZwKSU

/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* Solution::copyRandomList(RandomListNode* A) {
    RandomListNode* curr = A;
    RandomListNode* temp;

    while(curr){
        temp = curr->next;
        curr->next = new RandomListNode(curr->label);
        curr->next->next = temp;
        curr = temp;
    }

    curr = A;

    while(curr){
        curr->next->random = ((curr->random) ? curr->random->next : curr->random);

        curr = curr->next->next;
    }

    RandomListNode* original = A , *copy = A->next , *start;
    start = copy;

    while(original and copy){
        original->next = original->next->next;
        copy->next = copy->next ? copy->next->next : copy->next;
        original = original->next;
        copy = copy->next;
    }

    return start;
}
