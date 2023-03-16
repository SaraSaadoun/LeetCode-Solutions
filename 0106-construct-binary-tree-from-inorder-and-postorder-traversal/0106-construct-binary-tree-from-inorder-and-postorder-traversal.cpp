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

    unordered_map <int, int> mp;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int rootIdx = postorder.size() - 1, m = inorder.size();
        for (int i = 0; i < m; ++i)
            mp[inorder[i]] = i;

        return solve(inorder, postorder,rootIdx, 0, m - 1);
    }

    TreeNode* solve(vector<int>& inorder, vector<int>& postorder,int &rootIdx, int l, int r) {
        if(l > r)
            return NULL;
        int mid = mp[postorder[rootIdx]];
        TreeNode *node = new TreeNode(postorder[rootIdx]);
        rootIdx--;
        node->right = solve(inorder, postorder, rootIdx, mid+1, r);
        node->left = solve(inorder, postorder, rootIdx, l, mid-1);
        return node;

    }
};