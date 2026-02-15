//144. Binary Tree Preorder Traversal
//Given the root of a binary tree, return the preorder traversal of its nodes' values.


#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

    vector<int> preorderTraversal(TreeNode* root) {
        if(root==nullptr) return {};
        vector<int> tree;
        tree.push_back(root->val);
        vector<int> left = preorderTraversal(root->left);
        vector<int> right = preorderTraversal(root->right);

        tree.insert(tree.end(),left.begin(), left.end());
        tree.insert(tree.end(),right.begin(), right.end());

        return tree;
    }