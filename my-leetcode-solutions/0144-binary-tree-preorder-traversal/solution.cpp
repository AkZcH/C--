class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        // vector<int> tree;

        // if(root== NULL){
        //     return tree;
        // } 

        // else{
        //     tree.push_back(root->val);
        //     vector<int> left = preorderTraversal(root->left);
        //     vector<int> right = preorderTraversal(root->right);

        //     tree.insert(tree.end(), left.begin(), left.end());
        //     tree.insert(tree.end(), right.begin(), right.end());
        // }

        // return tree;

        if(root==NULL) return {};

        stack<TreeNode*> st;
        vector<int> tree;

        st.push(root);

        while(!st.empty()){
            TreeNode* node = st.top();
            tree.push_back(node->val);
            st.pop();
            if(node->right) st.push(node->right);
            if(node->left) st.push(node->left);
        }
        return tree;
    }
};
