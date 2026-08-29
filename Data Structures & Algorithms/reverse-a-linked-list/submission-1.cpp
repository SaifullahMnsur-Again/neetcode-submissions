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
    ListNode* reverseList(ListNode* curr, ListNode* prev = nullptr) {
        if (curr == nullptr) {
            return prev; 
        }
        if (curr->next == nullptr) {
            curr->next = prev;
            return curr;
        }
        
        ListNode *nxt = curr->next;
        curr->next = prev;
        return reverseList(nxt, curr);
    }
};
