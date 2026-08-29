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
    bool hasCycle(ListNode* head) {
        if(!head or !head->next or !head->next->next)
            return false;
        
        ListNode *fast, *slow;
        fast = head->next->next;
        slow = head->next;

        while(fast != slow) {
            if((fast->next == nullptr) or (fast->next->next == nullptr))
                return false;
            fast = fast->next->next;
            slow = slow->next;
        }

        return true;
    }
};
