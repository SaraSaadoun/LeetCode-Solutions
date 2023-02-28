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
    unordered_map<string, int>mp;
    vector<TreeNode*> ans;
    //represent the subtree as a string (pre order traversal)
    string solve(TreeNode* node){
        if(!node)
            return "";

        string subtree =  "r" + to_string(node->val) + "l" + solve(node->left) +"r" + solve(node->right); 
        if(mp[subtree]++ == 1)
            ans.push_back(node);
        return subtree;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        solve(root);
        return ans;
    }
};