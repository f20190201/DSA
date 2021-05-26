//spiral level order traversal. We maintain 2 stacks, s1 for L to R and s2 for R to L

vector<int> findSpiral(Node *root)
{
    //Your code here
    
    
    vector<int> v;
    
    if(root == NULL)
        return v;
    
    stack<Node*>s1; // if pop from s1, look for right child first and put in s2
    stack<Node*> s2; // if pop from s2, look for right child first and put in s1
    
    s1.push(root);
    
    while(!s1.empty() || !s2.empty()){
                 
            while(!s1.empty()){
                
                Node* curr = s1.top();
                s1.pop();
                
                v.push_back(curr->data);
                
                if(curr->right != NULL)
                    s2.push(curr->right);
                
                if(curr->left != NULL)
                    s2.push(curr->left);
            }      
            
            while(!s2.empty()){
                
                Node* curr = s2.top();
                s2.pop();
                
                v.push_back(curr->data);
                
                if(curr->left != NULL)
                    s1.push(curr->left);
                
                if(curr->right != NULL)
                    s1.push(curr->right);
            }        
    }

    return v; }

// Normal level order traversal

// We maintain a queue where NULL is inserted after every level completed. If the popped element isn't NULL, look for it's left and righ child and push into the queue
// If the popped element is NULL, a level has ended and push NULL into the queue to denote it.
// Print the popped element
// The program ends when a NULL is popped and the queue is empty

void LevelTraversal(Node* root){
    queue<Node*>q;
    
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
        
        Node* curr = q.front();
        q.pop();
        
        if (curr != NULL){
            cout<<curr->data<<" ";
            
        if(curr->left != NULL)
            q.push(curr->left);
        
        if(curr->right != NULL)
            q.push(curr->right);
                
        }
        
        else if(curr == NULL){
            if(!q.empty())
                q.push(NULL);
            else
                return;
        }
        
    }
}
    
    
    
    
