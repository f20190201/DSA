#include <bits/stdc++.h>

bool kthAncestor(Node* root , int target , int &k){
    
    if(!root)
        return 0;
    
    if(root->data == target){
        k--;
        return 1;
    }
    
    else{
        bool LeftFlag = kthAncestor(root->left , target , k);
        
        if(LeftFlag){
            
            if(!k){
                cout<<k<<"th ancestor is "<<root->data;
                return 0;
            }
            
            else{
                k--;
                return 1;
            }       
        }
        
        bool RightFlag = kthAncestor(root->right , target , k);
        
        if(RightFlag){
            
            if(!k){
                cout<<k<<"th ancestor is "<<root->data;
                return 0;
            }
            
            else{
                k--;
                return 1;
            }       
        }
    }
        
}

int main() {
	bool flag = kthAncestor(root , item , k);
	
	if(flag == 1)
	    cout<<"No such item exists\n";
	return 0;
}
