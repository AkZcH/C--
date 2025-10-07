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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> tree;

        if(root== NULL){
            return tree;
        } 

        else{
            tree.push_back(root->val);
            vector<int> left = preorderTraversal(root->left);
            vector<int> right = preorderTraversal(root->right);

            tree.insert(tree.end(), left.begin(), left.end());
            tree.insert(tree.end(), right.begin(), right.end());
        }

        return tree;

    }
};
