class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        int left = maxDepth(root->left);
        if(left == -1) return -1;
        int right = maxDepth(root->right);
        if(right == -1) return -1;
        if (abs(left - right) > 1) return -1;

        return 1 + max(left, right);
    }

    bool isBalanced(TreeNode* root) {
        if(root==nullptr) return true;
        return maxDepth(root) != -1;
    }
};
