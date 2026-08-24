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
    bool ans = true;
    int DFS(TreeNode* root, int lvl) {
        if(!root)
            return lvl - 1;
        int left = DFS(root->left, lvl + 1);
        int right = DFS(root->right, lvl + 1);
        if(abs(left - right) > 1)
            ans = false;
        return max(left, right);
    }
public:
    bool isBalanced(TreeNode* root) {
        DFS(root, 0);
        return ans;
    }
};
