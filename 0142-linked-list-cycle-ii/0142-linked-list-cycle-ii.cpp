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

        ListNode *slow = head, *fast = head;
        while(fast && fast->next){
            // update
            slow = slow->next;
            fast = fast->next->next;
            // check for the cycle
            if(slow == fast){
                // dist from head to answer in the forward path
                // equals dist from slow / fast to it in the backward (cyclic) path
                while(head != slow){
                    head = head->next;
                    slow = slow->next;
                }
                return slow;
            }
        }

        return nullptr;
    }
};