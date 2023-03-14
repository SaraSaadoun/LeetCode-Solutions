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
    long long solve(TreeNode* node, string s) {
        if(!node->left && !node->right)
            return stoi(s+to_string(node->val));
        
        long long num1 = 0, num2 = 0;
        if(node->left)
            num1 = solve(node->left, s+to_string(node->val));
        if(node->right)
            num2 = solve(node->right, s+to_string(node->val));
        return num1 + num2;
    }
    int sumNumbers(TreeNode* root) {
        return (int)solve(root, "");
    }
};