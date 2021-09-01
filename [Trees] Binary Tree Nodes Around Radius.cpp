// Calculate distance of each node from target to root
// For any node other than those in this path, distance would 1 + distance from its parent

unordered_map<Tree* , int> mp;
vector<int> res;

// This function returns the distance (from target) of each node in the path from root to target
int find(Tree* root , int target){
    
    if(root == NULL)
        return -1;
    
    if(root->val == target){
        mp[root] = 0;
        return 0;
    }

    int left = find(root->left , target);
    if(left >= 0){
        mp[root] = left + 1;
        return left + 1;
    }

    int right = find(root->right , target);
    if(right >= 0){
        mp[root] = right + 1;
        return right + 1;
    }

    return -1;
}
// Checks if distance of node is present in map or not, if yes, then it compares it to radius, if no, then adds 1 to current length
void dfs(Tree* root , int length , int radius){
    if(root == NULL)
        return;
    
    if(mp.count(root))
        length = mp[root];
    else
        length = length + 1;
    
    if(length == radius)
        res.push_back(root->val);
    
    dfs(root->left , length , radius);
    dfs(root->right , length , radius);

    return;
}

vector<int> solve(Tree* root, int target, int radius) {
    mp.clear();
    res.clear();
    
    find(root , target);
    dfs(root , mp[root] , radius);

    sort(res.begin() , res.end());

    return res;
}

------------------------------------------------------------------------------------------------------------

// https://binarysearch.com/problems/Binary-Tree-Nodes-Around-Radius/solutions/2837198

// Convert the tree into graph and do BFS

map<int, vector<int>> m;

void dfs(Tree* root) {
    if (!root) return;
    Tree *child1, *child2;
    child1 = root->left;
    child2 = root->right;

    if (child1) {
        m[root->val].push_back(child1->val);
        m[child1->val].push_back(root->val);
        dfs(child1);
    }
    if (child2) {
        m[root->val].push_back(child2->val);
        m[child2->val].push_back(root->val);
        dfs(child2);
    }
}

vector<int> solve(Tree* root, int k, int distance) {
    m.clear();
    dfs(root);

    vector<int> ans;
    queue<array<int, 2>> q;
    q.push({k, 0});
    set<int> vis;
    vis.insert(k);

    while (q.size()) {
        auto f = q.front();
        q.pop();
        if (f[1] == distance) {
            ans.push_back(f[0]);
            continue;
        }

        for (auto v : m[f[0]]) {
            if (vis.find(v) == vis.end()) {
                vis.insert(v);
                q.push({v, f[1] + 1});
            }
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}
