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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int m = 0;
        ListNode* curr = head;
        while(curr) {
            m++;
            curr = curr->next;
        }
        if(m == 1)
            return nullptr;
        
        m -= n;
        m++;

        ListNode* prev = nullptr;
        curr = head;
        while(--m) {
            prev = curr;
            curr = curr->next;
        }

        if(prev)
            prev->next = curr->next;
        else
            head = curr->next;

        return head;
    }
};
