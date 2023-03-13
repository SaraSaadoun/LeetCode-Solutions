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
    string dfsLeft(TreeNode* node) {
        if(!node)
            return "#";
        return "#" + dfsLeft(node->left) + "#" + to_string(node->val) + "#" + dfsLeft(node->right);
        
    }
    string dfsRight(TreeNode* node) {
        if(!node)
            return "#";
        return "#" + dfsRight(node->right) + "#" + to_string(node->val) + "#" + dfsRight(node->left);
        
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        string left = dfsLeft(root->left);
        string right = dfsRight(root->right);
        
        return left == right;
    }
};