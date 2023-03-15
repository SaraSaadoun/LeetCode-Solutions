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
    
    int getDepth(TreeNode *node){
        int len = 0;
        while(node){
            ++len;
            node = node->left;
        }
        return len;   
    }

    bool isCompleteTree(TreeNode* root) {
        //accepted Tree => node, node, ... , node, null, null, ... ,null
        
        // BFS
        queue<TreeNode*> q;
        q.push(root);
        
        // add nodes till the you reeach a node added which = nullptr => stop 
        while(q.front() != nullptr) {
            auto node = q.front();
            q.pop();

            q.push(node->left);
            q.push(node->right);
        }
        // remove all null nodes 
        while(!q.empty() && q.front() == nullptr)
            q.pop();
        
        //if there is still nodes which are not null
        // "not far left as possible"
        return q.empty();
    }
};