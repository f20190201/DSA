void FindMiddle(Node* curr , Node** first , Node** second){
    Node* fast , slow;
    slow = curr;
    fast = curr->next;
    
    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }
    }
    *first = curr;
    *second = slow->next;
    slow->next = NULL;
}




void MergeLists(Node* first , Node* second){
    Node* result = NULL;
    
    if(first == NULL)
        return second;
    else if(second == NULL)
        return first;
    
    if(first->data <= second->data){
        result = first;
        result->next = MergeLists(first->next , second);
    }
    else{
        result = second;
        result->next = MergeLists(first , second->next);
    }
    
    return result;
}



void MergeSort(Node** head){
    Node* curr = *head;
    Node* first , second;
    
    if((curr == NULL) || (curr->next == NULL))
        return;
    
    FindMiddle(curr , &first , &second);
    
    MergeSort(&first);
    MergeSort(&second);
    
    *head = MergeLists(first , second);
}




