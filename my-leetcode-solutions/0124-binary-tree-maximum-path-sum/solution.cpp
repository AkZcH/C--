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
int maxPathSum(TreeNode* root) {
        int maxim = INT_MIN;
        int maxSum = sum(root, maxim);
        return maxim;
    }

    int sum(TreeNode* node, int& maxim){
        if(node==nullptr) return 0;
        int left = max(0, (sum(node->left, maxim)));
        int right = max(0, (sum(node->right, maxim)));
        maxim = max(maxim, left + right + node->val );
        return max(left, right) + node->val;
    }
};
