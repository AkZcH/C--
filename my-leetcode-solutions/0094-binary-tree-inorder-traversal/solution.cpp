class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {

        // if (!root) return {};  
        // vector<int> tree;
        // vector<int> left = inorderTraversal(root->left);
        // tree.insert(tree.end(), left.begin(), left.end());
        // tree.push_back(root->val);
        // vector<int> right = inorderTraversal(root->right);
        // tree.insert(tree.end(), right.begin(), right.end());

        // return tree;

        // if(root==NULL) return {};

        vector<int> tree;
        stack<TreeNode*> st;
        TreeNode* node = root;

        while(!st.empty() ||(node != NULL)){
            while(node != NULL){
                st.push(node);
                node = node->left;
            }
            
            node = st.top();
            st.pop();
            tree.push_back(node->val);

            node = node -> right;
        }

        return tree;
    }
};

