/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node)
            return nullptr;


        map<Node*, Node*> mp;
        mp[node] = new Node(node->val);
        
        queue<Node*> q;
        q.push(node);

        while(!q.empty()) {
            Node *old = q.front();
            Node *curr = mp[old];
            q.pop();

            for(Node* nbr: old->neighbors) {
                if(mp.find(nbr) == mp.end()) {
                    mp[nbr] = new Node(nbr->val);
                    q.push(nbr);
                }
                curr->neighbors.push_back(mp[nbr]);
            }
        }

        return mp[node];
    }
};
