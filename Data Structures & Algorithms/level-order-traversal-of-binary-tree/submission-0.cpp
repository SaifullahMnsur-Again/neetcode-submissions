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

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
            return vector<vector<int>>();
        
        queue<TreeNode*> q;
        q.push(root);
        
        int span = 1, nextSpan = 0;

        vector<vector<int>> ans;
        ans.push_back(vector<int>());

        while(!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            ans.back().push_back(curr->val);
            span--;

            if(curr->left)
                q.push(curr->left), nextSpan++;
            if(curr->right)
                q.push(curr->right), nextSpan++;
            
            if(span == 0 and !q.empty()) {
                ans.push_back(vector<int>());
                span = nextSpan;
                nextSpan = 0;
            }
        }

        return ans;
    }
};
