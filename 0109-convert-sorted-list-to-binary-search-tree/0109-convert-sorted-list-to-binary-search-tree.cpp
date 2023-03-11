/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* solve(int l, int r, vector<int>&values){
        // invalid case
        if(l > r)
            return nullptr;

        // leaf node
        if(l == r)
            return new TreeNode(values[l]);

        // treeNode
        int mid = l + (r - l) / 2, n = values.size();

        TreeNode* node = new TreeNode(values[mid]);

        node->left = solve(l, mid-1, values);
        node->right = solve(mid+1,r, values);

        return node;

    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>values;
        while(head) {
            values.push_back(head->val);
            head = head->next;
        }

        return solve(0, values.size()-1, values);
    }
};