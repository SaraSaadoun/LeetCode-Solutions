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
    int widthOfBinaryTree(TreeNode* root) {
        
        queue<pair<TreeNode*, long long>>q;
        q.push({root, 1});

        int level = 0, sz = 1;
        int ans = 0;
        //store in each node its idx (start from each level:1 2 3 ...)
        //to get the left and right children indices of the curr node
        //2 * (curr_idx - first node idx)+ 1 and 2 * (curr_idx - first node idx) +2
        while(!q.empty()) {
            sz = q.size();
            //first idx and last idx of the previous level:
            int st_idx = q.front().second, end_idx = q.back().second;
            ans = max(ans, end_idx - st_idx + 1);

            while(sz--) {
                auto [node, curr_idx] = q.front();
                q.pop();

                if(node->left) 
                    q.push({node->left, 2LL * (curr_idx - st_idx) + 1});
                
                if(node->right) 
                    q.push({node->right, 2LL * (curr_idx - st_idx) + 2});
                
            }
        }
        
        return ans;
    }
};