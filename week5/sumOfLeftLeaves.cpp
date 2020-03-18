class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        util(root,sum);
return sum;
    }
    
    void util(TreeNode *root, int &sum){
        if(!root) return;
        if(root->left){
            TreeNode *t=root->left;
        if(!t->left && !t->right) sum+=t->val;
        }
        util(root->left,sum);
        util(root->right,sum);
    }
};
