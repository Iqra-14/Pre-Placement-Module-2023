class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL) return res;
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));
        vector<int> level;
        int currentlevel=0;
        while (!q.empty()) {
            auto p=q.front(); q.pop();
            if (p.second == currentlevel) level.push_back(p.first->val);
            else {
                res.push_back(level);
                level.clear();
                level.push_back(p.first->val);
                currentlevel = p.second;
            }
            if (p.first->left) q.push(make_pair(p.first->left, currentlevel+1));
            if (p.first->right) q.push(make_pair(p.first->right, currentlevel+1));
        }
        res.push_back(level);
        return res;
    }
};