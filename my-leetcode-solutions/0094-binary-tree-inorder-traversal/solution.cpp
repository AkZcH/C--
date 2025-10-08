class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {

        if (!root) return {};  

        vector<int> left = inorderTraversal(root->left);
        left.push_back(root->val);
        vector<int> right = inorderTraversal(root->right);

        left.insert(left.end(), right.begin(), right.end());

        return left;
    }
};
