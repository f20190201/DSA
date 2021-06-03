----------------------------------------
// HUFFMAN DECODING

string decode_file(struct MinHeapNode* root, string s)
{
//add code here.
    struct MinHeapNode* current = root;
    string result = "";
    for(int i = 0 ; i < s.size() ; i++){
        
        if(s[i] == '0')
            current = current->left;
            
        else if(s[i] == '1')
            current = current->right;
            
            
        if((current->left == NULL) && (current->right == NULL)){
            result += current->data;
            current = root;
        }
    }
    return result;
}
