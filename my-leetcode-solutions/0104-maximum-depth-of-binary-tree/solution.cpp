class Solution {
public:
    int maxDepth(TreeNode* root) {
        // if(root == NULL) return 0;

        // int depth=0;

        // int lh = maxDepth(root->left);
        // int lr = maxDepth(root->right);
        // depth = 1 + max(lh, lr);
        
        // return depth;

        if(root==NULL) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int depth=0;

        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                q.push(node->left);
            } 
            if(node->right){
                q.push(node->right);
            } 
        }
                    depth++;

        }


        return depth;
    }
};
