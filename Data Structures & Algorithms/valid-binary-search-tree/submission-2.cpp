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
    bool isValidBST(TreeNode* root, int l = INT_MIN, int r = INT_MAX) {
        if(!root)
            return true;
        if(root->val <= l or root->val >= r)
            return false;
        return isValidBST(root->left, l, root->val) and isValidBST(root->right, root->val, r);
    }
};
