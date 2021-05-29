// We calculate the vertical path of each node from LCA and then find the distance from LCA to each of the nodes.
// If none of the either node is LCA then we add 1 to the final count

int verticalHeight(Node* root , int key , int level , vector<int> &v){
    // Making a vector of the vertical path from node to LCA
    // Later we'll join the 2 vectors to get the final path between the 2 nodes.
  
    if(root == NULL)
        return 0;
    
    if(root->data == key){
        v.push_back(level);
        return 1;
    }
    
    if(root->left)
        if(verticalHeight(root->left , key , level - 1 , v)){
            v.push_back(level);
            return 1;
        }
        
    if(root->right)
        if(verticalHeight(root->right , key , level + 1 , v)){
            v.push_back(level);
            return 1;
        }
    return 0;
    
}

Node* LCA(Node* root , int first , int second){
    if(!root)
        return NULL;
    
    if(root->data == first || root->data == second)
        return root;
    
    Node* left =  LCA(root->left , first , second);
    Node* right =  LCA(root->right , first , second);
    
    if(left && right)
        return root;
    
    return (left) ? left : right;
    
}

int NumberOFTurns(struct Node* root, int first, int second)
{
  // Your code goes here
  vector<int> First;
  vector<int> Second;
  int level = 0;
  int count = 0;
  
  Node* Ancestor = LCA(root , first , second);

  
  verticalHeight(Ancestor , first , level , First);
  verticalHeight(Ancestor , second ,level , Second);
    
  // Making the path from LCA to node instead of the other way round
  reverse(Second.begin() , Second.end());
  
  // Otherwise LCA would've been counted twice
  First.erase(First.end() - 1);
  
  // Full path from one node to the other
  for(auto x: Second)
    First.push_back(x);
   
   // Finding the number of turns 
  for(int i = 1 ; i < First.size() - 1 ; i++){
      if(((First[i] - First[i-1]) * (First[i] - First[i+1])) > 0)
        count++;
  }
  if(Ancestor->data == first || Ancestor->data == second)
    return (count == 0) ? -1 : count;
  
  return (count + 1);
  
}
