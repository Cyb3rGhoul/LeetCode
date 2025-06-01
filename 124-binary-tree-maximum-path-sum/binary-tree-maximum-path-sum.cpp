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
    int maxSum;

    int solve(TreeNode* root){
        if(root==NULL) return 0;

        int l = solve(root->left);
        int r = solve(root->right);

        int niche_sum_milgaya = l + r + root->val;
        int only_one_good_sum = max(l,r) + root->val;
        int only_root_good = root->val;

        maxSum = max({maxSum, niche_sum_milgaya, only_one_good_sum, only_root_good});

        return max(only_root_good,only_one_good_sum);
    }
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;

        solve(root);

        return maxSum;

    }
};