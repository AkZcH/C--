class Solution {
public:

    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int start, int end, int& postIndex){
        if(start > end) return nullptr;

        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);

        int index = find(inorder.begin() + start, inorder.begin() + end + 1, rootVal) - inorder.begin();

        root->right = build(inorder, postorder, index+1, end, postIndex);
        root->left = build(inorder, postorder, start, index-1, postIndex);


        return root;

    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postIndex= inorder.size() - 1;
        return build(inorder, postorder, 0, inorder.size()-1, postIndex);
    }
};
