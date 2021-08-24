bool isCousins(Node *root, int a, int b)
{
   //add code here.
   queue<pair<Node* , int>>q; //{Node , Parent}
   
   q.push({root , -1});
   
   while(!q.empty()){
       
       int n = q.size();
       
       int parent = -1;
       
       
       while(n--){
            auto curr = q.front().first;
            q.pop();
            
            if(curr->left && ((curr->left->data == a) || (curr->left->data == b))){
                if(curr->data == parent)
                    return 0;
                
                else if(curr->data != parent && parent != -1)
                    return 1;
                
                parent = curr->data;
            }
            
            if(curr->right && ((curr->right->data == a) || (curr->right->data == b))){
                
                if(curr->data == parent)
                    return 0;
                
                else if(curr->data != parent && parent != -1)
                    return 1;
                
                parent = curr->data;
            }
            
            if(curr->left)
                q.push({curr->left , curr->data});
            
            if(curr->right)
                q.push({curr->right , curr->data});
       }
       
   }
   
   return 0;
}


----------------------------------------------------------------------------------------------------------------------
  
  
  struct trio{
    Node* node;
    int parent;
    int level;
    
    trio(Node* x , int y , int z) : node(x) , parent(y) , level(z){
        
    }
};

bool isCousins(Node *root, int a, int b)
{
   //add code here.
   queue<trio>q; //{Node , Parent}
   
   q.push({root , -1 , 0});
   vector<trio> v;
   int level = -1;
   
   while(!q.empty()){
       
       int n = q.size();
       
       int parent = -1;
       level++;
        
        while(n--){
            auto curr = q.front();
            v.push_back({curr.node , curr.parent , level});
            q.pop();
            
            if(curr.node->left)
                q.push({curr.node->left , curr.node->data , level});
            
            if(curr.node->right)
                q.push({curr.node->right , curr.node->data , level});
        }
      
   }
   
   int ans_parent = -1 , ans_level = -1;
   
   for(auto it : v){
        Node* curr_node = it.node;
        int curr_parent = it.parent , curr_level = it.level;
        
        if(curr_node->data == a || curr_node->data == b){
            
            if(ans_parent == -1){
                ans_parent = curr_parent;
                ans_level = curr_level;
            }
            
            else{
                if(ans_level == curr_level && ans_parent != curr_parent)
                    return 1;
                
                return 0;
            }
        }
   }
   
   return 0;
}
