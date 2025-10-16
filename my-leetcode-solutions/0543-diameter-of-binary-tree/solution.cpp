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
    int diameterOfBinaryTree(TreeNode* root) {
        int dia=0;
        maxDepth(root, dia);
        return dia;
    }

    int maxDepth(TreeNode* node, int& dia){
        if(node==nullptr) return 0;

        int left = maxDepth(node->left, dia);
        int right = maxDepth(node->right, dia);

        dia = max(dia, left + right);

        return 1 + max(left,right);
    }
};
