class Solution {
public:

    void helper(TreeNode* root, vector<int>& tree){
        if(root == nullptr){
            return;
        }

        helper(root->left, tree);
        tree.push_back(root->val);
        helper(root->right, tree);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> tree;
        helper(root, tree);
        return tree;
    }
};
