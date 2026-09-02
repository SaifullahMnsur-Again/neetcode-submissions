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
    ListNode *mergeList(ListNode* a, ListNode *b) {
        if(!a)
            return b;
        if(!b)
            return a;
        
        ListNode dummy(0);
        ListNode *curr = &dummy;

        while(a and b) {
            if(a->val <= b->val) {
                curr->next = a;
                a = a->next;
            } else {
                curr->next = b;
                b = b->next;
            }
            curr = curr->next;
        }

        if(a) {
            curr->next = a;
        }

        if(b) {
            curr->next = b;
        }

        return dummy.next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
            return nullptr;

        vector<ListNode*> next;
        while(lists.size() > 1) {
            for(int i = 0; i < lists.size(); i += 2) {
                if(i < lists.size() - 1)
                    next.push_back(mergeList(lists[i], lists[i + 1]));
                else
                    next.push_back(lists[i]);
            }
            lists = next;
            next = vector<ListNode*>();
        }

        return lists.back();
    }
};
