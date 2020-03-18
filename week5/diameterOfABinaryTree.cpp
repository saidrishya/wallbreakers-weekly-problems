/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        
        int ld = diameterOfBinaryTree(root->left);
        int rd = diameterOfBinaryTree(root->right);
        
        return max(lh+rh, max(ld,rd));
    }
    
    int height(TreeNode *t){
        if(!t) return 0;
        int l = height(t->left);
        int r = height(t->right);
        
        if(l>r) return l+1;
        else return r+1;
    }
};
