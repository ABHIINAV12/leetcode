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
    vector<int> vt;
    void trav(TreeNode * root){
        if(root==nullptr)return ;
        vt.push_back(root->val);
        trav(root->left);
        trav(root->right);
    }
    void trav1(TreeNode * root,int curr){
        if(curr==(int)vt.size()) {
            root=nullptr;
            return ;
        }
        root->val=vt[curr++]; root->left=nullptr; root->right=nullptr;
        if(curr==(int)vt.size()) return ;
        root->right= new TreeNode(0);
        trav1(root->right,curr);
    }
    void flatten(TreeNode* root) {
        TreeNode *head=nullptr, *curr=nullptr;
        trav(root); trav1(root,0);
    }
};
