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
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right)
            return head;
        ListNode* curr = head;
        int i = 1;
        while(i< left){
            curr = curr->next;
            ++i;
        }
        ListNode* ptr = curr;
        vector<int>v;
        while( i<=right){
            v.push_back(curr->val);
            curr = curr->next;
            ++i;
        }
        int sz = v.size();
        
        for(int j = sz-1; j>=0; --j){
            
            ptr->val = v[j];
            ptr = ptr->next;
        }
        return head;
        
        
    }
};