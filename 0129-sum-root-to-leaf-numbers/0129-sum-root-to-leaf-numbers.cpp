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
    
    int solve(TreeNode* node, string s) {
        if(!node->left && !node->right)
            return stoi(s+to_string(node->val));
        
        int leftSubtree = 0, rightSubtree = 0;
        if(node->left)
            leftSubtree = solve(node->left, s+to_string(node->val));
        if(node->right)
            rightSubtree = solve(node->right, s+to_string(node->val));
        
        return leftSubtree + rightSubtree;
    }
    int sumNumbers(TreeNode* root) {
        return solve(root, "");
    }
};