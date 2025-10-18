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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==nullptr) return {};

        vector<vector<int>> tree;
        queue<TreeNode*> q;
        int flag=1;

        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int> level(size);

            for(int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();
                int index = (flag==1) ? i : (size-i-1);
                level[index] = node->val;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            flag = (flag==0) ? 1 : 0;
            tree.push_back(level);
        }

        return tree;
    }
};
