class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        queue<TreeNode*> q;
        vector<vector<int>> tree;
        q.push(root);

        while(!q.empty()){
           int size = q.size();
           vector<int> level;

           for(int i=0; i<size; i++){
            TreeNode* current = q.front();
            q.pop();
            if(current->left){
                q.push(current->left);
            }
            if(current->right){
                q.push(current->right);
            }
            level.push_back(current->val);
           }
           tree.push_back(level);
        }

        return tree;

    }
};
