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
    int maxx = INT_MIN;
    int dfs(TreeNode* root) {
        if(!root)
            return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);

        int sum = root->val + max({0, left, right});

        maxx = max({maxx, sum, root->val + max(0, left) + max(0, right)});

        if(sum < 0)
            return 0;
        
        return sum;
    }

public:
    int maxPathSum(TreeNode* root) {
        dfs(root);

        return maxx;
    }
};
