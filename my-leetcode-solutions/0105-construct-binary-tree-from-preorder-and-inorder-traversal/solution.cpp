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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& preIndex, int start, int end) {
        if(start>end) return nullptr;

        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);

        auto it = find(inorder.begin() + start, inorder.end() + end + 1, rootVal);

        int index = it - inorder.begin();

        root->left = build(preorder, inorder, preIndex, start, index-1);
        root->right = build(preorder, inorder, preIndex, index+1, end);

        return root;

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
        int preIndex=0;
        return build(preorder, inorder, preIndex, 0, inorder.size()-1);
    }
};
