class LRUCache {
public:
    struct node{
        int val;
        int key;
        node* next;
        node* prev;
        node(int x , int y) : key(x) , val(y) , next(NULL) , prev(NULL){}
    };
    
    node* head = new node(-1 , -1);
    node* tail = new node(-1 , -1);
    
    int n;
    unordered_map<int , node*>mp;
    
    void addnode(node* A){
        node* temp = head->next;
        A->next = temp;
        temp->prev = A;
        head->next = A;
        A->prev = head;
        
        return;
    }
    
    void deletenode(node* A){
        node* prevnode = A->prev;
        node* nextnode = A->next;
        
        prevnode->next = nextnode;
        nextnode->prev = prevnode;
        
        return;
    }
    
    LRUCache(int capacity) {
        n = capacity;
        
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        
        if(mp.count(key) == 0)
            return -1;
            
        node* curr = mp[key];
        int val = curr->val;
        
        mp.erase(key);
        deletenode(curr);
        addnode(curr);
        mp[key] = head->next;
        
        return val;
        
    }
    
    void put(int key, int value) {
        
        if(mp.count(key)){
            node* newnode = mp[key];
            mp.erase(key);
            deletenode(newnode);
        }
        
        if(mp.size() == n){
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        
        addnode(new node(key , value));
        mp[key] = head->next;
        
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */