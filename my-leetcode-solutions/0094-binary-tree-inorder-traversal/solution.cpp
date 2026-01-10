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
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == nullptr) return {};
        vector<int> tree;
        vector<int> left = inorderTraversal(root->left);
        tree.insert(tree.end(), left.begin(), left.end());
        tree.push_back(root->val);
        vector<int> right = inorderTraversal(root->right);
        tree.insert(tree.end(), right.begin(), right.end());
        return tree;
    }
};
