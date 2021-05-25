// We use a queue to traverse the tree level-order and push the left child first(if exists) and then right child(if exists). 
// The last element in the queue is going to be the rightmost node in the level, since we push right child after left.
// We chekc if only one element is prenet in the queue, if yes, then we print it.
// O(N)

vector<int> rightView(Node *root)
    {
       // Your Code here
       queue<Node*>q;
       vector<int> v;
       
       q.push(root);
       
       while(!q.empty()){
           
           int n = q.size();
           
           for(int i = 0; i<n ; i++){
               Node* curr = q.front();
               q.pop();
               
               if(i == n-1)
                    v.push_back(curr->data);
               
               if(curr->left != NULL)
                   q.push(curr->left);
               
              
               if(curr->right != NULL)
                   q.push(curr->right);
               
           }
       }
       return v;
       
       
       
    }
