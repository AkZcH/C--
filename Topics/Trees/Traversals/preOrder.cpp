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

vector<int> preOrder(TreeNode* root){
    if(root==nullptr) return {};
    vector<int> ans;
    ans.push_back(root->val);   
    vector<int> left = preOrder(root->left);
    vector<int> right = preOrder(root->right);
    ans.insert(ans.end(), left.begin(), left.end());
    ans.insert(ans.end(), right.begin(), right.end());
    return ans;
}
 