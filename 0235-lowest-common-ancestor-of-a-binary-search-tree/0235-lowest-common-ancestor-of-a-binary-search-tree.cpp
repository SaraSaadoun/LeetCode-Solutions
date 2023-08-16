/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* solve(TreeNode* curr, TreeNode* mn, TreeNode* mx) {
        if(curr->val >= mn->val && curr->val <= mx->val) 
            return curr;
        if(mn->val > curr->val)
            return solve(curr->right, mn, mx);
        return solve(curr->left, mn, mx);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val > q->val)
            swap(p, q);
        // p -> min, q -> max
        // if node >= p && node <= q return node
        // if node >= p solve(right half)
        // if node <= q solve(left  half)
        return solve(root, p, q);
    }
};