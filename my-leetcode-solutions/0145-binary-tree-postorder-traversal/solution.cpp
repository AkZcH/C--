class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==NULL) return {};

        vector<int> tree;

        vector<int> left = postorderTraversal(root->left);
        vector<int> right = postorderTraversal(root->right);

        tree.insert(tree.end(), left.begin(),left.end());
        tree.insert(tree.end(), right.begin(),right.end());
        tree.push_back(root->val);

        return tree;
    }
};
