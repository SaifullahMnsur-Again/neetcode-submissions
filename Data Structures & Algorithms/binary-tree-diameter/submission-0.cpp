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
    int ans = 0;
    int DFS(TreeNode* root, int lvl) {
        if(!root)
            return lvl - 1;
        int left = DFS(root->left, lvl + 1);
        int right = DFS(root->right, lvl + 1);
        // cerr << lvl << " : " << left << " + " << right << " - " << 2 * lvl << endl;
        ans = max(ans, left + right - 2 * lvl);
        // cerr << ans << endl;
        return max(left, right);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        DFS(root, 0);
        return ans;
    }
};
