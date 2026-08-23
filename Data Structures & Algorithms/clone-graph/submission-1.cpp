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

        // Node *curr = new Node(node->val);

        map<Node*, Node*> mp;
        queue<Node*> q1, q2;
        q1.push(node);
        Node *root = new Node(node->val);
        q2.push(root);

        while(!q1.empty()) {
            Node *curr1 = q1.front();
            Node *curr2 = q2.front();
            
            q1.pop();
            q2.pop();
            
            mp[curr1] = curr2;

            for(int i = 0; i < curr1->neighbors.size(); i++) {
                Node *nbr1 = curr1->neighbors[i];
                // Node *nbr2 = curr2->neighbors[i];

                if(mp.find(nbr1) == mp.end()) {
                    q1.push(nbr1);
                    Node *nbr2 = new Node(nbr1->val);
                    mp[nbr1] = nbr2;
                    q2.push(nbr2);
                }
                curr2->neighbors.push_back(mp[nbr1]);
            }
        }

        // Node* curr = new Node(node->val);
        // mp[node] = true;
        // for(Node* nbr : node->neighbors)
        //     if(!mp[nbr])
        //         curr->neighbors.push_back(cloneGraph(nbr, curr));
        // if(parent)
        //     curr->neighbors.push_back(parent);
        
        // cout << "Parent: " << curr->val << ": ";
        // for(auto i : curr->neighbors)
        //     cout << i->val << " ";
        // cout << endl;


        return root;
    }
};
