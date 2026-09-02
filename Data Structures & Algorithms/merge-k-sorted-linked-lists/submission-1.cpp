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
    struct Comp {
    bool operator()(const ListNode* const& a, const ListNode* const& b) {
        return a->val > b->val;
    }
};
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy(0);
        ListNode *root = &dummy;

        priority_queue<ListNode*, vector<ListNode*>, Comp> pq;

        for (ListNode* list : lists) {
            if (list != nullptr) {
                pq.push(list);
            }
        }

        while(!pq.empty()) {
            ListNode *curr = pq.top();
            pq.pop();
            root->next = curr;
            root = root->next;
            
            curr = curr->next;
            if(curr)
                pq.push(curr);
        }

        return dummy.next;
    }
};
