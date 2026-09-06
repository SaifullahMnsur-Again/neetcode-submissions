/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
    pair<int, int> nextVal(string &data, int i) {
        string nstr = "";
        int skip = 0;
        while(i + skip < data.size() and data[i + skip] != '#') {
            nstr += data[i + skip];
            skip++;
        }
        int n = stoi(nstr);
        skip++;
        

        return {n, skip + n};
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        string ans;
        while(!q.empty()) {
            TreeNode *curr = q.front();
            q.pop();

            if(curr != nullptr) {
                string str = to_string(curr->val);
                ans += (to_string(str.size()) + "#" + str);
                q.push(curr->left);
                q.push(curr->right);
            } else {
                ans += "0#";
            }
        }

        // cerr << ans << endl;
        // cerr << "serialize pas!s\n";
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        auto nxt = nextVal(data, 0);
        string rt = data.substr(nxt.second - nxt.first, nxt.first);
        int i = nxt.second;
        TreeNode *root;
        if(rt.empty())
            return nullptr;
        else
            root = new TreeNode(stoi(rt));
        
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode *curr = q.front();
            q.pop();

            if(curr != nullptr) {
                auto nxt = nextVal(data, i);
                string left = data.substr(i + nxt.second - nxt.first, nxt.first);
                i += nxt.second;

                if(left.empty())
                    curr->left = nullptr;
                else {
                    curr->left = new TreeNode(stoi(left));
                }
                
                nxt = nextVal(data, i);
                string right = data.substr(i + nxt.second - nxt.first, nxt.first);
                i += nxt.second;
                
                if(right.empty())
                    curr->right = nullptr;
                else {
                    curr->right = new TreeNode(stoi(right));
                }

                // cerr << "Left: " << left << endl;
                // cerr << "Right: " << right << endl;

                q.push(curr->left);
                q.push(curr->right);
            }
        }
        
        return root;
    }
};
