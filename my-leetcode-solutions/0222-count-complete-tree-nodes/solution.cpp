class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;

        int count=0;
        vector<int> tree;
        stack<TreeNode*> st;

        st.push(root);

        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();
            if(node->right) st.push(node->right);
            if(node->left) st.push(node->left);
            count++;
        }

        return count;
    }
};
