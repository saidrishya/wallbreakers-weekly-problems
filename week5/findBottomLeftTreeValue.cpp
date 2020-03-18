class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        if(!root->left && !root->right) return root->val;
          int level=0,bot=0, maxi=-1;
        findBottom(root,level,bot,maxi);
        return bot;
    }
    void findBottom(TreeNode *root, int level, int &x , int &maxlevel){
        if(root==NULL)
           return;
        if(!root->left && !root->right && level > maxlevel) {
                x=root->val;
                maxlevel = level;
            }
          else{
                findBottom(root->left, level+1, x, maxlevel);
                findBottom(root->right, level+1, x, maxlevel);
            }
        }
        
    
};
