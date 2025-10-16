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
        if(root == NULL) return {};

        vector<int> tree;
        // stack<TreeNode*> st;

        // st.push(root);
        // TreeNode* node = root;

        // while(!st.empty()){
        //     node = st.top();
        //     st.pop();
        //     tree.push_back(node->val);
            
        //     if(node->right) st.push(node->right);
        //     if(node->left) st.push(node->left);
        // }

        tree.push_back(root->val);
        vector<int> left = preorderTraversal(root->left);
        vector<int> right = preorderTraversal(root->right);

        tree.insert(tree.end(), left.begin(), left.end());
        tree.insert(tree.end(), right.begin(), right.end());

        return tree;
    }
};
