/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    void dfs(TreeNode* node, int level){
        ans = max(ans, level);
        if(node->left != nullptr)
            dfs(node->left, level+1);
        if(node->right != nullptr)
            dfs(node->right, level+1);
    }
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        dfs(root, 1);
        return ans;
    }
};