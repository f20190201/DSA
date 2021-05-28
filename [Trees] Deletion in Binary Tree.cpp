// Given a Binary Tree of size N, your task is to complete the function deletionBT(),
// that should delete a given node from the tree by making sure that tree shrinks from the bottom
// (the deleted node is replaced by bottommost and rightmost node).

// find target node and deepest node 
// replace the target node data by deepest node data
// delete the deepest node 

--------------------------------------------
// Function to delete the deepest node, whihc takes in root of the tree and the target node as parameters 
  
void deleteNode(Node* root , Node* last){
    queue<Node*>q;
    q.push(root);
    
    while(!q.empty()){
        Node* current = q.front();
        q.pop();
        
        if(current->left){
            
            if(current->left == last){
                current->left = NULL;
                free(last);
                return;
            }
            
            q.push(current->left);
        }
        
        if(current->right){
            
            if(current->right == last){
                current->right = NULL;
                free(last);
                return;
            }
            
            q.push(current->right);
        }
    }
    return;
}
--------------------------------------------
// Function to find the rightmost and bottom most node in the tree
// Right most and bottom most node in a tree is the last node which comes in the level order traversal of a tree
  
  Node* RightAndBottom(Node* root){
    
    queue<Node*>q;
    q.push(root);
    
    while(!q.empty()){
        Node* curr = q.front();
        q.pop();
        
        if(curr->left)
            q.push(curr->left);
        
        if(curr->right)
            q.push(curr->right);
        
        if(q.size() == 1)
            return q.front();
    }
    
    
}
--------------------------------------------
// Funtion which finds the node to be replaced from the int key given and calls the above two functions and performs the delete and replace operations.
  
struct Node* deletionBT(struct Node* root, int key)
{
    // code here
    Node* DeepestNode = RightAndBottom(root);
    
    queue<Node*>q;
    q.push(root);
    Node* target = NULL;
    
    while(!q.empty()){
        
        Node* curr = q.front();
        q.pop();
        
        if(curr->data == key) target = curr;
        
        if(curr->left) q.push(curr->left);
     
        if(curr->right) q.push(curr->right);   
    }
    
   
  //Replacing the target data by the data of the deepest node
    target->data = DeepestNode->data;
    
    deleteNode(root , DeepestNode);
    
    return root;
    
    
}
--------------------------------------------
