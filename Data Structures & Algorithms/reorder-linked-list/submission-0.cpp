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
    void reorderList(ListNode* head) {
        ListNode *slow, *fast;
        slow = fast = head;
        while(fast->next != nullptr and fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        

        ListNode *newHead = slow->next;
        slow->next = nullptr;
        ListNode *curr = newHead;
        ListNode *prev = nullptr;

        while(curr) {
            ListNode *tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        newHead = prev;

        while(head and newHead  ) {
            ListNode *tmp1 = head->next;
            ListNode *tmp2 = newHead->next;

            head->next = newHead;
            if(tmp1)
                newHead->next = tmp1;
            head = tmp1;
            newHead = tmp2;
        }

    }
};
