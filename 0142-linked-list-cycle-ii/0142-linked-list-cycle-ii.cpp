/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
    
        ListNode *ptr = head;

        unordered_map<ListNode*, bool> vis;
        while(ptr){
            if(vis[ptr]){
                return ptr;
            }
            vis[ptr] = true;                
            ptr = ptr->next;
        }
        
        return nullptr;
    }
};