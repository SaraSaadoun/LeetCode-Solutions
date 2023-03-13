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
    bool check(TreeNode* leftNode , TreeNode* rightNode) {
        if(!leftNode && !rightNode)
            return true;
        if(!leftNode || !rightNode)
            return false;
        
        if(leftNode->val != rightNode->val)
            return false;
        return check(leftNode->left, rightNode->right) &&
            check(leftNode->right, rightNode->left);
    }
    bool isSymmetric(TreeNode* root) {
        return check(root->left, root->right);
        
    }
};