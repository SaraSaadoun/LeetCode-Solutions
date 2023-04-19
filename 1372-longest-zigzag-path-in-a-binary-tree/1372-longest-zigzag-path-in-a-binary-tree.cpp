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
    int get_longest(TreeNode* node, int lastDirec, int len) {
        if(!node)
            return len - 1;

        // start from the curr node and go to the same direc it came from - > reset counter
        // continue the same zigzag direc
        
        int ch2, ch1;
        if(lastDirec){
            ch1 = get_longest(node->right, lastDirec, 1);
            ch2 = get_longest(node->left, 0, len+1);
        }
        else{
            ch1 = get_longest(node->left, lastDirec, 1);
            ch2 = get_longest(node->right, 1, len+1);
        }
        return max(ch1, ch2);
        
    }
    int longestZigZag(TreeNode* root) {
        return get_longest(root, -1, 0);
    }
};