class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root)
            return false;
        return pathSearch(root,sum,root->val);
    }
private:
    bool pathSearch(TreeNode* root,int sum,int curSum)
    {
        if(!root->left && !root->right)
            return sum==curSum;
        if(root->left && root->right) return pathSearch(root->left,sum,curSum+root->left->val) || pathSearch(root->right,sum,curSum+root->right->val);
        else if(root->left) return pathSearch(root->left,sum,curSum+root->left->val);
        else return pathSearch(root->right,sum,curSum+root->right->val);
    }
};