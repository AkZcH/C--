class Solution {
public:

    // int add(TreeNode* node){
    //     if(!node) return 0;
    //     if(!node->left && !node->right) return node->val;
    //     return add(node->left) + add(node->right);
    // }
    // bool checkTree(TreeNode* root) {
    //     if(root==nullptr) return true;

    //     return root->val == add(root->left) + add(root->right);
        
    // }

    bool checkTree(TreeNode* root){
        if(!root) return true;

        return root->val == root->left->val + root->right->val;
    }
};
