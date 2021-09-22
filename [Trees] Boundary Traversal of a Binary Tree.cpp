// Push the left boundary first followed by leaves(first left subtree leaves and the right) followed by reverse right boundary

class Solution {
public:
    vector<int> res;
    
    void Left(Node* root){
        
        if(root == NULL)
            return;
        
        if(root->left){
            res.push_back(root->data);
            Left(root->left);
        }
        
        else if(root->right){
            res.push_back(root->data);
            Left(root->right);
        }
        
        return;
    }
    
    void Right(Node* root){
        
        if(root == NULL)
            return;
        
        if(root->right){
            Right(root->right);
            res.push_back(root->data);
        }
        
        else if(root->left){
            Right(root->left);
            res.push_back(root->data);
        }
        
        return;
    }
    
    void Leaves(Node* root){
        
        if(root == NULL)
            return;
        
        Leaves(root->left);
        
        if(root->left == NULL && root->right == NULL)
            res.push_back(root->data);
        
        Leaves(root->right);
    }
    
    vector <int> printBoundary(Node *root)
    {
        //1. Push left Boundary
        //2. Push Leaves
        //3. Push right Boundary
        res.clear();
        res.push_back(root->data);
        
        Left(root->left);
        
        Leaves(root->left);
        Leaves(root->right);
        
        Right(root->right);
        
        return res;
    }
};
