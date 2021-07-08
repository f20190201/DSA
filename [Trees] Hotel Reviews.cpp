class TrieNode {
public:    
    TrieNode() : m_content(0), m_marker(false) {}
    ~TrieNode() { 
        for(vector<TrieNode*>::iterator it(m_children.begin()); 
            it != m_children.end(); it++) {
            delete *it;
        }      
    }
    
    char content() const { return m_content; }
    void set_content(char c) { m_content = c; }
    
    bool marker() const { return m_marker; }
    void set_marker(bool m) { m_marker = m; }

    const vector<TrieNode*> &children() const { return m_children; }
    TrieNode *find(char c) const {
        for(vector<TrieNode*>::const_iterator it(m_children.begin()); 
            it != m_children.end(); it++) {
            if ((*it)->content() == c) return *it;
        }
        return NULL;
    }
    void append(TrieNode *n) { m_children.push_back(n); }

private:    
    char m_content;
    bool m_marker;
    vector<TrieNode*> m_children;
};

class Trie {
public:    
    Trie() { m_root = new TrieNode(); }
    Trie(string s) { 
        m_root = new TrieNode(); 
        add_word(s);
    }
    ~Trie() { delete m_root; }
    
    void add_word(string s) {
        if (s.length() == 0) {
            m_root->set_marker(true);
            return;
        }
        
        TrieNode *current = m_root;
        for(int i = 0; i < s.length(); i++) {
            if (s[i] == '_') {
                if (current != m_root) current->set_marker(true);
                current = m_root;
                continue;
            }
            TrieNode *n = current->find(s[i]);
            if (n == NULL) {
                n = new TrieNode();
                n->set_content(s[i]);
                current->append(n);
                current = n;
            } else {
                current = n;
            }
            
            if (i == s.length() - 1) n->set_marker(true);
        }
    }
    int count_word(const string &s) {
        TrieNode *current = m_root;
        int t = 0;
        for(int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (c == '_') {
                if (current != NULL && current->marker() == true) t++;
                current = m_root;
                continue;
            } else if (current == NULL) {
                continue;
            }
            current = current->find(c);
        }
        
        if (current != NULL && current->marker() == true) t++;
        return t;
    }
    void delete_word(string s) {
        
    }
    
private:    
    TrieNode *m_root;
};

void split(const string &S, set<string> &O) {
   int i = 0, p = 0;
    for(; i < S.size(); i++) {
        if (S[i] == '_') {
            if (p + 1 < i) {
                O.insert(S.substr(p,i-p));
                std::cout << "*" << S.substr(p,i-p) << std::endl;
            }
            p = i+1;
        }
    }
    if (p < S.size()) {
        O.insert(S.substr(p,i-p));
        std::cout << "*" << S.substr(p,i-p) << std::endl;        
    }    
}

int count(const string &S, const set<string> &O) {
   int c = 0;
   int i = 0, p = 0;
    for(; i < S.size(); i++) {
        if (S[i] == '_') {
            if (p + 1 < i) {
                std::cout << "** " << S.substr(p,i-p) << std::endl;
                if (O.find(S.substr(p,i-p)) != O.end()) {
                    //std::cout << "** " << S.substr(p,i-p) << std::endl;
                    c++;
                }
            }
            p = i+1;
        }
    }
    if (p < S.size()) {
        if (O.find(S.substr(p,i-p)) != O.end()) {
            //std::cout << "** " << S.substr(p,i-p) << std::endl;
            c++;
        }
    }   
    
    return c;
}

vector<int> old(string A, vector<string> &B) {
    string t;
    set<string> cool;
    split(A, cool);
    //std::cout << "Cool " << cool.size() << std::endl;
    
    map<int, vector<int> > m;
    for(int i = 0; i < B.size(); i++) {
        if (i != 9) continue;
        int c = count(B[i], cool);
        std::cout << "C " << i << "/" << c << " " << B[i].substr(0,25) << std::endl;
        m[c].push_back(i);
    }
    
    vector<int> out;
    for(map<int, vector<int> >::const_reverse_iterator it(m.rbegin()); it != m.rend(); it++) {
        out.insert(out.end(), it->second.begin(), it->second.end());
    }
    
    return out;
}

vector<int> Solution::solve(string A, vector<string> &B) {
    Trie t(A);

    map<int, vector<int> > m;
    for(int i = 0; i < B.size(); i++) {
        //if (i != 9) continue;
        int c = t.count_word(B[i]);
        //std::cout << "C " << i << "/" << c << " " << B[i].substr(0,25) << std::endl;
        m[c].push_back(i);
    }

    vector<int> out;
    for(map<int, vector<int> >::const_reverse_iterator it(m.rbegin()); it != m.rend(); it++) {
        out.insert(out.end(), it->second.begin(), it->second.end());
    }
    
    return out;
}


----------------------_----------------------_----------------------_----------------------_----------------------_

bool comp(pair<int , int> &a , pair<int , int> &b){
    if(a.first != b.first)
        return a.first > b.first;
    
    return a.second < b.second;

}

vector<int> Solution::solve(string A, vector<string> &B) {
    map<string , int>mp;

    stringstream ss(A);

    string word;

    while(getline(ss , word , '_')){
        if(word.size())
            mp[word]++;
    }

    vector<pair<int , int>> v;    //{instances , index}

    for(int i = 0 ; i < B.size() ; i++){
        
        stringstream s1(B[i]);
        string container;
        int num = 0;
        
        while(getline(s1 , container , '_')){
            
            if(container.size()){
                if(mp.count(container))
                    num++;
            }
        }

        v.push_back({num , i});
    }

    sort(v.begin() , v.end() , comp);


    vector<int>result;

    for(int i = 0 ; i < v.size() ; i++){
        result.push_back(v[i].second);
    }

    return result;
}

