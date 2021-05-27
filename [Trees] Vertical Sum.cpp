

void LevelAndData(Node* root , int level , map<int , int> &mp){
        
        if(root == NULL)
            return;
        
  // Storing the sum of node->data of nodes in each level
        mp[level] += root->data;
        
  // Level of any node to left of root is (current level - 1)
        LevelAndData(root->left , level - 1 , mp);
  
  // Level of any node to right of root is (current level + 1)
        LevelAndData(root->right , level + 1, mp);
        
        return;
    }
  
    vector <int> verticalSum(Node *root) {
        // add code here.
        map<int , int> mp; //itr->first is level and itr->second is value
        int level = 0;
        vector<int> result;
        LevelAndData(root , level , mp);
        
        for ( auto itr = mp.begin(); itr != mp.end(); ++itr){
            result.push_back(itr->second);
        }
        
        return result;
        
        
        
        
        
    }
